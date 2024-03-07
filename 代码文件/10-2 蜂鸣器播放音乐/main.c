#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"


sbit Buzzer=P1^5;

#define SPEED 500

unsigned int FreqTable[]={
	0,
	63777,63872,63969,64054,64140,64216,64291,64360,64426,64489,64547,64603,
	64655,64704,64751,64795,64837,64876,64913,64948,64981,65012,65042,65070,
	65095,65120,65144,65166,65186,65206,65225,65242,65259,65274,65289,65303,
};

code unsigned char Music[]={
	13,4,
	13,4,
	20,4,
	20,4,
	22,4,
	22,4,
	20,4+4,
	0, 4,
	18,4,
	18,4,
	17,4,
	17,4,
	15,4,
	15,4,
	13,4+4,
	0xFF
};

unsigned char FreqSelect,MusicSelect;

void main()
{
	Timer0_Init();
	
	while(1)
	{
		
		if(Music[MusicSelect]!=0xFF)
		{
			FreqSelect=Music[MusicSelect];
			MusicSelect++;
			Delay(SPEED/4*Music[MusicSelect]);
			MusicSelect++;
			
			TR0=0;
			Delay(5);
			TR0=1;
		}
		else
		{
			TR0=0;
			while(1);
		}
		
	}
}




void Timer0_Rountine()  interrupt 1
{
	if(FreqTable[FreqSelect]!=0)      //¶ÔÐÝÖ¹·û½øÐÐÅÐ¶Ï
	{
		TL0=FreqTable[FreqSelect]%256;
		TH0=FreqTable[FreqSelect]/256;
		Buzzer=!Buzzer;
	}
	
	
	
	
	
	
	
}