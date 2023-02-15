#ifndef _MAIN_H_
#define _MAIN_H_

//system
#include "at32f415.h"
#include "at32f415_clock.h"
#include "delay.h"

//bsp
#include "gpio.h"
#include "timer.h"
#include "i2c_sw.h"

//hardware
#include "led.h"
#include "usb_kb.h"
#include "PAJ7620U2.h"

//application
#include "SEGGER_RTT.h"

void System_Init(void);
void gesture(void);

#endif