/**
  ******************************************************************************
  * @file    main.c
  * @author  fei long
  * @version V1.0
  * @date    2017-12-21
  * @brief   
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:���� F103-�Ե� STM32 ������
	* оƬ�ͺţ�STM32F103ZET6
  * 
  ******************************************************************************
  */ 

#include "init.h"


#define SOFT_DELAY Delay(0x0FFFFF)

void Delay(__IO u32 nCount); 

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	

	
	while (1)
	{
			Drv_LED_Control(E_LED_ALL,E_LED_ON);
		  Drv_Buzzer_Control(E_BUZZER_ON);
			SOFT_DELAY;
			Drv_LED_Control(E_LED_ALL,E_LED_OFF);
			Drv_Buzzer_Control(E_BUZZER_OFF);
			SOFT_DELAY;
	}
}

void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/
