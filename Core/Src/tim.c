/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    tim.c
  * @brief   This file provides code for the configuration
  *          of the TIM instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "tim.h"
#include "angle_pid.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* TIM2 init function */

float save_num_pid=2500.0f;


void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  LL_TIM_InitTypeDef TIM_InitStruct = {0};
  LL_TIM_OC_InitTypeDef TIM_OC_InitStruct = {0};

  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* Peripheral clock enable */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  TIM_InitStruct.Prescaler = 84;
  TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
  TIM_InitStruct.Autoreload = 10000-1;
  TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
  LL_TIM_Init(TIM3, &TIM_InitStruct);
  LL_TIM_DisableARRPreload(TIM3);
  LL_TIM_OC_EnablePreload(TIM3, LL_TIM_CHANNEL_CH1);
  TIM_OC_InitStruct.OCMode = LL_TIM_OCMODE_PWM1;
  TIM_OC_InitStruct.OCState = LL_TIM_OCSTATE_DISABLE;
  TIM_OC_InitStruct.OCNState = LL_TIM_OCSTATE_DISABLE;
  TIM_OC_InitStruct.CompareValue =1500;
  TIM_OC_InitStruct.OCPolarity = LL_TIM_OCPOLARITY_HIGH;
  LL_TIM_OC_Init(TIM3, LL_TIM_CHANNEL_CH1, &TIM_OC_InitStruct);
  LL_TIM_OC_DisableFast(TIM3, LL_TIM_CHANNEL_CH1);
  LL_TIM_OC_EnablePreload(TIM3, LL_TIM_CHANNEL_CH2);
  TIM_OC_InitStruct.CompareValue = 1234;
  LL_TIM_OC_Init(TIM3, LL_TIM_CHANNEL_CH2, &TIM_OC_InitStruct);
  LL_TIM_OC_DisableFast(TIM3, LL_TIM_CHANNEL_CH2);
  LL_TIM_OC_EnablePreload(TIM3, LL_TIM_CHANNEL_CH3);
	 TIM_OC_InitStruct.CompareValue = 1500;
  LL_TIM_OC_Init(TIM3, LL_TIM_CHANNEL_CH3, &TIM_OC_InitStruct);
  LL_TIM_OC_DisableFast(TIM3, LL_TIM_CHANNEL_CH3);
  LL_TIM_OC_EnablePreload(TIM3, LL_TIM_CHANNEL_CH4);
	TIM_OC_InitStruct.CompareValue = 1500;
	
  LL_TIM_OC_Init(TIM3, LL_TIM_CHANNEL_CH4, &TIM_OC_InitStruct);
  LL_TIM_OC_DisableFast(TIM3, LL_TIM_CHANNEL_CH4);
  LL_TIM_SetTriggerOutput(TIM3, LL_TIM_TRGO_RESET);
  LL_TIM_DisableMasterSlaveMode(TIM3);
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
    /**TIM3 GPIO Configuration
    PA6     ------> TIM3_CH1
    PA7     ------> TIM3_CH2
    PB0     ------> TIM3_CH3
    PB1     ------> TIM3_CH4
    */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_6|LL_GPIO_PIN_7;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_2;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LL_GPIO_PIN_0|LL_GPIO_PIN_1;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_2;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}







//void MX_TIM3_Init(void)
//{

//  /* USER CODE BEGIN TIM2_Init 0 */

//  /* USER CODE END TIM2_Init 0 */

//  LL_TIM_InitTypeDef TIM_InitStruct = {0};
//  LL_TIM_OC_InitTypeDef TIM_OC_InitStruct = {0};

//  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
//  /* Peripheral clock enable */
//  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);

//  /* USER CODE BEGIN TIM2_Init 1 */

//  /* USER CODE END TIM2_Init 1 */
//  TIM_InitStruct.Prescaler = 84-1;
//  TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
//  TIM_InitStruct.Autoreload = 10000-1;
//  TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
//  LL_TIM_Init(TIM3, &TIM_InitStruct);
//  LL_TIM_DisableARRPreload(TIM3);
//  LL_TIM_SetClockSource(TIM3, LL_TIM_CLOCKSOURCE_INTERNAL);
//  LL_TIM_OC_EnablePreload(TIM3, LL_TIM_CHANNEL_CH1);
//  TIM_OC_InitStruct.OCMode = LL_TIM_OCMODE_PWM1;
//  TIM_OC_InitStruct.OCState = LL_TIM_OCSTATE_DISABLE;
//  TIM_OC_InitStruct.OCNState = LL_TIM_OCSTATE_DISABLE;
//  TIM_OC_InitStruct.CompareValue = 500;
//  TIM_OC_InitStruct.OCPolarity = LL_TIM_OCPOLARITY_HIGH;
//  LL_TIM_OC_Init(TIM3, LL_TIM_CHANNEL_CH1, &TIM_OC_InitStruct);
//  LL_TIM_OC_DisableFast(TIM3, LL_TIM_CHANNEL_CH1);
//  LL_TIM_SetTriggerOutput(TIM3, LL_TIM_TRGO_RESET);
//  LL_TIM_DisableMasterSlaveMode(TIM3);
//  /* USER CODE BEGIN TIM2_Init 2 */

