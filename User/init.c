/**
  ****************************************
  * @file    init.c
  * @author  fei long
  * @version V1.0
  * @date    2017-12-23
  * @brief   init module
	***************************************/
#include "init.h"

/*private function definiton*/
static void Init_Driver(void);
static void Init_Kernel(void);
static void Init_App(void);

/**
  * @brief  init all module of this project
  * @param  None  
  * @retval None
  */
void Init_All(void)
{
	Init_Driver();
	Init_Kernel();
	Init_App();
}
/**
  * @brief  init drivers used in this project
  * @param  None  
  * @retval None
  */
static void Init_Driver(void)
{
	Drv_LED_GPIO_Init();
	Drv_Buzzer_GPIO_Init();
}

/**
  * @brief  init kernel used in this project
  * @param  None  
  * @retval None
  */
static void Init_Kernel(void)
{
	;
}

/**
  * @brief  init app used in this project
  * @param  None  
  * @retval None
  */
static void Init_App(void)
{
	;
}