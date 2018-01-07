/**
  ******************************************************************************
  * @file    kernel_tick_time.h
  * @brief   declare some function interfaces of systick time module
  * @author  fei long
  * @version V1.0
  * @date    2018-01-07  
  *****************************************************************************
  */
#ifndef __KERNEL_TICK_TIME_H__
#define __KERNEL_TICK_TIME_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "common_define.h"
	 
extern void  kernel_tick_time_one_tick(void);
extern T_U32 kernel_tick_time_elapsed(T_U32 old_time_ms);
extern T_U32 kernel_tick_time_diff( T_U32 new_time_ms, T_U32 old_time_ms);
extern T_U32 kernel_tick_time_current(void);	 

#ifdef __cplusplus
}
#endif


#endif 
