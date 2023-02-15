/**
  **************************************************************************
  * @file     usb_conf.h
  * @brief    usb config header file
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */

/* define to prevent recursive inclusion -------------------------------------*/
#ifndef __USB_CONF_H
#define __USB_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

#include "at32f415_usb.h"
#include "at32f415.h"
#include "stdio.h"


/** @addtogroup AT32F415_periph_examples
  * @{
  */

/** @addtogroup 415_USB_device_keyboard
  * @{
  */


/**
  * @brief enable usb device mode
  */
#define USE_OTG_DEVICE_MODE

/**
  * @brief enable usb host mode
  */
/* #define USE_OTG_HOST_MODE */

#define USB_ID                           0
#define OTG_CLOCK                        CRM_OTGFS1_PERIPH_CLOCK
#define OTG_IRQ                          OTGFS1_IRQn
#define OTG_IRQ_HANDLER                  OTGFS1_IRQHandler
#define OTG_WKUP_IRQ                     OTGFS1_WKUP_IRQn
#define OTG_WKUP_HANDLER                 OTGFS1_WKUP_IRQHandler
#define OTG_WKUP_EXINT_LINE              EXINT_LINE_18

#define OTG_PIN_GPIO                     GPIOA
#define OTG_PIN_GPIO_CLOCK               CRM_GPIOA_PERIPH_CLOCK
#define OTG_PIN_VBUS                     GPIO_PINS_9
#define OTG_PIN_ID                       GPIO_PINS_10

#define OTG_PIN_SOF_GPIO                 GPIOA
#define OTG_PIN_SOF_GPIO_CLOCK           CRM_GPIOA_PERIPH_CLOCK
#define OTG_PIN_SOF                      GPIO_PINS_8

/**
  * @brief usb device mode config
  */
#ifdef USE_OTG_DEVICE_MODE
/**
  * @brief usb device mode fifo
  */
/* otg1 device fifo */
#define USBD_RX_SIZE                     128
#define USBD_EP0_TX_SIZE                 24
#define USBD_EP1_TX_SIZE                 20
#define USBD_EP2_TX_SIZE                 20
#define USBD_EP3_TX_SIZE                 20

/**
  * @brief usb endpoint max num define
  */
#ifndef USB_EPT_MAX_NUM
#define USB_EPT_MAX_NUM                   4
#endif
#endif

/**
  * @brief usb host mode config
  */
#ifdef USE_OTG_HOST_MODE
#ifndef USB_HOST_CHANNEL_NUM
#define USB_HOST_CHANNEL_NUM             8
#endif

/**
  * @brief usb host mode fifo
  */
/* otg1 host fifo */
#define USBH_RX_FIFO_SIZE                128
#define USBH_NP_TX_FIFO_SIZE             96
#define USBH_P_TX_FIFO_SIZE              96
#endif

/**
  * @brief usb sof output enable
  */
/* #define USB_SOF_OUTPUT_ENABLE */

/**
  * @brief ignore vbus detection, only available in at32f415xx revision C.
  *        at32f415xx revision B: (not support)
  *        the vbus detection pin (pa9) can not be used for other functionality.
  *        vbus pin must kept at VBUS or VDD.
  *
  *        at32f415xx revision C: (support)
  *        ignore vbus detection, the internal vbus is always valid.
  *        the vbus pin (pa9) can be used for other functionality.
  */
/* #define USB_VBUS_IGNORE */

/**
  * @brief usb low power wakeup handler enable
  */
#define USB_LOW_POWER_WAKUP

void usb_delay_ms(uint32_t ms);
void usb_delay_us(uint32_t us);

/**
  * @}
  */

/**
  * @}
  */
#ifdef __cplusplus
}
#endif

#endif

