/**
   ******************************************************************************
   * @file    drv_exti.h
   * @author  fei long
   * @version V1.0
   * @date    2018-01-06
   * @brief   exti driver header file
   *****************************************************************************
	*/
#ifndef __DRV_EXTI_H_
#define __DRV_EXTI_H_

#include "stm32f10x.h"
#include "common_define.h"

#define KEY1_INT_GPIO_PORT    GPIOA 
#define KEY1_INT_GPIO_PIN     GPIO_Pin_0
#define KEY1_INT_EXTI_LINE    EXTI_Line0
   
#define KEY2_INT_GPIO_PORT    GPIOC
#define KEY2_INT_GPIO_PIN     GPIO_Pin_13

extern void Drv_EXTI_KEY1_Init(void);

#endif
