#include <REGX52.H>

/**
  * @brief      定时器0初始化，1毫秒@11.0592MHz
  * @param  	无
  * @retval 	无
  
*/
void Timer0_Init() 		//1毫秒@11.0592MHz
{
	                //配置定时器工作模式
			        //高四位不变，低四位清零
		            //高四位不变，低四位置1
				    //通过与或的方式只改变低四位，不影响高四位
	TMOD&=0xF0;
	TMOD|=0x01;
	
	TF0=0;			//清除TF0标志
	TR0=1;			//定时器0开始计时
	
	TH0=0xFC;		//设置定时初值
	TL0=0x66;		//设置定时初值
	
	ET0=1; 			//定时器0中断允许
	EA=1;			//中断总开关打开
	
	PT0=0;			//优先级最低
}


/*  定时器中断函数模板

void Timer0_Rountine()  interrupt 1
{
	static unsigned int T0Count=0; //静态变量 子函数退出后保留，不销毁
	
	//为了让定时器始终每隔1ms溢出一次，因此每次溢出时都进行赋值
	TH0=0xFC;
	TL0=0x66;
	T0Count++;
	
	//溢出一千次改变一次状态，就可以做成一秒闪一次
	if(T0Count>=1000)
	{
		T0Count=0;
		P2_0=~P2_0;
	}

}


*/