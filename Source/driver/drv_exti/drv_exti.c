/**
  ******************************************************************************
  * @file    drv_exti.c
  * @author  fei long
  * @version V1.0
  * @date    2018-01-06
  * @brief   
  *****************************************************************************
  */
#include "drv_exti.h"
#include "drv_gpio_config.h"
static void Drv_EXTI_Init(void);
static void Drv_EXTI_NVIC_Init(void);

 /**
  * @brief  KEY1 EXTI init
  * @param  NONE
  * @retval NONE
  */
void Drv_EXTI_KEY1_Init(void)
{
	/*init KEY1 GPIO*/
	Drv_GPIO_InputInit(KEY1_INT_GPIO_PORT,KEY1_INT_GPIO_PIN,GPIO_Mode_IN_FLOATING);
	/*Config NVIC Priority*/
	Drv_EXTI_NVIC_Init();
	/*init EXTI*/
	Drv_EXTI_Init();
}

 /**
  * @brief  config EXIT
  * @param  none
  * @retval none
  */
static void Drv_EXTI_Init(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	/*OPEN clock*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}

 /**
  * @brief  Config NVIC
  * @param  NONE
  * @retval NONE 
  */
static void Drv_EXTI_NVIC_Init(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
