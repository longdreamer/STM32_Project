#ifndef __DRV_ADVANCE_TIM_H__
#define __DRV_ADVANCE_TIM_H__

#include "stm32f10x.h"
#include "common_define.h"
/********************advanced TIM1 or TIM8************/
#define ADVANCE_TIM_PWM
#define ADVANCE_TIM1 

#ifdef  ADVANCE_TIM1 // use TIM1

	#define            ADVANCE_TIM                   TIM1
	#define            ADVANCE_TIM_APBxClock_FUN     RCC_APB2PeriphClockCmd
	#define            ADVANCE_TIM_CLK               RCC_APB2Periph_TIM1
	#define            ADVANCE_TIM_Period            (1000 - 1)
	#define            ADVANCE_TIM_Prescaler         (72 - 1)
	//TIMER IRQ
	#define            ADVANCE_TIM_UP_IRQ            TIM1_UP_IRQn
	#define            ADVANCE_TIM__UP_IRQHandler    TIM1_UP_IRQHandler
	//PWM compare capture IRQ
	#define            ADVANCE_TIM_CC_IRQ            TIM1_CC_IRQn
	#define            ADVANCE_TIM_CC_IRQHandler     TIM1_CC_IRQHandler
	
	#define            ADVANCE_TIM_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
	#define            ADVANCE_TIM_CH1_PORT          GPIOA
	#define            ADVANCE_TIM_CH1_PIN           GPIO_Pin_8

	#define            ADVANCE_TIM_IC1PWM_CHANNEL    TIM_Channel_1
	#define            ADVANCE_TIM_IC2PWM_CHANNEL    TIM_Channel_2

#else  // Use TIM8
	#define            ADVANCE_TIM                   TIM8
	#define            ADVANCE_TIM_APBxClock_FUN     RCC_APB2PeriphClockCmd
	#define            ADVANCE_TIM_CLK               RCC_APB2Periph_TIM8
	#define            ADVANCE_TIM_Period            (1000 - 1)
	#define            ADVANCE_TIM_Prescaler         (72 - 1)
	#define            ADVANCE_TIM_UP_IRQ            TIM8_UP_IRQn
	#define            ADVANCE_TIM_UP_IRQHandler     TIM8_UP_IRQHandler
	//PWM compare capture IRQ
	#define            ADVANCE_TIM_CC_IRQ            TIM8_CC_IRQn
	#define            ADVANCE_TIM_CC_IRQHandler     TIM8_CC_IRQHandler
	
	#define            ADVANCE_TIM_CH1_GPIO_CLK      RCC_APB2Periph_GPIOC
	#define            ADVANCE_TIM_CH1_PORT          GPIOC
	#define            ADVANCE_TIM_CH1_PIN           GPIO_Pin_6
	
	#define            ADVANCE_TIM_IC1PWM_CHANNEL    TIM_Channel_1
	#define            ADVANCE_TIM_IC2PWM_CHANNEL    TIM_Channel_2
	
#endif

void Drv_Advance_TIM_PWM_Init(void);
void Drv_Advance_TIM_timer_Init(void); 

#endif
