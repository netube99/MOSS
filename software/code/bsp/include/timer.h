#ifndef _SYSTEM_TIMER_H_
#define _SYSTEM_TIMER_H_

#include <stdint.h>

//MOSS红眼
#define GPIO_LED_MOSS_PIN           GPIO_PINS_0
#define GPIO_LED_MOSS_PORT          GPIOB
#define PWM_LED_MOSS_CHANNEL        TMR_SELECT_CHANNEL_3
#define PWM_LED_MOSS_TIMER          TMR3
#define _SET_PWM_LED_MOSS(VAL)      tmr_channel_value_set(PWM_LED_MOSS_TIMER, PWM_LED_MOSS_CHANNEL, VAL)

void System_Timer_Init(void);
void System_Timer_Flag_Set(uint8_t flag);
uint8_t System_Timer_Flag_Get(void);
void Pwm_Timer_Init(void);

#endif