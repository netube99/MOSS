#include "timer.h"
#include "at32f415.h"

uint8_t system_timer_flag = 0;

//系统定时器5ms周期
void System_Timer_Init(void)
{
    crm_clocks_freq_type crm_clocks_freq_struct = {0};
    crm_clocks_freq_get(&crm_clocks_freq_struct);
    crm_periph_clock_enable(CRM_TMR1_PERIPH_CLOCK, TRUE);
    tmr_base_init(TMR1, 50 - 1, 14400 - 1);
    tmr_cnt_dir_set(TMR1, TMR_COUNT_UP);
    tmr_interrupt_enable(TMR1, TMR_OVF_INT, TRUE);
    nvic_irq_enable(TMR1_OVF_TMR10_IRQn, 0, 0);
    tmr_counter_enable(TMR1, TRUE);
}

void System_Timer_Flag_Set(uint8_t flag)
{
    system_timer_flag = flag ;
}

uint8_t System_Timer_Flag_Get()
{
    return system_timer_flag ;
}