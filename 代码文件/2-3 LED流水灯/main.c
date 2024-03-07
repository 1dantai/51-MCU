#include <REGX52.H>
#include <INTRINS.H>


void Delay100ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 195;
	j = 138;
	do
	{
		while (--j);
	} while (--i);
}


void main()
{
	while(1)
	{
		P2=0xFE;
		Delay100ms();
		
		
		P2=0xFD;
		Delay100ms();
		
		
		P2=0xFB;
		Delay100ms();
		
		
		P2=0xF7;
		Delay100ms();
		
		
		P2=0xEF;
		Delay100ms();
		
		
		P2=0xDF;
		Delay100ms();
		
		
		P2=0xBF;
		Delay100ms();
		
		P2=0x7F;
		Delay100ms();
		
	}
}