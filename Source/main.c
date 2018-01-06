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


#define SOFT_DELAY Delay(0x0FFFFF)

void Delay(__IO u32 nCount); 

/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{
	Init_All();
	while (1)
	{

	}
}

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/
