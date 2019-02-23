#include "drv_basic_TIM.h"

static void Basic_TIM_NVIC_Config()
{
    NVIC_InitTypeDef NVIC_InitStructure; 
    // set interrupt group 0
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);		
		// set interrupt souce
    NVIC_InitStructure.NVIC_IRQChannel = BASIC_TIM_IRQ ;	
		// set main priority
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
	  // set sub priority
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
	  return;
}

static void Basic_TIM_Mode_Config()
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    BASIC_TIM_APBxClock_FUN(BASIC_TIM_CLK, ENABLE);
    TIM_TimeBaseStructure.TIM_Period = BASIC_TIM_Period;	
    TIM_TimeBaseStructure.TIM_Prescaler= BASIC_TIM_Prescaler;
    TIM_TimeBaseInit(BASIC_TIM, &TIM_TimeBaseStructure);
	
    TIM_ClearFlag(BASIC_TIM, TIM_FLAG_Update);
    TIM_ITConfig(BASIC_TIM,TIM_IT_Update,ENABLE);
    TIM_Cmd(BASIC_TIM, ENABLE);	
	  return;
}


void Drv_Basic_TIM_Init(void)
{
	Basic_TIM_NVIC_Config();
	Basic_TIM_Mode_Config();
	return;
}
