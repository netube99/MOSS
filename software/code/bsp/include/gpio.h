#ifndef _GPIO_H_
#define _GPIO_H_

//oled屏幕
//oled_res
#define GPIO_OLED_RES_PIN           GPIO_PINS_2
#define GPIO_OLED_RES_PORT          GPIOB
#define _GPIO_OLED_RES_H()          gpio_bits_set(GPIO_OLED_RES_PORT, GPIO_OLED_RES_PIN)
#define _GPIO_OLED_RES_L()          gpio_bits_reset(GPIO_OLED_RES_PORT, GPIO_OLED_RES_PIN)
//oled_dc
#define GPIO_OLED_DC_PIN            GPIO_PINS_0
#define GPIO_OLED_DC_PORT           GPIOB
#define _GPIO_OLED_DC_H()           gpio_bits_set(GPIO_OLED_DC_PORT, GPIO_OLED_DC_PIN)
#define _GPIO_OLED_DC_L()           gpio_bits_reset(GPIO_OLED_DC_PORT, GPIO_OLED_DC_PIN)

//电源保持
#define GPIO_PWR_KEEP_PIN           GPIO_PINS_9
#define GPIO_PWR_KEEP_PORT          GPIOA
#define _GPIO_PWR_KEEP_H()          gpio_bits_set(GPIO_PWR_KEEP_PORT, GPIO_PWR_KEEP_PIN)
#define _GPIO_PWR_KEEP_L()          gpio_bits_reset(GPIO_PWR_KEEP_PORT, GPIO_PWR_KEEP_PIN)

//led使能
#define GPIO_LED_PIN                GPIO_PINS_6
#define GPIO_LED_PORT               GPIOB
#define _GPIO_LED_H()               gpio_bits_set(GPIO_LED_PORT, GPIO_LED_PIN)
#define _GPIO_LED_L()               gpio_bits_reset(GPIO_LED_PORT, GPIO_LED_PIN)

//buck使能
#define GPIO_BUCK_EN_PIN            GPIO_PINS_5
#define GPIO_BUCK_EN_PORT           GPIOB
#define _GPIO_BUCK_EN_H()           gpio_bits_set(GPIO_BUCK_EN_PORT, GPIO_BUCK_EN_PIN)
#define _GPIO_BUCK_EN_L()           gpio_bits_reset(GPIO_BUCK_EN_PORT, GPIO_BUCK_EN_PIN)

//相纸检测
#define GPIO_IF_BAT_PIN             GPIO_PINS_7
#define GPIO_IF_BAT_PORT            GPIOB
#define _GPIO_IF_BAT_READ()         gpio_input_data_bit_read(GPIO_IF_BAT_PORT,GPIO_IF_BAT_PIN)

//充电状态
#define GPIO_CHARGE_STA_PIN         GPIO_PINS_3
#define GPIO_CHARGE_STA_PORT        GPIOA
#define _GPIO_CHARGE_STA_READ()     gpio_input_data_bit_read(GPIO_CHARGE_STA_PORT,GPIO_CHARGE_STA_PIN)

//操作按键
#define GPIO_USER_KEY_PIN           GPIO_PINS_4
#define GPIO_USER_KEY_PORT          GPIOA
#define _GPIO_USER_KEY_READ()       gpio_input_data_bit_read(GPIO_USER_KEY_PORT,GPIO_USER_KEY_PIN)

void Gpio_Init(void);

#endif