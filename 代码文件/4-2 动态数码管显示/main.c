#include <REGX52.H>


void Nixie(unsigned char Location,Number); 
void Delay(unsigned int xms);


void main(){

	while(1){
		
		Nixie(1,1);
		Nixie(2,2);
		Nixie(3,3);
		
	}

}



void Nixie(unsigned char Location,Number){ //形参：位置 显示的位置

	unsigned char NixieTable[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
	
	
	
	switch(Location){
	
		case 1:P2_4=1;P2_3=1;P2_2=1; break;
		case 2:P2_4=1;P2_3=1;P2_2=0; break;
		case 3:P2_4=1;P2_3=0;P2_2=1; break;
		case 4:P2_4=1;P2_3=0;P2_2=0; break;
		case 5:P2_4=0;P2_3=1;P2_2=1; break;
		case 6:P2_4=0;P2_3=1;P2_2=0; break;
		case 7:P2_4=0;P2_3=0;P2_2=1; break;
		case 8:P2_4=0;P2_3=0;P2_2=0; break;
	
	}
	
	P0=NixieTable[Number];
	Delay(1);
	P0=0x00;
}

void Delay(unsigned int xms){

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