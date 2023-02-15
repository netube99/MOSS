#ifndef _LED_H_
#define _LED_H_

#include "at32f415.h"

void Led_Fsm(uint16_t ms);
void Led_Dfh_Set(uint8_t num);
void Led_Dfh_Play_Step(void);
void Led_Moss_Set(int8_t dir);
void Led_Flash(void);

#endif