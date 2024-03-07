#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"


unsigned char KeyNum;
unsigned int Password,Count;

void main(){
	
	
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	
	while(1){
	
		KeyNum=MatrixKey();
		
		if(KeyNum!=0){
			
			if(KeyNum<=10){            		//若按下S1~S10，则判定为输入密码
				if(Count<4){                //若输入次数小于4
				
					Password*=10;          	 //密码左移一位
					Password+=KeyNum%10;     //获取一位密码
					Count++;				 //计次加一
				}
				
				
				LCD_ShowNum(2,1,Password,4);  //更新显示
			}
		
			if(KeyNum==11){                    //如果按下S11，则确定输入密码
			
				if(Password==2345){               //如果密码正确，显示OK，反之显示ERR
				
					LCD_ShowString(1,14,"OK ");
					Password=0;      //密码清零
					Count=0;		//计次清零
					LCD_ShowNum(2,1,Password,4);
				}
				else{
					LCD_ShowString(1,14,"ERR");
					Password=0;      //密码清零
					Count=0;		//计次清零
					LCD_ShowNum(2,1,Password,4);
				}
			
			}
			
			if(KeyNum==12){            //如果按下S12，则清零 重置
			
				Password=0;      //密码清零
				Count=0;		//计次清零
				LCD_ShowNum(2,1,Password,4);
			
			}
		
		}
		
	
	}
	
}
	
	
	
	