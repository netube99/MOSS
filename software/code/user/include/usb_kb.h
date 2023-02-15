#ifndef _USB_KB_H_
#define _USB_KB_H_

#include "at32f415.h"

void Usb_Init(void);
void usb_gpio_config(void);
void Clean_Key_Buffer();
void Usb_Send_Hotkey(uint8_t control_key, uint8_t standard_key);

#endif
