#include "usmart.h"
#include "usmart_str.h" 
#include "tim.h"
#include "USART2.h"
#include "PWM_Calculation.h"
#include "main.h"

////////////////////////////用户配置区///////////////////////////////////////////////
//这下面要包含所用到的函数所申明的头文件(用户自己添加) 
		

										
//函数名列表初始化(用户自己添加)
//用户直接在这里输入要执行的函数名及其查找串
struct _m_usmart_nametab usmart_nametab[]=
{
#if USMART_USE_WRFUNS==1 	//如果使能了读写操作
	(void*)read_addr,"u32 read_addr(u32 addr)",
	(void*)write_addr,"void write_addr(u32 addr,u32 val)",	 
#endif
//	(void*)delay_ms,"void delay_ms(u16 nms)",
//	(void*)delay_us,"void delay_us(u32 nus)",		
//					(void*)LED_Init,"void LED_Init(void)",
//					(void*)Control_LED0, "u8 Control_LED0(u16 delta0)",
//					(void*)Control_LED1, "u8 Control_LED1(u16 delta0)",
//					(void*)Control_LED01,"u8 Control_LED01(u16 delta0)",
	(void*) TIM_PWM,"void TIM_PWM(int num)",
		(void*)Usart_SendString,"void Usart_SendString( USART_TypeDef * pUSARTx, char *str) ",
			//(void*) test_Send,"void test_Send(char *str)",
			(void*) test_PWM,"test_PWM(int flag1,float angle1,int flag2,float angle2,int flag3,float angle3,int flag4,float angle4)",
			(void*)set_ARM_state_test,"void set_ARM_state_test(int flag1 ,int x,int flag2,int y,int flag3,int z)",
				(void*)set_angle_fun,"void set_angle_fun(int t1, int t2, int t3,int t4,int t5,int t6)",
			(void*)test_arm_oc_pwm,"void test_arm_oc_pwm(int id,int rate)",
			
			
			
};					  
///////////////////////////////////END///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//函数控制管理器初始化
//得到各个受控函数的名字
//得到函数总数量
struct _m_usmart_dev usmart_dev=
{
	usmart_nametab,
	usmart_init,
	usmart_cmd_rec,
	usmart_exe,
	usmart_scan,
	sizeof(usmart_nametab)/sizeof(struct _m_usmart_nametab),//函数数量
	0,	  	//参数数量
	0,	 	//函数ID
	1,		//参数显示类型,0,10进制;1,16进制
	0,		//参数类型.bitx:,0,数字;1,字符串	    
	0,	  	//每个参数的长度暂存表,需要MAX_PARM个0初始化
	0,		//函数的参数,需要PARM_LEN个0初始化
};



















