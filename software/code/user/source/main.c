#include "main.h"

int main(void)
{
    System_Init();//上电初始化
    while(1)
    {
        //10ms周期执行
        if(System_Timer_Flag_Get())
        {
            System_Timer_Flag_Set(0);
            gesture();//手势识别
            Led_Fsm(10);//LED状态机
        }
	}
}

//系统上电初始化
void System_Init(void)
{
    system_clock_config();                                  //系统时钟树配置
    nvic_priority_group_config(NVIC_PRIORITY_GROUP_4);      //中断优先级分组模式
    Gpio_Init();                                            //通用GPIO初始化
    System_Timer_Init();                                    //系统定时器初始化
    Pwm_Timer_Init();                                       //PWM定时器初始化
    _SET_PWM_LED_MOSS(100);                                 //点亮MOSS红眼
    // Gpio_Exit_Init();                                       //外部中断促使华
    SW_I2C_initial();                                       //软件I2C初始化
    Paj7620u2_Init();                                       //手势传感器上电初始化
    Usb_Init();                                             //初始化USB
    _GPIO_LED_STD_1_L();                                    //开启白灯表示初始化完成
    _GPIO_LED_STD_2_L();
}

//手势指令对应操作
void gesture(void)
{
    uint8_t state;
    state = Paj7620u2_Get();
    if(state)
    {
        Led_Flash();
        switch(state)
        {
            case PAJ_UP :    Usb_Send_Hotkey(0x30, 0x26); break; // right_shift + right_ctrl + 9
            case PAJ_DOWN :  Usb_Send_Hotkey(0x30, 0x25); break; // right_shift + right_ctrl + 8
            case PAJ_LEFT :  Usb_Send_Hotkey(0x30, 0x24); break; // right_shift + right_ctrl + 7
            case PAJ_RIGHT : Usb_Send_Hotkey(0x30, 0x23); break; // right_shift + right_ctrl + 6
        }
    }
}