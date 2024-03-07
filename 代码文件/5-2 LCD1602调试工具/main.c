#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"



void main(){

	int x=0;
	LCD_Init();
	
	while(1){
	
		x++;
		Delay(1000);
		LCD_ShowNum(1,1,x,3);
	
	
	}



}