//  /* USER CODE END TIM2_Init 2 */
//  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
//    /**TIM2 GPIO Configuration
//    PA0-WKUP     ------> TIM2_CH1
//    */
//  GPIO_InitStruct.Pin = LL_GPIO_PIN_6;
//  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
//  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
//  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
//  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
//  GPIO_InitStruct.Alternate = LL_GPIO_AF_1;
//  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

//}


void TIM_PWM(int num)
{
//LL_TIM_OC_SetCompareCH1(TIM3,num);
//	LL_TIM_OC_SetCompareCH2(TIM3,num);
//	LL_TIM_OC_SetCompareCH3(TIM3,num);
//	LL_TIM_OC_SetCompareCH4(TIM3,num);
		if(num>2500)
	{
		save_num_pid=2500;
	}
		else if(num<500)
	{
		save_num_pid=500;
	}
	save_num_pid=num;
}






//void Timer4_Init(u16 arr,u16 psc)
//{



//   LL_TIM_InitTypeDef TIM_InitStruct = {0};

//  /* Peripheral clock enable */
//  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM4);

//  /* TIM4 interrupt Init */
//  NVIC_SetPriority(TIM4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
//  NVIC_EnableIRQ(TIM4_IRQn);

//  /* USER CODE BEGIN TIM4_Init 1 */

//  /* USER CODE END TIM4_Init 1 */
//  TIM_InitStruct.Prescaler = psc;
//  TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
//  TIM_InitStruct.Autoreload = arr;
//  TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
//  LL_TIM_Init(TIM4, &TIM_InitStruct);
//  LL_TIM_DisableARRPreload(TIM4);
//  LL_TIM_SetClockSource(TIM4, LL_TIM_CLOCKSOURCE_INTERNAL);
//  LL_TIM_SetTriggerOutput(TIM4, LL_TIM_TRGO_RESET);
//  LL_TIM_DisableMasterSlaveMode(TIM4);
//	 
//	LL_TIM_EnableIT_UPDATE(TIM4);
//	LL_TIM_EnableCounter(TIM4);
//	LL_TIM_GenerateEvent_UPDATE( TIM4);

//}






void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  LL_TIM_InitTypeDef TIM_InitStruct = {0};

  /* Peripheral clock enable */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM2);

  /* TIM3 interrupt Init */
  NVIC_SetPriority(TIM2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),1, 0));
  NVIC_EnableIRQ(TIM2_IRQn);

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  TIM_InitStruct.Prescaler = 840-1;
  TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
  TIM_InitStruct.Autoreload = 125-1;
  TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
  LL_TIM_Init(TIM2, &TIM_InitStruct);
  LL_TIM_DisableARRPreload(TIM2);
  LL_TIM_SetClockSource(TIM2, LL_TIM_CLOCKSOURCE_INTERNAL);
  LL_TIM_SetTriggerOutput(TIM2, LL_TIM_TRGO_RESET);
  LL_TIM_DisableMasterSlaveMode(TIM2);
	 

	LL_TIM_DisableIT_UPDATE(TIM2);
	LL_TIM_DisableCounter(TIM2);
	LL_TIM_GenerateEvent_UPDATE( TIM2);
}

void TIM2_IRQHandler(void)
{

	if(LL_TIM_IsActiveFlag_UPDATE(TIM2)==SET)//溢出中断
	{
		
		//all_set_Fun();
	  
		test_angle_turn();
		
		LL_TIM_ClearFlag_UPDATE(TIM2);  //清除中断标志位    		
	}	
	
	
}











/* USER CODE BEGIN 1 */
void tim_start(void)
{
 MX_TIM3_Init();
	
	LL_TIM_CC_EnableChannel( TIM3 , LL_TIM_CHANNEL_CH1 );
	LL_TIM_CC_EnableChannel( TIM3 , LL_TIM_CHANNEL_CH2 );
	LL_TIM_CC_EnableChannel( TIM3 , LL_TIM_CHANNEL_CH3 );
	LL_TIM_CC_EnableChannel( TIM3 , LL_TIM_CHANNEL_CH4 );
	//LL_TIM_EnableAllOutputs( TIM3);						//只有Timer1等高级定时器需要，必须放置在LL_TIM_BDTR_Init(TIM1, &TIM_BDTRInitStruct);之后。
	
	LL_TIM_EnableCounter( TIM3 );	
	
	//LL_TIM_GenerateEvent_UPDATE( TIM3);


}

/* USER CODE END 1 */





