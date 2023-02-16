#include "usb_kb.h"
#include "delay.h"
#include "at32f415_clock.h"
#include "usb_conf.h"
#include "usb_core.h"
#include "usbd_int.h"
#include "keyboard_class.h"
#include "keyboard_desc.h"

otg_core_type otg_core_struct;
uint8_t key_buffer[8];

void Usb_Init(void)
{
    Clean_Key_Buffer();
    crm_periph_clock_enable(OTG_CLOCK, TRUE);
    usb_gpio_config();
    nvic_irq_enable(OTG_IRQ, 0, 0);
    usbd_init(&otg_core_struct,
            USB_FULL_SPEED_CORE_ID,
            USB_ID,
            &keyboard_class_handler,
            &keyboard_desc_handler);
}

void usb_gpio_config(void)
{
    gpio_init_type gpio_init_struct;
    crm_periph_clock_enable(OTG_PIN_GPIO_CLOCK, TRUE);
    gpio_default_para_init(&gpio_init_struct);
    gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
    gpio_init_struct.gpio_out_type  = GPIO_OUTPUT_PUSH_PULL;
    gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
    gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
#ifdef USB_SOF_OUTPUT_ENABLE
    crm_periph_clock_enable(OTG_PIN_SOF_GPIO_CLOCK, TRUE);
    gpio_init_struct.gpio_pins = OTG_PIN_SOF;
    gpio_init(OTG_PIN_SOF_GPIO, &gpio_init_struct);
#endif
  /* otgfs use vbus pin */
#ifndef USB_VBUS_IGNORE
    gpio_init_struct.gpio_pins = OTG_PIN_VBUS;
    gpio_init_struct.gpio_pull = GPIO_PULL_DOWN;
    gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
    gpio_init(OTG_PIN_GPIO, &gpio_init_struct);
#endif
}

void Clean_Key_Buffer(void)
{
    for(uint8_t i=0; i<8; i++)
        key_buffer[i] = 0x00;
}

void usb_delay_ms(uint32_t ms)
{
    delay_ms(ms);
}

void OTGFS1_IRQHandler(void)
{
    usbd_irq_handler(&otg_core_struct);
}

//USB发送一个快捷键组合
void Usb_Send_Hotkey(uint8_t control_key, uint8_t standard_key)
{
    void *udev = &otg_core_struct.dev ;
    usbd_core_type *pudev = (usbd_core_type *)udev;
    keyboard_type *pkeyboard = (keyboard_type *)pudev->class_handler->pdata;
    key_buffer[0] = control_key;
    key_buffer[2] = standard_key;
    while(1)
    {
        if(pkeyboard->g_u8tx_completed == 1)
        {
            pkeyboard->g_u8tx_completed = 0;
            usb_keyboard_class_send_report(udev, key_buffer, 8);
            break;
        }
    }
    Clean_Key_Buffer();
    while(1)
    {
        if(pkeyboard->g_u8tx_completed == 1)
        {
            pkeyboard->g_u8tx_completed = 0;
            usb_keyboard_class_send_report(udev, key_buffer, 8);
            break;
        }
    }
}