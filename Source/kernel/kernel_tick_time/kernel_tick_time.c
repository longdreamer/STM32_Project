/**
  ******************************************************************************
  * @file    kernel_tick_time.c
  * @brief   
  * @author  fei long
  * @version V1.0
  * @date    2018-01-07
  *****************************************************************************
  */
#include "kernel_tick_time.h"
#include "common.h"
/*time elapse from power on to now*/
static T_U32 tick_time_ms_elapse = 0;
//static TE_BOOLEAN tick_time_is_tick_handled = E_FALSE;
//static TE_BOOLEAN tick_time_is_tick_changed = E_FALSE;
 /**
  * @brief  call this function when one tick elapsed,only called by the timer interrupt
  * @param 
  * @retval 
  */
void kernel_tick_time_one_tick(void)
{
	//add one tick
	tick_time_ms_elapse += MS_PER_TICK;
	//set tick as not handled
	//tick_time_is_tick_handled = E_FALSE;
	//set tick changed
    //tick_time_is_tick_changed = E_TRUE;
}
 /**
  * @brief  calculate the elapsed time from old time to now
  * @param  old_time_ms
  * @retval the elapsed time
  */
T_U32 kernel_tick_time_elapsed(T_U32 old_time_ms)
{
    if(tick_time_ms_elapse >= old_time_ms)
    {
        return tick_time_ms_elapse - old_time_ms;
    }
    else
    {
        return MAX_T_U32 - old_time_ms + tick_time_ms_elapse + 1;
    }
}
 /**
  * @brief  calculate the elapsed time from old_time_ms to new_time_ms, unit: ms
  * @param  new_time_ms,old_time_ms
  * @retval the elapsed time from old_time_ms to new_time_ms
  */
T_U32 kernel_tick_time_diff( T_U32 new_time_ms, T_U32 old_time_ms)
{
    if(new_time_ms >= old_time_ms)
    {
        return new_time_ms - old_time_ms;
    }
    else
    {
        return MAX_T_U32 - old_time_ms + new_time_ms + 1;
    }
}
 /**
  * @brief  get current time,it will recount when it reach MAX_T_U32 millisecond
  * @param 
  * @retval 
  */
T_U32 kernel_tick_time_current(void)
{
    return tick_time_ms_elapse;
}
