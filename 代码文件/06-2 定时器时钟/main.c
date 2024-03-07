#include <REGX52.H>

#include "LCD1602.h"
#include "Timer0.h"
#include "Delay.h"


unsigned int Sec=0,Min=0,Hour=0;

void main()
{
	LCD_Init();
	Timer0_Init();
	
	LCD_ShowString(1,1,"CLOCK:");
	
	
	while(1)
	{
		LCD_ShowChar(2,3,':');
		LCD_ShowChar(2,6,':');
		
		LCD_ShowNum(2,7,Sec,2);
		LCD_ShowNum(2,4,Min,2);
		LCD_ShowNum(2,1,Hour,2);
	}
}




void Timer0_Rountine()  interrupt 1
{
	static unsigned int T0Count=0; //��̬���� �Ӻ����˳�������������
	
	//Ϊ���ö�ʱ��ʼ��ÿ��1ms���һ�Σ����ÿ�����ʱ�����и�ֵ
	TH0=0xFC;
	TL0=0x18;
	T0Count++;
	
	//���һǧ�θı�һ��״̬���Ϳ�������һ����һ��
	if(T0Count>=1000)
	{
		T0Count=0;
		Sec++;
		if(Sec>=60)
		{
			Sec=0;
			Min++;
			
			if(Min>=60)
			{
				Min=0;
				Hour++;
				
				if(Hour>=24)
				{
					Hour=0;
				}
			}
		}
		
	}

}