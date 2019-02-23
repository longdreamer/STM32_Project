#ifndef __DRV_BASIC_TIM_H__
#define __DRV_BASIC_TIM_H__
#include "stm32f10x.h"
#include "common_define.h"
/********************Basic Timer Definition，TIM6 or TIM7************/
#define BASIC_TIM6 // Define TIM6

#ifdef  BASIC_TIM6 // Use TIM6
	#define            BASIC_TIM                   TIM6
	#define            BASIC_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
	#define            BASIC_TIM_CLK               RCC_APB1Periph_TIM6
	#define            BASIC_TIM_Period            (1000-1)
	#define            BASIC_TIM_Prescaler         71
	#define            BASIC_TIM_IRQ               TIM6_IRQn
	#define            BASIC_TIM_IRQHandler        TIM6_IRQHandler

#else  // Use TIM7
	#define            BASIC_TIM                   TIM7
	#define            BASIC_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
	#define            BASIC_TIM_CLK               RCC_APB1Periph_TIM7
	#define            BASIC_TIM_Period            1000-1
	#define            BASIC_TIM_Prescaler         71
	#define            BASIC_TIM_IRQ               TIM7_IRQn
	#define            BASIC_TIM_IRQHandler        TIM7_IRQHandler

#endif
/**************************函数声明********************************/

extern void Drv_Basic_TIM_Init(void);

#endif
