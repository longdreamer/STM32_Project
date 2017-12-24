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
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( LED1_GPIO_CLK | LED2_GPIO_CLK | LED3_GPIO_CLK, ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);	
		
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);
		
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LED3_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIOF*/
		GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStructure);

		/* �ر�����led��	*/
		GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
		
		/* �ر�����led��	*/
		GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);	 
    
    /* �ر�����led��	*/
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
