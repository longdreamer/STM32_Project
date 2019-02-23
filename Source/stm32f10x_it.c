/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTI
  
  AL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"

/*add by user for add interrupt handler*/

#include "drv_led.h"
#include "drv_exti.h"
#include "kernel_tick_time.h"
#include "drv_uart.h"
#include "drv_basic_tim.h"
#include "drv_general_TIM.h"
#include "drv_advance_TIM.h"
#include "common.h"
/*end of user add*/

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
		
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
//void SVC_Handler(void)
//{
//}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
//void PendSV_Handler(void)
//{
//}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */

/*implement by user*/
//void SysTick_Handler(void)
//{
	//kernel_tick_time_one_tick();
//}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 
/*implement by user*/
void EXTI0_IRQHandler(void)
{
	while(EXTI_GetITStatus(KEY1_INT_EXTI_LINE) != RESET) 
	{
		Drv_LED_Toggle(E_LED_1);
		//USE KEY1 to control trace state
		if(E_TRACE_OFF == GetTraceState())
		{
				SetTraceState(E_TRACE_ON);
		}
		else
		{
				SetTraceState(E_TRACE_OFF);
		}
		EXTI_ClearITPendingBit(KEY1_INT_EXTI_LINE);     
	}  
	return;
}

void USARTx_IRQHandler(void)
{
	T_U8 Temp;
	if (USART_GetITStatus(USARTx,USART_IT_RXNE)!=RESET) 
	{
		Temp = USART_ReceiveData(USARTx);
		USART_SendData(USARTx,Temp);
	}
	return;
}

/**
  * @brief  This function handles TIM2 interrupt request.
  * @param  None
  * @retval None
  */
extern volatile uint32_t basic_time;
void  BASIC_TIM_IRQHandler (void)
{
	if ( TIM_GetITStatus( BASIC_TIM, TIM_IT_Update) != RESET ) 
	{	
		basic_time++;
		TIM_ClearITPendingBit(BASIC_TIM , TIM_FLAG_Update);  		 
	}	
	return;	
}

/**
  * @brief  This function handles TIM2 interrupt request.
  * @param  None
  * @retval None
  */
extern volatile uint32_t advance_time;
void  ADVANCE_TIM_UP_IRQHandler (void)
{
	if ( TIM_GetITStatus(ADVANCE_TIM, TIM_IT_Update) != RESET ) 
	{	
		advance_time++;
		TIM_ClearITPendingBit(ADVANCE_TIM , TIM_FLAG_Update);  		 
	}	
	return;	
}
/*
**Advance timer for CC .
*/
__IO uint16_t IC2Value = 0;
__IO uint16_t IC1Value = 0;
__IO float    DutyCycle = 0;
__IO float    Frequency = 0;
void ADVANCE_TIM_CC_IRQHandler(void)
{
  TIM_ClearITPendingBit(ADVANCE_TIM, TIM_IT_CC1);
  //get input capture value
  IC1Value = TIM_GetCapture1(ADVANCE_TIM);
  IC2Value = TIM_GetCapture2(ADVANCE_TIM);
	
	if (IC1Value != 0)
  {
    DutyCycle = (float)((IC2Value+1) * 100) / (IC1Value+1);
    Frequency = (72000000/(ADVANCE_TIM_Prescaler + 1))/(float)(IC1Value+1);
		printf("Pulse:%0.2f%%   Freq:%0.2fHz\n",DutyCycle,Frequency);
  }
  else
  {
    DutyCycle = 0;
    Frequency = 0;
		printf("reset");
  }
}




/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
