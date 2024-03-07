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
			
			if(KeyNum<=10){            		//������S1~S10�����ж�Ϊ��������
				if(Count<4){                //���������С��4
				
					Password*=10;          	 //��������һλ
					Password+=KeyNum%10;     //��ȡһλ����
					Count++;				 //�ƴμ�һ
				}
				
				
				LCD_ShowNum(2,1,Password,4);  //������ʾ
			}
		
			if(KeyNum==11){                    //�������S11����ȷ����������
			
				if(Password==2345){               //���������ȷ����ʾOK����֮��ʾERR
				
					LCD_ShowString(1,14,"OK ");
					Password=0;      //��������
					Count=0;		//�ƴ�����
					LCD_ShowNum(2,1,Password,4);
				}
				else{
					LCD_ShowString(1,14,"ERR");
					Password=0;      //��������
					Count=0;		//�ƴ�����
					LCD_ShowNum(2,1,Password,4);
				}
			
			}
			
			if(KeyNum==12){            //�������S12�������� ����
			
				Password=0;      //��������
				Count=0;		//�ƴ�����
				LCD_ShowNum(2,1,Password,4);
			
			}
		
		}
		
	
	}
	
}
	
	
	
	