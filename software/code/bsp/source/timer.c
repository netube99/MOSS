#include "timer.h"

uint8_t system_timer_flag = 0;

//系统定时器10ms周期
void System_Timer_Init(void)
{
    crm_periph_clock_enable(CRM_TMR1_PERIPH_CLOCK, TRUE);
    tmr_base_init(TMR1, 100 - 1, 14400 - 1);
    tmr_cnt_dir_set(TMR1, TMR_COUNT_UP);
    tmr_interrupt_enable(TMR1, TMR_OVF_INT, TRUE);
    nvic_irq_enable(TMR1_OVF_TMR10_IRQn, 0, 0);
    tmr_counter_enable(TMR1, TRUE);
}

void System_Timer_Flag_Set(uint8_t flag)
{
    system_timer_flag = flag ;
}

uint8_t System_Timer_Flag_Get(void)
{
    return system_timer_flag ;
}

void Pwm_Timer_Init(void)
{
    //PWM通道IO初始化
    crm_periph_clock_enable(CRM_IOMUX_PERIPH_CLOCK, TRUE);
    crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);
    gpio_init_type gpio_init_struct;
    gpio_default_para_init(&gpio_init_struct);
    gpio_init_struct.gpio_out_type = GPIO_OUTPUT_OPEN_DRAIN;
    gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
    gpio_init_struct.gpio_mode = GPIO_MODE_OUTPUT;
    gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
    gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
    gpio_init_struct.gpio_pins = GPIO_LED_MOSS_PIN;
    gpio_init(GPIO_LED_MOSS_PORT, &gpio_init_struct);

    //TIMER 3
    crm_periph_clock_enable(CRM_TMR3_PERIPH_CLOCK, TRUE);
    tmr_base_init(PWM_LED_MOSS_TIMER, 100-1, 144-1);
    tmr_cnt_dir_set(PWM_LED_MOSS_TIMER, TMR_COUNT_UP);
    tmr_output_config_type tmr_output_struct;
    tmr_output_default_para_init(&tmr_output_struct);
    tmr_output_struct.oc_mode = TMR_OUTPUT_CONTROL_PWM_MODE_B;  //输出模式B
    tmr_output_struct.oc_output_state = TRUE;                   //使能通道输出
    tmr_output_struct.oc_polarity = TMR_OUTPUT_ACTIVE_HIGH;      //输出极性低
    tmr_output_struct.oc_idle_state = TRUE;                     //空闲模式状态为高电平
    tmr_output_channel_config(PWM_LED_MOSS_TIMER, PWM_LED_MOSS_CHANNEL, &tmr_output_struct);
    tmr_channel_value_set(PWM_LED_MOSS_TIMER, PWM_LED_MOSS_CHANNEL, 0);
    tmr_output_enable(PWM_LED_MOSS_TIMER, TRUE);
    tmr_counter_enable(PWM_LED_MOSS_TIMER, TRUE);
}