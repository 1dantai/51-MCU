#include <REGX52.H>

void Delay(unsigned int xms);		


void main(){

//	P2=0xFE;
	
	while(1){
		 
		if(P3_1==0){
			
			Delay(20);   //按下抖动
			
			while(P3_1==0);
			Delay(20);   //松手抖动
			P2_0=~P2_0;  //直接取反
		
		}
		
//		if(P3_1==0 && P2_0==0){
//			
//			Delay(20);
//			while(P3_1==0);
//			Delay(20);
//			P2_0=1;
//			
//		
//		
//		}
		
		
		
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

