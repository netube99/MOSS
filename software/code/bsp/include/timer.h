#ifndef _SYSTEM_TIMER_H_
#define _SYSTEM_TIMER_H_

#include <stdint.h>

void System_Timer_Init(void);
void System_Timer_Flag_Set(uint8_t flag);
uint8_t System_Timer_Flag_Get();

#endif