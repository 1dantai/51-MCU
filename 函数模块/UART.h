#ifndef __UART_H__
#define __UART_H__


/**
  * @brief   ���ڳ�ʼ��
  * @param   ��
  * @retval  ��
  
*/
void UART_Init();	//4800bps@11.0592MHz


/**
  * @brief  ���ڷ���һ���ֽ�����
  * @param  Byte Ҫ���͵�һ���ֽ�����
  * @retval ��
  
*/
void UART_SendByte(unsigned char Byte);


#endif