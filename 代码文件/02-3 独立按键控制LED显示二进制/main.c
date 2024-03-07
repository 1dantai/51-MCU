#include <REGX52.H>

void Delay(unsigned int xms);		


void main(){

//	P2=0xFE;
	
	while(1){
		 
		if(P3_1==0){
			
			Delay(20);   //按下抖动
			
			while(P3_1==0);
			Delay(20);   //松手抖动
			P2--;  //直接取反
		
		}
	
		
	}



}

void Delay(unsigned int xms)		
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

