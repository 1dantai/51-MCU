#include <REGX52.H>
#include "Delay.h"


//74HC595�ܽ�
sbit	RCK = P3^5;    //RCLK
sbit 	SCK = P3^6;	   //SRCLK
sbit 	SER = P3^4;

#define MATRIX_LED_PORT 	P0


/**
  * @brief   74HC595д��һ���ֽ�
  * @param   Byte Ҫд����ֽ�
  * @retval  ��
  
*/
void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	
	for(i=0;i<8;i++)
	{
		SER=Byte&(0x80>>i); //ѭ��һ�Σ�����һλ��ֱ��ȡ��Byte��ȫ����λ
		SCK=1;
		SCK=0;
	}
	
	RCK=1;
	RCK=0;
	
	/*
	SER=Byte&0x80;
	��λ��ֵ��һλ���ҡ�Byte&0x80����0��1����ô��SER��ͬ����0��1
	*/
}




/**
  * @brief   	LED��������ʼ��
  * @param  	��
  * @retval 	��
  
*/
void MatrixLED_Init()
{
	SCK=0;
	RCK=0;

}




/**
  * @brief   LED��������ʾһ������
  * @param   Column Ҫѡ����У���Χ��0~7����0���������
  * @param 	 Data ��ѡ������ʾ�����ݣ���λ���ϣ�1Ϊ����0Ϊ��
  * @retval  ��
  
*/
void MatrixLED_ShowColumn(unsigned char Column,Data)
{
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT=~(0x80>>Column);
	
	Delay(1);
	MATRIX_LED_PORT=0xFF;

}