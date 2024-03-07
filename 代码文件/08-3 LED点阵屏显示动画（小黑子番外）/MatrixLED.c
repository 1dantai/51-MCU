#include <REGX52.H>
#include "Delay.h"


//74HC595管脚
sbit	RCK = P3^5;    //RCLK
sbit 	SCK = P3^6;	   //SRCLK
sbit 	SER = P3^4;

#define MATRIX_LED_PORT 	P0


/**
  * @brief   74HC595写入一个字节
  * @param   Byte 要写入的字节
  * @retval  无
  
*/
void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	
	for(i=0;i<8;i++)
	{
		SER=Byte&(0x80>>i); //循环一次，右移一位，直到取出Byte的全部八位
		SCK=1;
		SCK=0;
	}
	
	RCK=1;
	RCK=0;
	
	/*
	SER=Byte&0x80;
	八位赋值给一位，且“Byte&0x80”非0即1，那么“SER”同样非0即1
	*/
}




/**
  * @brief   	LED点阵屏初始化
  * @param  	无
  * @retval 	无
  
*/
void MatrixLED_Init()
{
	SCK=0;
	RCK=0;

}




/**
  * @brief   LED点阵屏显示一列数据
  * @param   Column 要选择的列，范围：0~7，第0列在最左边
  * @param 	 Data 所选择列显示的数据，高位在上，1为亮，0为灭
  * @retval  无
  
*/
void MatrixLED_ShowColumn(unsigned char Column,Data)
{
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT=~(0x80>>Column);
	
	Delay(1);
	MATRIX_LED_PORT=0xFF;

}