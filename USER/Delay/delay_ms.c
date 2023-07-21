#include "tim.h"
#include "main.h"
#include "usart.h"


u16 M_counter=0;
//u16 TIMER_COUNTER[5]={0};



void MX_TIM5_Init(void)
{

  /* USER CODE BEGIN TIM5_Init 0 */

  /* USER CODE END TIM5_Init 0 */

  LL_TIM_InitTypeDef TIM_InitStruct = {0};


  /* Peripheral clock enable */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM5);

  /* TIM5 interrupt Init */
  NVIC_SetPriority(TIM5_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),3, 0));
  NVIC_EnableIRQ(TIM5_IRQn);

  /* USER CODE BEGIN TIM5_Init 1 */

  /* USER CODE END TIM5_Init 1 */
  TIM_InitStruct.Prescaler = 8400-1;
  TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
  TIM_InitStruct.Autoreload = 10-1;
  TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
  LL_TIM_Init(TIM5, &TIM_InitStruct);
  LL_TIM_EnableARRPreload(TIM5);
  LL_TIM_SetClockSource(TIM5, LL_TIM_CLOCKSOURCE_INTERNAL);
  LL_TIM_SetTriggerOutput(TIM5, LL_TIM_TRGO_RESET);
  LL_TIM_DisableMasterSlaveMode(TIM5);
  /* USER CODE BEGIN TIM5_Init 2 */
	LL_TIM_EnableIT_UPDATE(TIM5);
	LL_TIM_EnableCounter(TIM5);
	LL_TIM_GenerateEvent_UPDATE( TIM5);
  /* USER CODE END TIM5_Init 2 */

}


void TIM5_IRQHandler(void)
{

	if(LL_TIM_IsActiveFlag_UPDATE(TIM5)==SET)//溢出中断
	{
			M_counter++;
				if(M_counter>5000)
				{
					
						M_counter=0;
				}
		
	  LL_TIM_ClearFlag_UPDATE(TIM5);  //清除中断标志位    		
	}	
	
	
}



 



void  LL_uDelay(uint16_t us)
{	
	uint32_t temp;	    	 
	SysTick->LOAD=us*(84000000/1000000); 					//时间加载	  		 
	SysTick->VAL=0x00;        					//清空计数器
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;	//开始倒数	  
	do
	{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));		//等待时间到达   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;	//关闭计数器
	SysTick->VAL =0X00;      					 //清空计数器	 
}







