/*generate PWM to advance TIM as a input capture*/
#include "drv_general_TIM.h"

/*
*clk_cnt = fck_int/(psc+1)=72M/(PSC+1)
*PWM T = ARR*(1/CLK_CNT) = ARR*(PSC+1)/72M
*Pulse = CCR / (ARR + 1)
*/

/**
  * @brief  General TIM PWM Output GPIO
  * @param  None
  * @retval None
  */
static void general_TIM_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // Output compare channel 1 GPIO init
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH1_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GENERAL_TIM_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH1_PORT, &GPIO_InitStructure);

	// Output compare channel 2 GPIO Init
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH2_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GENERAL_TIM_CH2_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH2_PORT, &GPIO_InitStructure);
	
	// Output compare channel 3 GPIO Init
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH3_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH3_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH3_PORT, &GPIO_InitStructure);
	
	// Output compare channel 4 GPIO Init
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH3_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH3_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH3_PORT, &GPIO_InitStructure);
	
	return;
}


static void general_TIM_Mode_Config(void)
{
  // Enable time clock,CK_INT = 72M
		GENERAL_TIM_APBxClock_FUN(GENERAL_TIM_CLK,ENABLE);
	// Base time config: Peroid = 100k
	   TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// Set ARR
		TIM_TimeBaseStructure.TIM_Period = GENERAL_TIM_PERIOD;	
	// CNT = Fck_int/(PSC + 1)
		TIM_TimeBaseStructure.TIM_Prescaler = GENERAL_TIM_PSC;	
	// No use
		TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;		
	// Counter mode :up
		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		
	// No use of repetition counter
		TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;	
	// Init time base
		TIM_TimeBaseInit(GENERAL_TIM, &TIM_TimeBaseStructure);
		
	//Output compare init
		TIM_OCInitTypeDef  TIM_OCInitStructure;
	// PWM MODE 1
		TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	
		TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
		// polarity : high 
		TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// channel 1
		TIM_OCInitStructure.TIM_Pulse = GENERAL_TIM_CCR1;
		TIM_OC1Init(GENERAL_TIM, &TIM_OCInitStructure);
		TIM_OC1PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
	
	// channel 2
		TIM_OCInitStructure.TIM_Pulse = GENERAL_TIM_CCR2;
		TIM_OC2Init(GENERAL_TIM, &TIM_OCInitStructure);
		TIM_OC2PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
	
	// channel 3
		TIM_OCInitStructure.TIM_Pulse = GENERAL_TIM_CCR3;
		TIM_OC3Init(GENERAL_TIM, &TIM_OCInitStructure);
		TIM_OC3PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
	
	// channel 4
		TIM_OCInitStructure.TIM_Pulse = GENERAL_TIM_CCR4;
		TIM_OC4Init(GENERAL_TIM, &TIM_OCInitStructure);
		TIM_OC4PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
	
		TIM_Cmd(GENERAL_TIM, ENABLE);
	
		return;
}



void Drv_General_TIM_Init(void)
{
	general_TIM_GPIO_Config();
	general_TIM_Mode_Config();
	return;
}
