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
	Init_All();
	while (1)
	{

	}
}

void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/
