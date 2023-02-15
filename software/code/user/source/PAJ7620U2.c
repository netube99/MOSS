#include "PAJ7620U2.h"
#include "PAJ7620U2_cmd.h"
#include "i2c_sw.h"

void Paj7620u2_Init(void)
{
    uint8_t i ;
    SW_I2C_WriteControl_8Bit(SW_I2C1, PAJ7620U2_I2C_ADDRESS, PAJ_BANK_SELECT, 0);
    for (i = 0; i < Init_Array; i++)
        SW_I2C_WriteControl_8Bit(SW_I2C1, PAJ7620U2_I2C_ADDRESS, Init_Register_Array[i][0], Init_Register_Array[i][1]);
    SW_I2C_WriteControl_8Bit(SW_I2C1, PAJ7620U2_I2C_ADDRESS, PAJ_BANK_SELECT, 0);
    for (i = 0; i < Gesture_Array_SIZE; i++)
		SW_I2C_WriteControl_8Bit(SW_I2C1, PAJ7620U2_I2C_ADDRESS, Init_Gesture_Array[i][0], Init_Gesture_Array[i][1]);//Gesture register initializes
}

uint8_t Paj7620u2_Get(void)
{
    uint8_t data = 0, out = 0;
    data = SW_I2C_ReadControl_8Bit(SW_I2C1, PAJ7620U2_I2C_ADDRESS, PAJ_INT_FLAG1);
    switch(data)
    {
        case 0x01: out = PAJ_DOWN;  break;
        case 0x02: out = PAJ_UP;    break;
        case 0x04: out = PAJ_RIGHT; break;
        case 0x08: out = PAJ_LEFT;  break;
    }
    return out ;
}