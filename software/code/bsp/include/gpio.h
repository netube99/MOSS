#ifndef _GPIO_H_
#define _GPIO_H_

//开关量LED
//MOSS上白灯
#define GPIO_LED_STD_1_PIN          GPIO_PINS_1
#define GPIO_LED_STD_1_PORT         GPIOB
#define _GPIO_LED_STD_1_H()         gpio_bits_set(GPIO_LED_STD_1_PORT, GPIO_LED_STD_1_PIN)
#define _GPIO_LED_STD_1_L()         gpio_bits_reset(GPIO_LED_STD_1_PORT, GPIO_LED_STD_1_PIN)
//MOSS下白灯
#define GPIO_LED_STD_2_PIN          GPIO_PINS_7
#define GPIO_LED_STD_2_PORT         GPIOA
#define _GPIO_LED_STD_2_H()         gpio_bits_set(GPIO_LED_STD_2_PORT, GPIO_LED_STD_2_PIN)
#define _GPIO_LED_STD_2_L()         gpio_bits_reset(GPIO_LED_STD_2_PORT, GPIO_LED_STD_2_PIN)
//MOSS底红灯
#define GPIO_LED_STD_3_PIN          GPIO_PINS_3
#define GPIO_LED_STD_3_PORT         GPIOB
#define _GPIO_LED_STD_3_H()         gpio_bits_set(GPIO_LED_STD_3_PORT, GPIO_LED_STD_3_PIN)
#define _GPIO_LED_STD_3_L()         gpio_bits_reset(GPIO_LED_STD_3_PORT, GPIO_LED_STD_3_PIN)
//光学传感灯组1
#define GPIO_LED_DFH_1_PIN          GPIO_PINS_4
#define GPIO_LED_DFH_1_PORT         GPIOB
#define _GPIO_LED_DFH_1_H()         gpio_bits_set(GPIO_LED_DFH_1_PORT, GPIO_LED_DFH_1_PIN)
#define _GPIO_LED_DFH_1_L()         gpio_bits_reset(GPIO_LED_DFH_1_PORT, GPIO_LED_DFH_1_PIN)
//光学传感灯组2
#define GPIO_LED_DFH_2_PIN          GPIO_PINS_5
#define GPIO_LED_DFH_2_PORT         GPIOB
#define _GPIO_LED_DFH_2_H()         gpio_bits_set(GPIO_LED_DFH_2_PORT, GPIO_LED_DFH_2_PIN)
#define _GPIO_LED_DFH_2_L()         gpio_bits_reset(GPIO_LED_DFH_2_PORT, GPIO_LED_DFH_2_PIN)
//光学传感灯组3
#define GPIO_LED_DFH_3_PIN          GPIO_PINS_6
#define GPIO_LED_DFH_3_PORT         GPIOB
#define _GPIO_LED_DFH_3_H()         gpio_bits_set(GPIO_LED_DFH_3_PORT, GPIO_LED_DFH_3_PIN)
#define _GPIO_LED_DFH_3_L()         gpio_bits_reset(GPIO_LED_DFH_3_PORT, GPIO_LED_DFH_3_PIN)
//光学传感灯组4
#define GPIO_LED_DFH_4_PIN          GPIO_PINS_7
#define GPIO_LED_DFH_4_PORT         GPIOB
#define _GPIO_LED_DFH_4_H()         gpio_bits_set(GPIO_LED_DFH_4_PORT, GPIO_LED_DFH_4_PIN)
#define _GPIO_LED_DFH_4_L()         gpio_bits_reset(GPIO_LED_DFH_4_PORT, GPIO_LED_DFH_4_PIN)

//外部触发源
#define GPIO_EXIT_PIN               GPIO_PINS_5
#define GPIO_EXIT_PORT              GPIOA
#define GPIO_EXIT_SOURCE            GPIO_PINS_SOURCE5

void Gpio_Init(void);
void Gpio_Exit_Init(void);
uint8_t Gpio_Exit_Flag_Get(uint8_t exit_line);
void Gpio_Exit_Flag_Set(uint8_t exit_line, uint8_t state);

#endif