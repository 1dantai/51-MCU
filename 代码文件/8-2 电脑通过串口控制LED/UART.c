#include <REGX52.H>




void UART_Init()	//4800bps@11.0592MHz
{
	SCON = 0x50;	//�����ڽ����ⲿ
	PCON |= 0x80;	//ʹ�ܲ����ʱ���λSMOD
	
	TMOD&=0x0F;		//�����ʱ��1ģʽλ
	TMOD|=0x20;     //��ʱ��1��λ�Զ����أ������ʱ��TH1��ŵ�ֵ�Զ���װ��TL1
	
	TL1 = 0xF4;		//�趨��ʱ��ֵ
	TH1 = 0xF4;		//�趨��ʱ����װֵ
	
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	TR1 = 1;		//������ʱ��1
	
	EA=1;        	//�������ڽ��ܵĵ��ж������ȼ�Ĭ��
	ES=1;
}



void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);  //TI����1ʱ˵���������
	TI=0;		   //ֻ�������λTI
}

/* �����жϺ���ģ��

void UART_Routine()	interrupt 4
{
	if(RI==1)    //ȷ�Ͻ�����ɺ�ִ���¼�
	{
		
		RI=0;
	}
	
}

*/



