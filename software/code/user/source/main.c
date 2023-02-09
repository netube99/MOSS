#include "main.h"

int main(void)
{
    System_Init();      //上电初始化
    System_Loop();      //进入系统主循环
}

void System_Loop(void)
{
    while(1)
    {
		
		}
}

//系统上电初始化
void System_Init(void)
{
    system_clock_config();                                  //系统时钟树配置
    nvic_priority_group_config(NVIC_PRIORITY_GROUP_4);      //中断优先级分组模式
}