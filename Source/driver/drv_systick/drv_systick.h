/**
  ******************************************************************************
  * @file    drv_systick.h
  * @brief   systick driver header file
  * @author  fei long
  * @version V1.0
  * @date    2018-01-07
  *****************************************************************************
  */
#ifndef __DRV_SYSTICK_H_
#define __DRV_SYSTICK_H_


#ifdef __cplusplus
 extern "C" {
#endif
	 
#include "stm32f10x.h"
#include "common_define.h"
	 
extern void Drv_Systick_Init(T_S32 ticks_ms);

#ifdef __cplusplus
}
#endif


#endif  /* __DRV_SYSTICK_H__ */
