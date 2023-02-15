#ifndef _PAJ7620U2_
#define _PAJ7620U2_

#include "at32f415.h"

//i2c address
#define PAJ7620U2_I2C_ADDRESS	0x73<<1
//Register Bank select
#define PAJ_BANK_SELECT			0xEF		/*Bank0=0x00,Bank1=0x01*/
//Register Bank 0
#define PAJ_SUSPEND			 	0x03		/*I2C suspend command (Write 0x01 to enter suspend state). I2C wake-up command is slave ID wake-up. Refer to topic ��I2C Bus Timing Characteristics and Protocol��*/
#define PAJ_INT_FLAG1_MASK		0x41		/*Gesture detection interrupt flag mask*/
#define PAJ_INT_FLAG2_MASK		0x42		/*Gesture/PS detection interrupt flag mask*/
#define PAJ_INT_FLAG1		    0x43		/*Gesture detection interrupt flag*/
#define PAJ_INT_FLAG2			0x44		/*Gesture/PS detection interrupt flag*/
#define PAJ_STATE				0x45		/*State indicator for gesture detection (Only functional at gesture detection mode)*/
#define PAJ_PS_HIGH_THRESHOLD	0x69		/*PS hysteresis high threshold (Only functional at proximity detection mode)*/
#define PAJ_PS_LOW_THRESHOLD	0x6A		/*PS hysteresis low threshold (Only functional at proximity detection mode)*/
#define PAJ_PS_APPROACH_STATE	0x6B		/*PS approach state,  Approach = 1 , (8 bits PS data >= PS high threshold),  Not Approach = 0 , (8 bits PS data <= PS low threshold)(Only functional at proximity detection mode)*/
#define PAJ_PS_DATA				0x6C		/*PS 8 bit data(Only functional at gesture detection mode)*/
#define PAJ_OBJ_BRIGHTNESS		0xB0		/*Object Brightness (Max. 255)*/
#define PAJ_OBJ_SIZE_L			0xB1		/*Object Size(Low 8 bit)*/
#define PAJ_OBJ_SIZE_H			0xB2		/*Object Size(High 8 bit)*/

//Register Bank 1
#define PAJ_PS_GAIN				0x44		/*PS gain setting (Only functional at proximity detection mode)*/
#define PAJ_IDLE_S1_STEP_L		0x67		/*IDLE S1 Step, for setting the S1, Response Factor(Low 8 bit)*/
#define PAJ_IDLE_S1_STEP_H		0x68		/*IDLE S1 Step, for setting the S1, Response Factor(High 8 bit)*/
#define PAJ_IDLE_S2_STEP_L		0x69		/*IDLE S2 Step, for setting the S2, Response Factor(Low 8 bit)*/
#define PAJ_IDLE_S2_STEP_H		0x6A		/*IDLE S2 Step, for setting the S2, Response Factor(High 8 bit)*/
#define PAJ_OPTOS1_TIME_L		0x6B		/*OPtoS1 Step, for setting the OPtoS1 time of operation state to standby 1 state(Low 8 bit)*/
#define PAJ_OPTOS2_TIME_H		0x6C		/*OPtoS1 Step, for setting the OPtoS1 time of operation state to standby 1 stateHigh 8 bit)*/
#define PAJ_S1TOS2_TIME_L		0x6D		/*S1toS2 Step, for setting the S1toS2 time of standby 1 state to standby 2 state(Low 8 bit)*/
#define PAJ_S1TOS2_TIME_H		0x6E		/*S1toS2 Step, for setting the S1toS2 time of standby 1 state to standby 2 stateHigh 8 bit)*/
#define PAJ_EN					0x72		/*Enable/Disable PAJ7620U2*/
//Gesture detection interrupt flag
#define PAJ_UP				    0x01
#define PAJ_DOWN			    0x02
#define PAJ_LEFT			    0x04
#define PAJ_RIGHT			    0x08
#define PAJ_FORWARD			    0x10
#define PAJ_BACKWARD		    0x20
#define PAJ_CLOCKWISE			0x40
#define PAJ_COUNT_CLOCKWISE		0x80
#define PAJ_WAVE				0x100
//Initialize array size
#define Init_Array sizeof(Init_Register_Array)/2
#define PS_Array_SIZE sizeof(Init_PS_Array)/2
#define Gesture_Array_SIZE sizeof(Init_Gesture_Array)/2

void Paj7620u2_Init(void);
uint8_t Paj7620u2_Get(void);

#endif
