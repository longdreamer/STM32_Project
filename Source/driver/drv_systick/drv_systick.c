/**
  ******************************************************************************
  * @file    drv_systick.c
  * @brief   systick driver
  * @author  fei long
  * @version V1.0
  * @date    2018-01-10
  * @brief   
  *****************************************************************************
  */
#include "drv_systick.h"
	
#define SYSTICK_MS_DIV    (1000)        //1 ms 
#define SYSTICK_US_DIV    (1000000)     //1 us 
 /**
  * @brief  systick initialize and start systick
  * @param  T_S32 : ms_per_tick,ms per tick
  * @retval NONE
  */
void Drv_Systick_Init(T_S32 ms_per_tick)
{
	T_U32 RELOAD;
	//SYSCLK = AHB = 72M, SystemCoreClock/1000 means 1 ms interrupt
	RELOAD = SystemCoreClock/SYSTICK_MS_DIV *(T_U32)ms_per_tick;
	if(SysTick_Config(RELOAD))
	{
		while(1);
	}
}
