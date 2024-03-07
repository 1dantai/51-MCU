#include <REGX52.H>

void Delay(unsigned int xms);		


void main(){


	unsigned char num_LED=0;
	P2=~0x01;
	while(1){
		 
		if(P3_1==0){
			
			Delay(20);   
			while(P3_1==0);
			Delay(20);   
			
			
			num_LED++;
			
			if(num_LED>=8){
				num_LED=0;
			}
			
			P2=~(0x01<<num_LED);
		
		}
	
		
		if(P3_0==0){
			
			Delay(20);   
			while(P3_0==0);
			Delay(20);   
			
			if(num_LED==0){
				num_LED=7;
			}
			else{
				num_LED--;
			}
			
			P2=~(0x01<<num_LED);
			
			
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

