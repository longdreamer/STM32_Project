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
  * 实验平台:秉火 F103-霸道 STM32 开发板
  * 芯片型号：STM32F103ZET6
  * 
  ******************************************************************************
  */ 

#include "init.h"
#include "app_test_case.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


void vTaskLed1( void * pvParameters )
{
	while(1)
	{
		Drv_LED_Toggle(E_LED_1);			 
		vTaskDelay( 500 );
	}
	
}


void vTaskLed2( void * pvParameters )
{
	while(1)
	{
		Drv_LED_Toggle(E_LED_2);			 
		vTaskDelay( 500 );
	}
	
}


void vTaskLed3( void * pvParameters )
{
	while(1)
	{
		Drv_LED_Toggle(E_LED_3);			 
		vTaskDelay( 500 );
	}
}


void vTaskStart( void * pvParameters )
{	
	NVIC_SetPriorityGrouping(NVIC_PriorityGroup_4);
	Init_All();
	xTaskCreate( vTaskLed1, "Task Led1", 512, NULL, 1, NULL );
	xTaskCreate( vTaskLed2, "Task Led2", 512, NULL, 1, NULL );
	xTaskCreate( vTaskLed3, "Task Led3", 512, NULL, 1, NULL );
	
	vTaskDelete( NULL );
}


/**
  * @brief 
  * @param 
  * @retval
  */
int main ( void )
{	
	xTaskCreate( vTaskStart, "Task Start", 512, NULL, 1, NULL );
  vTaskStartScheduler();
}

/*********************************************END OF FILE**********************/
