#ifndef __DRV_LED_H
#define	__DRV_LED_H

#include "stm32f10x.h"

/*Define GPIO PORT and GPIO Pin for LEDs*/

/*LED1*/
#define LED1_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define LED1_GPIO_PIN		    GPIO_Pin_0			        /* ���ӵ�SCLʱ���ߵ�GPIO */
/*LED2*/
#define LED2_GPIO_PORT    	GPIOF			              /* GPIO�˿� */
#define LED2_GPIO_CLK 	    RCC_APB2Periph_GPIOF		/* GPIO�˿�ʱ�� */
#define LED2_GPIO_PIN		    GPIO_Pin_7			        /* ���ӵ�SCLʱ���ߵ�GPIO */
/*LED3*/
#define LED3_GPIO_PORT    	GPIOF			              /* GPIO�˿� */
#define LED3_GPIO_CLK 	    RCC_APB2Periph_GPIOF		/* GPIO�˿�ʱ�� */
#define LED3_GPIO_PIN		    GPIO_Pin_8			        /* ���ӵ�SCLʱ���ߵ�GPIO */

typedef enum
{
	E_LED_1,
	E_LED_2,
	E_LED_3,
	E_LED_ALL
}TE_LED_ID;

typedef enum
{
	E_LED_ON,
	E_LED_OFF
}TE_LED_STATE;

/*led driver exported functions*/
extern void Drv_LED_GPIO_Init(void);
extern void Drv_LED_Control(TE_LED_ID led_id,TE_LED_STATE led_state);
extern void Drv_LED_Toggle(TE_LED_ID led_id);

#endif /* __DRV_LED_H */
