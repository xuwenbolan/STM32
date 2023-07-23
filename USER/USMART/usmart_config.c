#include "usmart.h"
#include "usmart_str.h" 
#include "tim.h"
#include "USART2.h"
#include "PWM_Calculation.h"
#include "main.h"

////////////////////////////�û�������///////////////////////////////////////////////
//������Ҫ�������õ��ĺ�����������ͷ�ļ�(�û��Լ����) 
		

										
//�������б��ʼ��(�û��Լ����)
//�û�ֱ������������Ҫִ�еĺ�����������Ҵ�
struct _m_usmart_nametab usmart_nametab[]=
{
#if USMART_USE_WRFUNS==1 	//���ʹ���˶�д����
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
//�������ƹ�������ʼ��
//�õ������ܿغ���������
//�õ�����������
struct _m_usmart_dev usmart_dev=
{
	usmart_nametab,
	usmart_init,
	usmart_cmd_rec,
	usmart_exe,
	usmart_scan,
	sizeof(usmart_nametab)/sizeof(struct _m_usmart_nametab),//��������
	0,	  	//��������
	0,	 	//����ID
	1,		//������ʾ����,0,10����;1,16����
	0,		//��������.bitx:,0,����;1,�ַ���	    
	0,	  	//ÿ�������ĳ����ݴ��,��ҪMAX_PARM��0��ʼ��
	0,		//�����Ĳ���,��ҪPARM_LEN��0��ʼ��
};



















