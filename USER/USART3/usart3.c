#include "usart3.h"
#include "USART2.h"

extern int task_check_flag;

int task_check_flag2=0;
void MX_USART6_UART_Init(void)
{

  /* USER CODE BEGIN USART6_Init 0 */

  /* USER CODE END USART6_Init 0 */

  LL_USART_InitTypeDef USART_InitStruct = {0};

  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* Peripheral clock enable */
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_USART6);

  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
  /**USART6 GPIO Configuration
  PA11   ------> USART6_TX
  PA12   ------> USART6_RX
  */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_11|LL_GPIO_PIN_12;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_8;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USART6 interrupt Init */
  NVIC_SetPriority(USART6_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),1, 0));
  NVIC_EnableIRQ(USART6_IRQn);

  /* USER CODE BEGIN USART6_Init 1 */

  /* USER CODE END USART6_Init 1 */
  USART_InitStruct.BaudRate = 115200;
  USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
  USART_InitStruct.StopBits = LL_USART_STOPBITS_1;
  USART_InitStruct.Parity = LL_USART_PARITY_NONE;
  USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
  USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
  USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;
  LL_USART_Init(USART6, &USART_InitStruct);
  LL_USART_ConfigAsyncMode(USART6);
  LL_USART_Enable(USART6);
  /* USER CODE BEGIN USART6_Init 2 */

  /* USER CODE BEGIN USART1_Init 2 */
	LL_USART_EnableIT_RXNE(USART6);
	//LL_USART_EnableIT_IDLE(USART6);
	//
	//LL_USART_EnableIT_ERROR(USART6);
  /* USER CODE END USART6_Init 2 */

}

/* USER CODE BEGIN 1 */






char data[20];
uint8_t Rflag = 0;
uint8_t Rnum = 0;






u8 USART_RX_BUF2[USART_REC_LEN2];
u16 USART_RX_STA2=0; 
static u8 count=0;
u8 count_with_fl=0;
u8 flag=0;
/* USER CODE BEGIN 1 */
//void USART6_IRQHandler(void)
//{
//u8 Res;


//	if(LL_USART_IsActiveFlag_RXNE(USART6) != RESET)
//	{
//			Res=LL_USART_ReceiveData8(USART6);

//		if(Res=='C')flag++;
//			if(flag)USART_RX_BUF2[count++]=Res;
//		
//		if(USART_RX_BUF2[count-1]=='F')
//		{
//			
//			flag=0;
//			USART_RX_BUF2[count]='\0';
//			task_check_flag=1;
//			count=0;

//		}
//		if(count>=3)
//		{
//		count=0;
//			flag=0;
//		}			
//		LL_USART_ClearFlag_RXNE(USART6);
//	}

//LL_USART_ReceiveData8(USART6);
//}





char USART_DATA_REC_x[5]={'\0'};
char USART_DATA_REC_y[5]={'\0'};
char USART_DATA_REC_z[5]={'\0'};
char USART_DATA_REC_cmd[5]={'\0'};

u8 flag_rec=0;
u8 flag_count=0;
u8 flag_count_2=0;
u8 flag_count_3=0;
u8 break_flag=0;
void USART6_IRQHandler(void)
{
		u8 Res;
	
		if(LL_USART_IsActiveFlag_RXNE(USART6) != RESET)
		{
			
			
			Res=LL_USART_ReceiveData8(USART6);
		

			
			if(flag_rec==2)
			{
				if(flag_count_2==0)
				{
					if(((Res!='F')&&(flag_count<5))&&(Res!='x'))
					{
							USART_DATA_REC_x[flag_count]=Res;
							flag_count++;
					}
					else if(Res=='x')
					{
							USART_DATA_REC_x[flag_count]='\0';
							flag_count_2=1;
							flag_count=0;
					}
					else if  (((Res=='F')&&(flag_count_2!=1))
						    ||	((Res=='F')&&(flag_count_2==1)
														   &&(flag_count==0)))
					{
							flag_rec=0;
							flag_count=0;
							flag_count_2=0;
					}
					
				}
					
					
					
					 if((flag_count>4))
					{
							flag_rec=0;
							flag_count=0;
						flag_count_2=0;
					}
					
					
					if(flag_count_2==1)
					{
								if(Res!='x')
						{
							USART_DATA_REC_y[flag_count]=Res;
							flag_count++;
						}
						
						if(Res=='F')
						{
							USART_DATA_REC_y[flag_count-1]='\0';
							task_check_flag2=1;
							
							flag_rec=0;
							flag_count=0;
						flag_count_2=0;
						}
				
					}
	
			}
			else if(flag_rec==3)
			{
					USART_DATA_REC_z[flag_count]=Res;
					flag_count++;
				if(flag_count>4)
				{
					memset(USART_DATA_REC_z,'\0',sizeof(USART_DATA_REC_z));
					flag_rec=0;
					flag_count=0;
					break_flag=1;
				}
				else if((Res=='F')&&(flag_count==1))
				{
					flag_rec=0;
					flag_count=0;
					memset(USART_DATA_REC_z,'\0',sizeof(USART_DATA_REC_z));
					break_flag=1;
				}
				else if(Res=='F')
				{
					USART_DATA_REC_z[flag_count-1]='\0';
				  flag_rec=0;
					flag_count=0;
					//task_check_flag2=1;
				}
				
				
				
			}

			
			
			
			
			
			
			
			
			
			
			if(flag_rec==1)
			{
					if(Res=='M')
					{
							flag_rec=2;
						
					}
					else if(Res=='Z')
					{
							flag_rec=3;
					}
					else
					{
							flag_rec=4;
						
					}	
					
				flag_count=0;					
			}
			
			
			
						 if(flag_rec==4)
			{
					if(Res!='F')
					{
						USART_DATA_REC_cmd[flag_count]=Res;
						flag_count++;
					}
					else if((Res=='F')||(flag_count>4))
					{
					USART_DATA_REC_cmd[flag_count]='\0';
					flag_rec=0;
					flag_count=0;
						task_check_flag=1;
						
					}
				
			}
			
			
			
			if(Res=='C')
			{
				flag_rec=1;
				flag_count=0;
				flag_count_2=0;
					
			}
			
			
			Res='\0';
			
			
			
				LL_USART_ClearFlag_RXNE(USART6);
		}
		
		Res=LL_USART_ReceiveData8(USART6);
		if(Res=='\0')
		{
			task_check_flag=0;
		}
}




/* USER CODE END 1 */

