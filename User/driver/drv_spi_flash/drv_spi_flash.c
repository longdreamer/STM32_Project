/**
  ******************************************************************************
  * @file    drv_spi_flash.c
  * @author  fei long
  * @version V1.0
  * @date    2017-12-23
  * @brief   driver for spi flash
  ******************************************************************************
	*/
#include "drv_spi_flash.h"

 /**
  * @brief    SPI_FLASH init 
  * @param    None
  * @retval   None
  */
  void Drv_SPI_Flash_Init(void)
  {
	  SPI_InitTypeDef SPI_InitStructure;
	  GPIO_InitTypeDef GPIO_InitStructure;
	  /*enable SPI1 Clock*/
	  RCC_APB2PeriphClockCmd(SPI_FLASH_CLK,ENABLE);
	  /*enable SPI GPIO clock*/
	  RCC_APB2PeriphClockCmd(SPI_FLASH_GPIO_CLK,ENABLE);
	  
	  /*Config SPI CS Pin*/
	  GPIO_InitStructure.GPIO_Pin = SPI_FLASH_GPIO_CS_PIN;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
      GPIO_Init(SPI_FLASH_GPIO_PORT, &GPIO_InitStructure);
	  
	  /*Config SPI CLK Pin*/
	  GPIO_InitStructure.GPIO_Pin = SPI_FLASH_GPIO_CLK_PIN;
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
      GPIO_Init(SPI_FLASH_GPIO_PORT, &GPIO_InitStructure);

	  /*Config SPI MISO Pin*/	  
      GPIO_InitStructure.GPIO_Pin = SPI_FLASH_GPIO_MISO_PIN;
      GPIO_Init(SPI_FLASH_GPIO_PORT, &GPIO_InitStructure);
	  
	  /*Config SPI MOSI Pin*/
	  GPIO_InitStructure.GPIO_Pin = SPI_FLASH_GPIO_MISO_PIN;
      GPIO_Init(SPI_FLASH_GPIO_PORT, &GPIO_InitStructure);  
  }
  


