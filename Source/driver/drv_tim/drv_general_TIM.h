#ifndef __DRV_GENERAL_TIM_H__
#define __DRV_GENERAL_TIM_H__

#include "stm32f10x.h"
#include "common_define.h"

#define            GENERAL_TIM                   TIM3
#define            GENERAL_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM_CLK               RCC_APB1Periph_TIM3

//PWM f = 72M/{(arr + 1)*(psc + 1)}
#define            GENERAL_TIM_PERIOD            (10-1)
#define            GENERAL_TIM_PSC               (72-1)

#define            GENERAL_TIM_CCR1              5
#define            GENERAL_TIM_CCR2              4
#define            GENERAL_TIM_CCR3              3
#define            GENERAL_TIM_CCR4              2


// TIM3 output compare channel 1
#define            GENERAL_TIM_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH1_PORT          GPIOA
#define            GENERAL_TIM_CH1_PIN           GPIO_Pin_6

// TIM3 output compare channel 2
#define            GENERAL_TIM_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH2_PORT          GPIOA
#define            GENERAL_TIM_CH2_PIN           GPIO_Pin_7

// TIM3 output compare channel 3
#define            GENERAL_TIM_CH3_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH3_PORT          GPIOB
#define            GENERAL_TIM_CH3_PIN           GPIO_Pin_0

// TIM3 output compare channel 4
#define            GENERAL_TIM_CH4_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH4_PORT          GPIOB
#define            GENERAL_TIM_CH4_PIN           GPIO_Pin_1

void Drv_General_TIM_Init(void);

#endif
