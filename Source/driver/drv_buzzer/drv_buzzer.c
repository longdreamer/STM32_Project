/**
  ******************************************************************************
  * @file    drv_buzzer.c
  * @author  fei long
  * @version V1.0
  * @date    2017-12-21
  * @brief   buzzer driver
  ******************************************************************************/

#include "drv_buzzer.h"

 /**
  * @brief  Buzzer GPIO init
  * @param  None
  * @retval None
  */
void Drv_Buzzer_GPIO_Init(void)
{
	/*define GPIO_InitTypeDef structure*/
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*Turn on buzzer GPIO Port Clock*/
	RCC_APB2PeriphClockCmd(BUZZER_GPIO_CLK,ENABLE); 
	
	/*select buzzer control GPIO*/
	GPIO_InitStructure.GPIO_Pin = BUZZER_GPIO_PIN;
	
	/*set GPIO Mode:Push Pull Mode*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	
	/*set GPIO rate:50MHz */   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	/*Init GPIO*/
	GPIO_Init(BUZZER_GPIO_PORT, &GPIO_InitStructure);			 
    
  /*turn off buzzer*/
	GPIO_ResetBits(BUZZER_GPIO_PORT, BUZZER_GPIO_PIN);	
}

static void Drv_Buzzer_On(void)
{
	GPIO_SetBits(BUZZER_GPIO_PORT, BUZZER_GPIO_PIN);	
}

static void Drv_Buzzer_Off(void)
{
	GPIO_ResetBits(BUZZER_GPIO_PORT, BUZZER_GPIO_PIN);	
}

void Drv_Buzzer_Control(TE_BUZZER_STATE state)
{
	if(E_BUZZER_ON == state)
	{
		Drv_Buzzer_On();
	}
	else
	{
		Drv_Buzzer_Off();
	}
}



/*********************************************END OF FILE**********************/
