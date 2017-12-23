/**
  ****************************************
  * @file    drv_led.c
  * @author  fei long
  * @version V1.0
  * @date    2017-12-21
  * @brief   led driver
	***************************************/
  
#include "drv_led.h"   


 /**
  * @brief  LED GPIO initial
  * @param  None
  * @retval None
  */
void Drv_LED_GPIO_Init(void)
{		
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( LED1_GPIO_CLK | LED2_GPIO_CLK | LED3_GPIO_CLK, ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIO*/
		GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);	
		
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;

		/*调用库函数，初始化GPIO*/
		GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);
		
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LED3_GPIO_PIN;

		/*调用库函数，初始化GPIOF*/
		GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStructure);

		/* 关闭所有led灯	*/
		GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
		
		/* 关闭所有led灯	*/
		GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);	 
    
    /* 关闭所有led灯	*/
		GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);
}


 /**
  * @brief  turn off led1:set bit to 1 is off,set 0 is on
  * @param  None
  * @retval None
  */
static void Drv_LED1_On(void)
{
	GPIO_ResetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
}


 /**
  * @brief  turn off led2
  * @param  None
  * @retval None
  */
static void Drv_LED2_On(void)
{
	GPIO_ResetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
}


 /**
  * @brief  turn off led3
  * @param  None
  * @retval None
  */
static void Drv_LED3_On(void)
{
	GPIO_ResetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);
}



 /**
* @brief  turn off led1:set bit to 1 is off,set 0 is on
  * @param  None
  * @retval None
  */
static void Drv_LED1_Off(void)
{
	GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
}


 /**
  * @brief  turn off led2
  * @param  None
  * @retval None
  */
static void Drv_LED2_Off(void)
{
	GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
}


 /**
  * @brief  turn off led3
  * @param  None
  * @retval None
  */
static void Drv_LED3_Off(void)
{
	GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);
}


 /**
  * @brief  turn on all LEDs
  * @param  None
  * @retval None
  */
static void Drv_LED_All_On(void)
{
	Drv_LED1_On();
	Drv_LED2_On();
	Drv_LED3_On();
}

 /**
  * @brief  turn off all LEDs
  * @param  None
  * @retval None
  */
static void Drv_LED_All_Off(void)
{
	Drv_LED1_Off();
	Drv_LED2_Off();
	Drv_LED3_Off();
}
/**
**@brief  control led status
**@param  led_id,led_state
**@retval None
*/
void Drv_LED_Control(TE_LED_ID led_id,TE_LED_STATE led_state)
{
	if(E_LED_ON == led_state)
	{
		switch(led_id)
		{
			case E_LED_1:
				Drv_LED1_On();
				break;
				
			case E_LED_2:
				Drv_LED2_On();
				break;
				
			case E_LED_3:
				Drv_LED3_On();
				break;
				
			case E_LED_ALL:
				Drv_LED_All_On();
				break;
				
			default:
				break;
		}
	}
	else
	{
		switch(led_id)
		{
			case E_LED_1:
				Drv_LED1_Off();
				break;
				
			case E_LED_2:
				Drv_LED2_Off();
				break;
				
			case E_LED_3:
				Drv_LED3_Off();
				break;
				
			case E_LED_ALL:
				Drv_LED_All_Off();
				break;
				
			default:
				break;
		}
	}
}

/*********************************************END OF FILE**********************/
