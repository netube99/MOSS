#include "led.h"
#include "timer.h"

//底部红灯LED闪烁延时时间
uint8_t flash_time = 0 ;

//LED状态机
void Led_Fsm(uint16_t ms)
{
    static uint16_t ms100 = 0, ms300 = 0;
    ms100 += ms ;
    ms300 += ms ;
    if(ms100 >= 100)
    {
        ms100 = 0 ;
        //底部红灯闪烁
        if(flash_time)
        {
            _GPIO_LED_STD_3_H();
            flash_time -- ;
        }
        else _GPIO_LED_STD_3_L();
    }
    if(ms300 >= 300)
    {
        ms300 = 0 ;
        //播放东方红
        Led_Dfh_Play_Step();
    }
}

//简谱音调数值转换成LED灯组
void Led_Dfh_Set(uint8_t num)
{
    //延音标志
    if(num >= 8)
        _GPIO_LED_DFH_4_L();
    else
        _GPIO_LED_DFH_4_H();
    //1~7
    if(num & 0x04)
        _GPIO_LED_DFH_3_L();
    else
        _GPIO_LED_DFH_3_H();
    if(num & 0x02)
        _GPIO_LED_DFH_2_L();
    else
        _GPIO_LED_DFH_2_H();
    if(num & 0x01)
        _GPIO_LED_DFH_1_L();
    else
        _GPIO_LED_DFH_1_H();
}

//东方红播放一个音
void Led_Dfh_Play_Step(void)
{
    static uint8_t step = 0 ;
    Led_Dfh_Set(dfh[step]);
    step ++ ;
    if(step >= 32)
        step = 0 ;
}

//MOSS关灯装死
void Led_Turn_Off_All(void)
{
    _GPIO_LED_DFH_1_H();
    _GPIO_LED_DFH_2_H();
    _GPIO_LED_DFH_3_H();
    _GPIO_LED_DFH_4_H();
    _GPIO_LED_STD_1_H();
    _GPIO_LED_STD_2_H();
    _GPIO_LED_STD_3_H();
    _SET_PWM_LED_MOSS(0);
}

//设置MOSS红眼病严重程度
void Led_Moss_Set(int8_t dir)
{
    static uint8_t moss_light = 5 ;
    if(dir > 0)
    {
        moss_light ++ ;
        if(moss_light > 4)
            moss_light = 4 ;
    }
    else
    {
        moss_light -- ;
        if(moss_light < 1)
            moss_light = 1 ;
    }
    _SET_PWM_LED_MOSS(moss_light * 25);
}

//触发一次底部LED闪烁
void Led_Flash(void)
{
    flash_time += 5 ;
}