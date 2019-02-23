#include "drv_advance_TIM.h"

#ifndef ADVANCE_TIM_PWM
//=============================1.定时功能应用======================//
static void Drv_timer_TIM_NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure; 
    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);		
		
    NVIC_InitStructure.NVIC_IRQChannel = ADVANCE_TIM_UP_IRQ;	
		
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
	  
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
	  return;
}


static void Drv_timer_TIM_Mode_Config(void)
{
	  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;		
		//enable clk CK_INT = 72M
    ADVANCE_TIM_APBxClock_FUN(ADVANCE_TIM_CLK, ENABLE);	
		//ARR = TIM_period + 1
    TIM_TimeBaseStructure.TIM_Period = ADVANCE_TIM_Period;
	  //set psc
    TIM_TimeBaseStructure.TIM_Prescaler= ADVANCE_TIM_Prescaler;	
		
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
		//up mode
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 		
	  //repetition counter : no use
		TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	  //init TIMER
    TIM_TimeBaseInit(ADVANCE_TIM, &TIM_TimeBaseStructure);
	
	  //Clear IT Flag.
    TIM_ClearFlag(ADVANCE_TIM, TIM_FLAG_Update);
		//enable timer counter interrupt
    TIM_ITConfig(ADVANCE_TIM,TIM_IT_Update,ENABLE);
		//enable timer counter
    TIM_Cmd(ADVANCE_TIM, ENABLE);
		return;
}

void Drv_Advance_TIM_timer_Init(void)
{
	Drv_timer_TIM_NVIC_Config();
	Drv_timer_TIM_Mode_Config();	
	return;
}
//==============================end 定时应用===========================//
#else

//=====================2.PWM输入捕获应用=============================//

static void advance_TIM_PWM_NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure; 
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);		
    NVIC_InitStructure.NVIC_IRQChannel = ADVANCE_TIM_CC_IRQ; 	
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
		return;
}


static void advance_TIM_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(ADVANCE_TIM_CH1_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  ADVANCE_TIM_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  
  GPIO_Init(ADVANCE_TIM_CH1_PORT, &GPIO_InitStructure);	
	return;
}


static void advance_TIM_Mode_Config(void)
{
  // CK_INT=72M
	ADVANCE_TIM_APBxClock_FUN(ADVANCE_TIM_CLK,ENABLE);

	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// 
	TIM_TimeBaseStructure.TIM_Period = ADVANCE_TIM_Period;	
	// 
	TIM_TimeBaseStructure.TIM_Prescaler = ADVANCE_TIM_Prescaler;	
	// 
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;		
	// 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		
	// 
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;	
	// 
	TIM_TimeBaseInit(ADVANCE_TIM, &TIM_TimeBaseStructure);

	
	TIM_ICInitTypeDef  TIM_ICInitStructure;
  TIM_ICInitStructure.TIM_Channel = ADVANCE_TIM_IC1PWM_CHANNEL;
  TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;

  TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
  TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
  TIM_ICInitStructure.TIM_ICFilter = 0x0;
  TIM_PWMIConfig(ADVANCE_TIM, &TIM_ICInitStructure);
  TIM_SelectInputTrigger(ADVANCE_TIM, TIM_TS_TI1FP1);		
  TIM_SelectSlaveMode(ADVANCE_TIM, TIM_SlaveMode_Reset);
  TIM_SelectMasterSlaveMode(ADVANCE_TIM,TIM_MasterSlaveMode_Enable); 

  TIM_ITConfig(ADVANCE_TIM, TIM_IT_CC1, ENABLE);	
	TIM_ClearITPendingBit(ADVANCE_TIM, TIM_IT_CC1);
	
  TIM_Cmd(ADVANCE_TIM, ENABLE);
	return;
}

void Drv_Advance_TIM_PWM_Init(void)
{
	advance_TIM_PWM_NVIC_Config();
	advance_TIM_GPIO_Config();
	advance_TIM_Mode_Config();
	return;
}

//=====================end PWM输入捕获应用=============================//
#endif
