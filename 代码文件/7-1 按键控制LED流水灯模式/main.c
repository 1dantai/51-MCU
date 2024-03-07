#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.H>


unsigned char KeyNum,LEDMode=0;


void main()
{
	P2=0xFE;
	
	Timer0_Init(); 
	
	while(1)
	{
		KeyNum=Key();
		
		if(KeyNum!=0)
		{
			if(KeyNum==1)
			{
				LEDMode++;
				if(LEDMode>=2)
				{
					LEDMode=0;
				}
			}
			
		
		
		}
	}
}



void Timer0_Rountine()  interrupt 1
{
	static unsigned int T0Count=0; //��̬���� �Ӻ����˳�������������
	
	//Ϊ���ö�ʱ��ʼ������̶�ʱ�����һ�Σ����ÿ�����ʱ�����и�ֵ
	TH0=64535/256;
	TL0=64535%256;
	T0Count++;
	
	//���һǧ�θı�һ��״̬���Ϳ�������һ����һ��
	if(T0Count>=500)
	{
		T0Count=0;
		if(LEDMode==0)
		{
			P2=_cror_(P2,1);
		}
		if(LEDMode==1)
		{
			P2=_crol_(P2,1);
		}
	}

}





