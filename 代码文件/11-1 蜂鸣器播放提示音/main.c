#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"	
#include "Buzzer.h"	


unsigned char KeyNum=0;


void main()
{
	Nixie(1,0);
	
	while(1)
	{
		KeyNum=Key();
		
		if(KeyNum!=0)
		{
			Buzzer_Time(1000);
			
			
			Nixie(1,KeyNum);
		}
		
		
	}
}