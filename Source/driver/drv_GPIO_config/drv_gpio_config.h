/**
  ******************************************************************************
  * @file    drv_gpio_config.c
  * @author  fei long
  * @version V1.0
  * @date    2017-12-24
  * @brief   General use functions for GPIO config
  *****************************************************************************
  */
#ifndef __DRV_GPIO_CONFIG_H
#define __DRV_GPIO_CONFIG_H

#include "stm32f10x.h"
#include "common_define.h"

/*enum definition:IO MODE*/
#if 0
typedef enum
{
	E_IO_MODE_AIN, //Analog In/Out Mode
	E_IO_MODE_IN_FLOATING, //Input and no Pull Mode
	E_IO_MODE_IPD, //Input and Pull Down Mode
	E_IO_MODE_IPU, //Input and Pull Up Mode
	E_IO_MODE_Out_OD, //Output and Open Drain Mode
	E_IO_MODE_Out_OD_PD, //Output and Open Drain Mode and Pull Down Mode
	E_IO_MODE_Out_OD_PU, //Output and Open Drain Mode and Pull Up Mode
	E_IO_MODE_Out_PP, //Output and Push Pull Mode
	E_IO_MODE_Out_PP_PD, //Output and Push Pull Mode and Pull Down Mode
	E_IO_MODE_Out_PP_PU, //Output and Push Pull Mode and Pull Up Mode
	E_IO_MODE_AF_OD, //Alternate function and Open Drain Mode
	E_IO_MODE_AF_OD_PD, //Alternate function and Open Drain Mode and Pull Down Mode
	E_IO_MODE_AF_OD_PU, //Alternate function and Open Drain Mode and Pull Up Mode
	E_IO_MODE_AF_PP, //Alternate function and  Push Pull Mode 
	E_IO_MODE_AF_PP_PD, //Alternate function and  Push Pull Mode and Pull Down Mode
	E_IO_MODE_AF_PP_PU //Alternate function and  Push Pull Mode and Pull Up Mode
}TE_IO_MODE;
#endif

/*declare exported functions*/
extern void Drv_GPIO_InputInit(GPIO_TypeDef* port, T_U16 pin, GPIOMode_TypeDef mode);
extern void Drv_GPIO_OutputInit(GPIO_TypeDef* port, T_U16 pin,GPIOMode_TypeDef mode,TE_BOOLEAN init_value);

#endif
