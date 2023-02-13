#include "gpio.h"

uint8_t Gpio_Exit_Flag[16];

void Gpio_Init(void)
{
    //初始化结构体与外设时钟管理
    gpio_init_type gpio_init_struct;
    crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);
    crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);

    //电平状态初始化
    _GPIO_LED_STD_1_H();
    _GPIO_LED_STD_2_H();
    _GPIO_LED_STD_3_H();
    _GPIO_LED_DFH_1_H();
    _GPIO_LED_DFH_2_H();
    _GPIO_LED_DFH_3_H();
    _GPIO_LED_DFH_4_H();

    gpio_default_para_init(&gpio_init_struct);
    gpio_init_struct.gpio_out_type = GPIO_OUTPUT_OPEN_DRAIN;
    gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
    gpio_init_struct.gpio_mode = GPIO_MODE_OUTPUT;
    gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;

    gpio_init_struct.gpio_pins = GPIO_LED_STD_1_PIN;
    gpio_init(GPIO_LED_STD_1_PORT, &gpio_init_struct);
    gpio_init_struct.gpio_pins = GPIO_LED_STD_2_PIN;
    gpio_init(GPIO_LED_STD_2_PORT, &gpio_init_struct);
    gpio_init_struct.gpio_pins = GPIO_LED_STD_3_PIN;
    gpio_init(GPIO_LED_STD_3_PORT, &gpio_init_struct);
    gpio_init_struct.gpio_pins = GPIO_LED_DFH_1_PIN;
    gpio_init(GPIO_LED_DFH_1_PORT, &gpio_init_struct);
    gpio_init_struct.gpio_pins = GPIO_LED_DFH_2_PIN;
    gpio_init(GPIO_LED_DFH_2_PORT, &gpio_init_struct);
    gpio_init_struct.gpio_pins = GPIO_LED_DFH_3_PIN;
    gpio_init(GPIO_LED_DFH_3_PORT, &gpio_init_struct);
    gpio_init_struct.gpio_pins = GPIO_LED_DFH_4_PIN;
    gpio_init(GPIO_LED_DFH_4_PORT, &gpio_init_struct);
}

void Gpio_Exit_Init(void)
{
    for(uint8_t i=0; i<16; i++)
        Gpio_Exit_Flag[i] = 0 ;

    exint_init_type exint_init_struct;
    crm_periph_clock_enable(CRM_IOMUX_PERIPH_CLOCK, TRUE);
    crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);
    gpio_exint_line_config(GPIO_EXIT_SOURCE_PORT, GPIO_EXIT_SOURCE_PIN);

    exint_default_para_init(&exint_init_struct);
    exint_init_struct.line_enable = TRUE;
    exint_init_struct.line_mode = EXINT_LINE_INTERRUPUT;
    exint_init_struct.line_select = EXINT_LINE_5;
    exint_init_struct.line_polarity = EXINT_TRIGGER_FALLING_EDGE;
    exint_init(&exint_init_struct);
    nvic_irq_enable(EXINT0_IRQn, 1, 0);
}

uint8_t Gpio_Exit_Flag_Get(uint8_t exit_line)
{
    return Gpio_Exit_Flag[exit_line];
}

void Gpio_Exit_Flag_Set(uint8_t exit_line, uint8_t state)
{
    Gpio_Exit_Flag[exit_line] = state ;
}