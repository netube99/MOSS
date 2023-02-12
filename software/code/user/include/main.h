#ifndef _MAIN_H_
#define _MAIN_H_

//system
#include "at32f415.h"
#include "at32f415_clock.h"

//bsp
#include "gpio.h"
#include "timer.h"
#include "i2c_sw.h"

//hardware
#include "led.h"

//application
#include "SEGGER_RTT.h"

void System_Init(void);

#endif