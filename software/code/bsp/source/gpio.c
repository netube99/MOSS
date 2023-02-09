#include "gpio.h"
#include "at32f415.h"

void Gpio_Init(void)
{
    //初始化结构体与外设时钟管理
    gpio_init_type gpio_init_struct;
    crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);
    crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);
    crm_periph_clock_enable(CRM_GPIOC_PERIPH_CLOCK, TRUE);

    //电平状态初始化
    _GPIO_OLED_RES_H();
    _GPIO_OLED_DC_H();
    _GPIO_PWR_KEEP_H(); //开机键按下瞬间保持电源使能*
    _GPIO_LED_L();
    _GPIO_BUCK_EN_L();

    //oled屏幕gpio引脚初始化
    //oled_res
    gpio_default_para_init(&gpio_init_struct);
    gpio_init_struct.gpio_pins = GPIO_OLED_RES_PIN;
    gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
    gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
    gpio_init_struct.gpio_mode = GPIO_MODE_OUTPUT;
    gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
    gpio_init(GPIO_OLED_RES_PORT, &gpio_init_struct);
    //oled_dc
    gpio_init_struct.gpio_pins = GPIO_OLED_DC_PIN;
    gpio_init(GPIO_OLED_DC_PORT, &gpio_init_struct);

    //电源保持
    gpio_init_struct.gpio_pins = GPIO_PWR_KEEP_PIN;
    gpio_init(GPIO_PWR_KEEP_PORT, &gpio_init_struct);

    //led使能
    gpio_init_struct.gpio_pins = GPIO_LED_PIN;
    gpio_init(GPIO_LED_PORT, &gpio_init_struct);

    //buck使能
    gpio_init_struct.gpio_pins = GPIO_BUCK_EN_PIN;
    gpio_init(GPIO_BUCK_EN_PORT, &gpio_init_struct);

    //相纸检测
    gpio_init_struct.gpio_pins = GPIO_IF_BAT_PIN;
    gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
    gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
    gpio_init(GPIO_IF_BAT_PORT, &gpio_init_struct);

    //充电状态
    gpio_init_struct.gpio_pins = GPIO_CHARGE_STA_PIN;
    gpio_init_struct.gpio_pull = GPIO_PULL_UP;
    gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
    gpio_init(GPIO_CHARGE_STA_PORT, &gpio_init_struct);

    //操作键
    gpio_init_struct.gpio_pins = GPIO_USER_KEY_PIN;
    gpio_init_struct.gpio_pull = GPIO_PULL_UP;
    gpio_init_struct.gpio_mode = GPIO_MODE_INPUT;
    gpio_init(GPIO_USER_KEY_PORT, &gpio_init_struct);
}