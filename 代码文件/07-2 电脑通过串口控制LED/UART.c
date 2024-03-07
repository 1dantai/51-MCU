#include <REGX52.H>




void UART_Init()	//4800bps@11.0592MHz
{
	SCON = 0x50;	//允许串口接收外部
	PCON |= 0x80;	//使能波特率倍速位SMOD
	
	TMOD&=0x0F;		//清除定时器1模式位
	TMOD|=0x20;     //定时器1八位自动重载，当溢出时将TH1存放的值自动重装入TL1
	
	TL1 = 0xF4;		//设定定时初值
	TH1 = 0xF4;		//设定定时器重装值
	
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	
	EA=1;        	//启动串口接受的的中断且优先级默认
	ES=1;
}



void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);  //TI等于1时说明发送完成
	TI=0;		   //只能软件复位TI
}

/* 串口中断函数模板

void UART_Routine()	interrupt 4
{
	if(RI==1)    //确认接受完成后执行事件
	{
		
		RI=0;
	}
	
}

*/



