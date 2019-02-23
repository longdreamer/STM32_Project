/**
  ******************************************************************************
  * @file    drv_uart.c
  * @brief   driver for UARTx in STM32F103ZET6,redirect printf() in C library to UART.
  * @author  fei long
  * @version V1.0
  * @date    2018-01-08
  *****************************************************************************
  */
#include "drv_uart.h"
#include "drv_gpio_config.h"
 /**
  * @brief  config NVIC for UART interrupt
  * @param 
  * @retval 
  */
	
static void Drv_UART_NVIC_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /*Select NVIC priority group */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  
  /*Set UARTx as interrupt source */
  NVIC_InitStructure.NVIC_IRQChannel = USARTx_IRQ;
  /*Set Preemption Priority*/
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /*Set SubPriority*/
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  /*Enable interrupt*/
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  /*Init NVIC*/
  NVIC_Init(&NVIC_InitStructure);
}

void Drv_UART_Init(void)
{
	USART_InitTypeDef USART_InitStructure;
	/**
	 *Tx and Rx GPIO config
	 */
	
	/*Config Tx GPIO*/
	Drv_GPIO_OutputInit(USARTx_TX_GPIO_PORT,USARTx_TX_GPIO_PIN,GPIO_Mode_AF_PP,E_FALSE);
	/*Config Rx GPIO*/
	Drv_GPIO_InputInit(USARTx_RX_GPIO_PORT,USARTx_RX_GPIO_PIN,GPIO_Mode_IN_FLOATING);
	
	/**
	  *UARTx config
	  */
	
	/*Enable UARTx clock*/
	USARTx_APBxClkCmd(USARTx_CLK,ENABLE);
	/*Set baudrate: 115200*/
	USART_InitStructure.USART_BaudRate = USARTx_BAUDRATE;
	/*Set word length: 8 bit*/
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	/*Set stop bit: 1 bit*/
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	/*Set parity: No parity*/
	USART_InitStructure.USART_Parity = USART_Parity_No;
	/*Set hardware flow control: none*/
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	/*Set Work Mode:send and receive mode*/
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USARTx, &USART_InitStructure);
	
	/*Config NVIC*/
	Drv_UART_NVIC_Config();
	/*Enable UART interrupt*/
	USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);	
	/*Enable UART*/
	USART_Cmd(USARTx, ENABLE);
}
 /**
  * @brief  Send a byte
  * @param 
  * @retval 
  */
void Drv_UART_SendByte(USART_TypeDef * pUSARTx, uint8_t ch)
{
	/* Send a byte data to USART */
	USART_SendData(pUSARTx,ch);
		
	/* Wait for send data register is empty */
	while(USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);	
}

void Drv_UART_SendString(USART_TypeDef * pUSARTx, char *str)
{
	unsigned int k=0;
  do 
  {
      Drv_UART_SendByte( pUSARTx, *(str + k) );
      k++;
  } while(*(str + k)!='\0');
  
  /*wait for send ready */
  while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TC)==RESET);
}

 /**
  * @brief  redirect printf() to UART
  * @param 
  * @retval 
  */
int fputc(int ch, FILE *f)
{
		/* send a byte to UART*/
		USART_SendData(USARTx, (uint8_t) ch);
		
		/* Wait for send ready */
		while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);		
	
		return (ch);
}
