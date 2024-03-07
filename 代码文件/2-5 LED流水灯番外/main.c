#include <REGX52.H>
#include <INTRINS.H>

void Delay1ms(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	
	while(xms){
		

		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	
		xms--;
	
	}
	
}


void main(){
	unsigned int x;
	x=100;
	
	while(1){
		//123432
		P2=0x7E;
		Delay1ms(x);
		
		
		P2=0xBD;
		Delay1ms(x);
		
		
		P2=0xDB;
		Delay1ms(x);
		
		
		P2=0xE7;
		Delay1ms(x);
		
		
		
		P2=0xDB;
		Delay1ms(x);
		
		P2=0xBD;
		Delay1ms(x);
		
		
		
		
	}
}