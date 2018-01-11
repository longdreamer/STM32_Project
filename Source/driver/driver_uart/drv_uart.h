/**
  ******************************************************************************
  * @file    DRV_UART.H
  * @brief   Header file for UART
  * @author  fei long
  * @version V1.0
  * @date    2018-01-07
  *****************************************************************************
  */
#ifndef __DRV_UART_H_
#define __DRV_UART_H_

#include "stm32f10x.h"

#ifdef __cplusplus
 extern "C" {
#endif
	 
#include <stdio.h>

/** 
	* Macro define for uart.
	* UASRT1 mount on APB2 Bus which max clock is 72M,others mount on APB1 which max clock is 36M
  */
	
//USART1
#define  USARTx                   USART1
#define  USARTx_CLK                RCC_APB2Periph_USART1
#define  USARTx_APBxClkCmd         RCC_APB2PeriphClockCmd
#define  USARTx_BAUDRATE           115200

// USART GPIO Config
#define  USARTx_GPIO_CLK           (RCC_APB2Periph_GPIOA)
    
#define  USARTx_TX_GPIO_PORT       GPIOA   
#define  USARTx_TX_GPIO_PIN        GPIO_Pin_9
#define  USARTx_RX_GPIO_PORT       GPIOA
#define  USARTx_RX_GPIO_PIN        GPIO_Pin_10

#define  USARTx_IRQ                USART1_IRQn
#define  USARTx_IRQHandler         USART1_IRQHandler


//USART2
//#define  USARTx                   USART2
//#define  USARTx_CLK                RCC_APB1Periph_USART2
//#define  USARTx_APBxClkCmd         RCC_APB1PeriphClockCmd
//#define  USARTx_BAUDRATE           115200

// USART GPIO Config
//#define  USARTx_GPIO_CLK           (RCC_APB2Periph_GPIOA)
//#define  USARTx_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
//    
//#define  USARTx_TX_GPIO_PORT       GPIOA   
//#define  USARTx_TX_GPIO_PIN        GPIO_Pin_2
//#define  USARTx_RX_GPIO_PORT       GPIOA
//#define  USARTx_RX_GPIO_PIN        GPIO_Pin_3

//#define  USARTx_IRQ                USART2_IRQn
//#define  USARTx_IRQHandler         USART2_IRQHandler

// USART3
//#define  USARTx                   USART3
//#define  USARTx_CLK                RCC_APB1Periph_USART3
//#define  USARTx_APBxClkCmd         RCC_APB1PeriphClockCmd
//#define  USARTx_BAUDRATE           115200

//// USART GPIO Config
//#define  USARTx_GPIO_CLK           (RCC_APB2Periph_GPIOB)
//#define  USARTx_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
//    
//#define  USARTx_TX_GPIO_PORT       GPIOB   
//#define  USARTx_TX_GPIO_PIN        GPIO_Pin_10
//#define  USARTx_RX_GPIO_PORT       GPIOB
//#define  USARTx_RX_GPIO_PIN        GPIO_Pin_11

//#define  USARTx_IRQ                USART3_IRQn
//#define  USARTx_IRQHandler         USART3_IRQHandler

// UART4
//#define  USARTx                   UART4
//#define  USARTx_CLK                RCC_APB1Periph_UART4
//#define  USARTx_APBxClkCmd         RCC_APB1PeriphClockCmd
//#define  USARTx_BAUDRATE           115200

//// USART GPIO Config
//#define  USARTx_GPIO_CLK           (RCC_APB1Periph_GPIOC)
//#define  USARTx_GPIO_APBxClkCmd    RCC_APB1PeriphClockCmd
//    
//#define  USARTx_TX_GPIO_PORT       GPIOC   
//#define  USARTx_TX_GPIO_PIN        GPIO_Pin_10
//#define  USARTx_RX_GPIO_PORT       GPIOC
//#define  USARTx_RX_GPIO_PIN        GPIO_Pin_11

//#define  USARTx_IRQ                UART4_IRQn
//#define  USARTx_IRQHandler         UART4_IRQHandler


// UART5
//#define  USARTx                   UART5
//#define  USARTx_CLK                RCC_APB1Periph_UART5
//#define  USARTx_APBxClkCmd         RCC_APB1PeriphClockCmd
//#define  USARTx_BAUDRATE           115200

// USART GPIO Config
//#define  USARTx_GPIO_CLK           (RCC_APB1Periph_GPIOC|RCC_APB1Periph_GPIOD)
//#define  USARTx_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
//    
//#define  USARTx_TX_GPIO_PORT       GPIOC   
//#define  USARTx_TX_GPIO_PIN        GPIO_Pin_12
//#define  USARTx_RX_GPIO_PORT       GPIOD
//#define  USARTx_RX_GPIO_PIN        GPIO_Pin_2

//#define  USARTx_IRQ                UART5_IRQn
//#define  USARTx_IRQHandler         UART5_IRQHandler


extern void Drv_USAR_Init(void);
extern void Drv_Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);
extern void Drv_Usart_SendString( USART_TypeDef * pUSARTx, char *str);
	 
	 
#ifdef __cplusplus
}
#endif

#endif /**END OF FILE*/
