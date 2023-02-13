#ifndef _LED_H_
#define _LED_H_

#include "at32f415.h"

//东方红简谱编码
uint8_t dfh[32] =
{
    5, 5+6, 2,
    1, 1+6, 2,
    5, 5, 6+1, 6, 5,
    1, 1+6, 2,
    5, 2, 1, 7+6, 5, 5, 2,
    3, 2, 1, 1+6,
    2, 3, 2, 1, 2+1, 7+6, 5
};

void Led_Fsm(uint16_t ms);
void Led_Dfh_Set(uint8_t num);
void Led_Dfh_Play_Step(void);
void Led_Turn_Off_All(void);
void Led_Moss_Set(int8_t dir);
void Led_Flash(void);

#endif