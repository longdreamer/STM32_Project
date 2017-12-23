/************************************************
* COPYRIGHT 2017 LongFei Technology
*
* NAME: drv_buzzer.h
*
* REVISION HISTORY:
* $Log$
*   Rev 1.0 2017-12-21   long fei
*
* END OF FILE HEADER
************************************************/

#ifndef __DRV_BUZZER_H
#define __DRV_BUZZER_H

#include "stm32f10x.h"

/*define GPIO PORT and GPIO Pins for buzzer*/
#define BUZZER_GPIO_PORT    	GPIOC		                /* GPIO端口 */
#define BUZZER_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO端口时钟 */
#define BUZZER_GPIO_PIN		    GPIO_Pin_0			        /* 连接到SCL时钟线的GPIO */


typedef enum
{
	E_BUZZER_ON,
	E_BUZZER_OFF
}TE_BUZZER_STATE;

/*buzzer driver exported functions*/
extern void Drv_Buzzer_GPIO_Init(void);
extern void Drv_Buzzer_Control(TE_BUZZER_STATE buzzer_state);


#endif 
