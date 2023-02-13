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
            Led_Fsm(10);//LED状态机
        }
        //触发源检测
        if(Gpio_Exit_Flag_Get(5))
        {
            Gpio_Exit_Flag_Set(5, 0);
            //todo 手势数据读取 & 执行
        }
	}
}

//系统上电初始化
void System_Init(void)
{
    system_clock_config();                                  //系统时钟树配置
    nvic_priority_group_config(NVIC_PRIORITY_GROUP_4);      //中断优先级分组模式
    Gpio_Init();
    _SET_PWM_LED_MOSS(100);                                 //点亮MOSS红眼
    Gpio_Exit_Init();
    SW_I2C_initial();
    _GPIO_LED_STD_1_L();                                    //开启白灯表示初始化完成
    _GPIO_LED_STD_2_L();
}