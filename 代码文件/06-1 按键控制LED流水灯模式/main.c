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
	static unsigned int T0Count=0; //静态变量 子函数退出后保留，不销毁
	
	//为了让定时器始终相隔固定时间溢出一次，因此每次溢出时都进行赋值
	TH0=64535/256;
	TL0=64535%256;
	T0Count++;
	
	//溢出一千次改变一次状态，就可以做成一秒闪一次
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





