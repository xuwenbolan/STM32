/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "usart.h"
#include "USART2.h"	
#include "usmart.h"	
#include "itoa_turn.h"
#include "PWM_Calculation.h"
#include "calculate_D_H.h"
#include "usart3.h"
#include "angle_pid.h"
#define sys_test_time			84000000





float a=1500.0f;
int task_check_flag=0;
int count_num=0;
int flag_eq=0;
/*
rec_data_sovle[0]:x
rec_data_sovle[1]:y
rec_data_sovle[2]:z
rec_data_sovle[0]:cmd

*/
float rec_data_sovle[4]={0};


void SystemClock_Config(void);


/**
  * @brief  The application entry point.
  * @retval int
  */
	
	void task_check(void)
	{
		

	
	if((task_check_flag)&&(break_flag!=1))
	{

//															Usart_SendString(USART6,USART_DATA_REC_x);
//															Usart_SendString(USART6,"\r\n");
//															Usart_SendString(USART6,USART_DATA_REC_y);
//															Usart_SendString(USART6,"\r\n");
//															Usart_SendString(USART6,USART_DATA_REC_z);
//															Usart_SendString(USART6,"\r\n");
//															Usart_SendString(USART6,USART_DATA_REC_cmd);
//															Usart_SendString(USART6,"\r\n");
		

		if(rec_data_sovle[1]!=atoi(USART_DATA_REC_x))
		{
				flag_eq=1;
		}
	//	rec_data_sovle[0]=atoi(USART_DATA_REC_z);
		if(flag_eq)
		{
		rec_data_sovle[1]=atoi(USART_DATA_REC_x);
		rec_data_sovle[2]=atoi(USART_DATA_REC_y);
		rec_data_sovle[3]=atoi(USART_DATA_REC_cmd);
//			Usart_SendString(USART6,"\r\n");
//    Usart_SendByte(USART6,rec_data_sovle[0]);
//			Usart_SendString(USART6,"\r\n");
//		Usart_SendByte(USART6,rec_data_sovle[1]);
//			Usart_SendString(USART6,"\r\n");
//		Usart_SendByte(USART6,rec_data_sovle[2]);
//			Usart_SendString(USART6,"\r\n");
//		Usart_SendByte(USART6,rec_data_sovle[3]);
//			Usart_SendString(USART6,"\r\n");
		

//	if(rec_data_sovle[3]==1)
//	{
//			set_angle_fun(0.0f, 0.1f, 0.20f);
//			LL_mDelay(700);
//			set_angle_fun(0.0f, 0.2f, 0.15f);
//			LL_mDelay(700);
//			set_angle_fun(0.0f, 0.30f, 0.5f);
//			LL_mDelay(700);
//			set_angle_fun(0.0f, 0.20f, 0.25f);
//			LL_mDelay(700);
//			set_angle_fun(0.0f, 0.10f, 0.20f);
//			LL_mDelay(700);
//			set_angle_fun(0.10f, 0.0f, 0.20f);
//		LL_mDelay(700);
//		ARM_REC(rec_data_sovle);
//		set_angle_fun(rec_data_sovle[0],rec_data_sovle[1],rec_data_sovle[2]);
//		LL_mDelay(700);
//		
//	}
//	else if(rec_data_sovle[3]==0)
//	{
//		LL_mDelay(700);
//		set_angle_fun(0.10f, 0.0f, 0.20f);
//		LL_mDelay(700);
//	}
	
	
}
		
		

	
		
		task_check_flag=0;
flag_eq=0;
	//	LL_USART_EnableIT_RXNE(USART6);
		
	}
	
	}
	
	
	
	
	
	
	

	
	
	
	
	
	
	void WIFI_INIT(void)
	{
		LL_mDelay(8000);
			//Usart_SendString(USART6,"AT+CIPSTART= \"WIFI_TEST\",\"12345678\" \r\n ");		
		LL_mDelay(1000);
		Usart_SendString(USART6,"AT+CIPSTART=\"TCP\",\"192.168.4.1\",8000\r\n");
		LL_mDelay(1000);
	}
	
	void PWM_REALLY(void)
	{
			LL_TIM_OC_SetCompareCH1(TIM3,1500);
			LL_TIM_OC_SetCompareCH2(TIM3,1234);
			LL_TIM_OC_SetCompareCH3(TIM3,1500);
			LL_TIM_OC_SetCompareCH1(TIM3,1500);
	}
	
void BSP_INIT(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */

  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  /* System interrupt init*/
  /* SysTick_IRQn interrupt configuration */
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0));



  /* Configure the system clock */
  SystemClock_Config();
	
	  MX_GPIO_Init();
  
 MX_USART1_UART_Init();
MX_USART2_UART_Init();
	usmart_dev.init(sys_test_time/1000000);
	MX_TIM2_Init();
	//MX_TIM5_Init();
	MX_USART6_UART_Init();
	tim_start();


 WIFI_INIT();
 _pid_init(&v_pid);
 inti_ROB();

 
 	LL_TIM_EnableIT_UPDATE(TIM2);
 LL_TIM_EnableCounter(TIM2);
}





int main(void)
{

BSP_INIT();
	
PWM_REALLY();
LL_mDelay(300);

	
LL_mDelay(500);

  while (1)
  {
	
		//task_check();

//		 LL_mDelay(1000);

//	 LL_mDelay(1000);

  }

}



void test_arm_oc_pwm(int id,int rate)
{
	if(id==1)
			LL_TIM_OC_SetCompareCH1(TIM3,rate);
	else if(id==2)
			LL_TIM_OC_SetCompareCH2(TIM3,rate);
	else if(id==3)
			LL_TIM_OC_SetCompareCH3(TIM3,rate);
	else if(id==4)
			LL_TIM_OC_SetCompareCH4(TIM3,rate);
}




/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_2);
  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_2)
  {
  }
  LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE2);
  LL_RCC_HSE_Enable();

   /* Wait till HSE is ready */
  while(LL_RCC_HSE_IsReady() != 1)
  {

  }
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_25, 168, LL_RCC_PLLP_DIV_2);
  LL_RCC_PLL_Enable();

   /* Wait till PLL is ready */
  while(LL_RCC_PLL_IsReady() != 1)
  {

  }
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_2);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
  {

  }
  LL_Init1msTick(84000000);
  LL_SetSystemCoreClock(84000000);
  LL_RCC_SetTIMPrescaler(LL_RCC_TIM_PRESCALER_TWICE);
	
	
	//__disable_irq();
//	__enable_irq ();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}


#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

