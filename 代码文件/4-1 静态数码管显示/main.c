#include <REGX52.H>


void Nixie(unsigned char Location,Number); 



void main(){

	Nixie(8,13);
	while(1){
		
		
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

}