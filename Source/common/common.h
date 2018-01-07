/**
  ******************************************************************************
  * @file    common.h
  * @brief   header file for common.c
  * @author  fei long
  * @version V1.0
  * @date    2018-01-07 
  *****************************************************************************
  */
#ifndef __COMMON_H_
#define __COMMON_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "common_define.h"
#include "kernel_tick_time.h" 
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
	 
//the milliseconds per tick
#define MS_PER_TICK (5)
#define ASSERT_FILENAME_MAX_LEN	  (40)
	 
typedef struct 
{
	T_U8    location;
	T_U32   line;
  T_CHAR  file[ASSERT_FILENAME_MAX_LEN];	
}TS_M_ASSERT;

extern void assertFAILED(const char *file, int line);
extern void Delay_Ms(T_U32 ms);
//extern void Delay_Us(T_U32 us);
extern void Enter_Critical(void);
extern void ExitCritical(void);
extern void Goto_Sleep(void);
/*DEBUG Switch*/	 
//#define DBUG
	 
#ifdef PC_LINT	 
	 extern void exit(T_S32 i);
   #define M_Assert(expression) (expression)?(void)0:exit(0)
#else
   #define M_Assert(expression) (expression)?(void)0:assertFAILED(__FILE__, __LINE__)
#endif

#ifdef __cplusplus
}
#endif

#endif
