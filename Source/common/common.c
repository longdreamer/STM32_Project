/**
  ******************************************************************************
  * @file    common.c
  * @brief   define some common use interfaces
  * @author  fei long
  * @version V1.0
  * @date    2018-01-07
  *****************************************************************************
  */
  
#include "common.h"
#include <string.h>

#ifdef  USE_FULL_ASSERT
 /**
  * @brief  stm32's lib will use this function to check the error
  * @param  file: the assert failed file;line: the fail expression's line num
  * @retval 
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
    /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    printf("Wrong parameters value: file %s on line %d\r\n", file, line);

    /* Infinite loop */
    while (1)
    {
    }
}
#endif
static TE_TRACE_STATE g_trace_state = E_TRACE_OFF;

void assertFAILED(const char *file, int line)
{
	TS_M_ASSERT m_assert = {0};
	const char *filename = NULL;
	T_U32 str_len = 0;
	filename = strrchr(file,'\\');
	if (file == NULL) return;
	if(NULL != filename)
	{
		filename++;
		str_len = strlen(filename);
		if (str_len >= ASSERT_FILENAME_MAX_LEN) 
			str_len = ASSERT_FILENAME_MAX_LEN;
		m_assert.location = 1;
		m_assert.line = line;
		memcpy(m_assert.file, filename, str_len);
		/*add log function in the future*/
		#if 0
		write_log(m_assert);
		#endif
	}
}

 /**
  * @brief  enter critical and other threads can not enter it
  * @param  NONE
  * @retval NONE
  */
void Enter_Critical(void)
{ 
    __disable_irq();
}
 /**
  * @brief  exit critical, then other threads can enter it
  * @param  NONE
  * @retval NONE
  */
void Exit_Critical(void)
{ 
    __enable_irq();
}

 /**
  * @brief  goto sleep
  * @param 
  * @retval 
  */
void Goto_Sleep(void)
{
    /*goto sleep mode*/
    __wfi();
}

 /**
  * @brief   delay ms millisecond,the time is base on tick and tick is 5ms, 
  *          so suggest ms is Multiples of 5
  * @param   ms: millisecond
  * @retval  none
  */
void Delay_Ms(T_U32 ms)
{
    /*get current time*/
    T_U32 current_ms = kernel_tick_time_current();
    
    M_Assert(ms > 0);
    /*calc the elapse time is reach the specific time, if reach then stop delay*/
    while(kernel_tick_time_elapsed(current_ms) < ms)
    {
        Goto_Sleep();
    }
}
 /**
  * @brief  delay us, it is implementted by use systick.
  * @param  us
  * @retval none
  */
#if 0
void Delay_Us(T_S32 us)
{
#ifdef _WINDOWS
    T_U32 i;
    T_U8  j;
    for (i=0;i<us;i++)
	{
        for (j=0;j<25;j++)
		{
            __no_operation();
        }
    }
#else
	/*Get last systick's value*/
    T_U32 last_value = SysTick->VAL;
	/*now systick's value*/
    T_U32 now_value; 
    /*when reach the counter, delay is complete*/
    T_U32 end_counter = SystemCoreClock/1000000*(T_U32)us;
    T_U32 total_count=0; //used to record how many value past

    while(1)
    {
        //get now value
        now_value = SysTick->VAL;
        //if value changed, record it to total_count
        if (now_value != last_value)
        {
            //Note: it is a decrease timer
            if (now_value<last_value)
            {
                total_count += last_value - now_value;
            }
            else
            {
                total_count +=  SysTick->LOAD - now_value + last_value;
            }
            //update last value
            last_value = now_value;

            //if total count is reach the end count, delay is finish.
            if (total_count>=end_counter)
            {
                break;
            }
        }
    }	
#endif
}
#endif 

void SetTraceState(TE_TRACE_STATE trace_state)
{
		g_trace_state = trace_state;
}

TE_TRACE_STATE GetTraceState(void)
{
		return g_trace_state;
}
