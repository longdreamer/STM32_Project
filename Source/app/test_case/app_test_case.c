#include "app_test_case.h"


//UART test case£ºPress KEY1,It will send strings to PC
void app_test_case_UART(void)
{
	Trace("This is a uart communication case.\n");
	Delay_Ms(300);
	return;
}

//Basic TIM test case:led1 toggle 1s per time
volatile T_U32 basic_time = 0; // ms 
void app_test_case_basic_TIM(void)
{
	if (basic_time == 1000) /* 1000 * 1 ms = 1s*/
    {
		basic_time = 0;
		/* LED1 toggle */      
		Drv_LED_Toggle(E_LED_1); 
    } 
	return;
}
//advanced timer test case:led2 toggle 1s per time
volatile T_U32 advance_time = 0; // ms 
void app_test_case_advance_time_TIM(void)
{
	if (advance_time == 1000) /* 1000 * 1 ms = 1s*/
    {
		advance_time = 0;
		/* LED1 toggle */      
		Drv_LED_Toggle(E_LED_2); 
    } 
	return;
}
