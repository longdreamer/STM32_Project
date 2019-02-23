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
#ifndef _DEBUG
	#define Trace(...)  if(GetTraceState()){printf(__VA_ARGS__);}
	#define TraceT(...) if(GetTraceState()){printf("%.3f: ", CtlTickTimeCurrent()/1000.0);printf(__VA_ARGS__);}
	#define TraceL(...) if(GetTraceState()){printf("%.3f: ", CtlTickTimeCurrent()/1000.0);printf(__VA_ARGS__);printf("\n");}	
#else 
	//simple trace
	#define Trace printf  
	//trace with current time
	#define TraceT printf("%.3f: ", CtlTickTimeCurrent()/1000.0);printf
	//trace with current time and auto add line break
	#define TraceL(...) printf("%.3f: ", CtlTickTimeCurrent()/1000.0);printf(__VA_ARGS__);printf("\n");
#endif

typedef enum
{
	E_TRACE_OFF,
	E_TRACE_ON
}TE_TRACE_STATE;

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
extern void Exit_Critical(void);
extern void Goto_Sleep(void);
extern void SetTraceState(TE_TRACE_STATE trace_state);
extern TE_TRACE_STATE GetTraceState(void);
	 
#ifdef PC_LINT	 
   extern void exit(T_S32 i);
   #define M_Assert(expression) (expression)?(void)0:exit(0)
#else
   #define M_Assert(expression) (expression)?(void)0:assertFAILED(__FILE__, __LINE__)
#endif

#ifdef __cplusplus
}
#endif

#endif /**END OF FILE*/
