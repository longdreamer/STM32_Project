/**
  ******************************************************************************
  * @file    drv_spi.c
  * @author  fei long
  * @version V1.0
  * @date    2017-12-24
  * @brief   spi driver for stm32f103
  *****************************************************************************
  */
#include "drv_spi.h"	
#include "drv_gpio_config.h"

/*SPI Flash Config*/
#define SPI_FLASH               SPI1
#define SPI_FLASH_PORT          GPIOA 
#define SPI_FLASH_CS_PIN        GPIO_Pin_4
#define SPI_FLASH_CLK_PIN       GPIO_Pin_5
#define SPI_FLASH_MISO_PIN      GPIO_Pin_6
#define SPI_FLASH_MOSI_PIN      GPIO_Pin_7


void Drv_SPI_Init(TE_SPI_CHANNEL cha)
{
	if(E_SPI_FLASH == cha)
	{
		SPI_InitTypeDef  SPI_InitStructure;
		
		/*SPI GPIO config*/
		Drv_GPIO_OutputInit(SPI_FLASH_PORT,SPI_FLASH_CS_PIN,GPIO_Mode_Out_PP,E_FALSE);//CS_Pin
		Drv_GPIO_InputInit(SPI_FLASH_PORT,SPI_FLASH_CLK_PIN | SPI_FLASH_MOSI_PIN,GPIO_Mode_AF_PP);//config SPI CLK,MOSI
		Drv_GPIO_InputInit(SPI_FLASH_PORT,SPI_FLASH_MISO_PIN,GPIO_Mode_IN_FLOATING);//config SPI MISO
    /*SPI Mode Config*/    
		SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
		SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
		SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
		SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
		SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
		SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
		SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
		SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
		SPI_InitStructure.SPI_CRCPolynomial = 7;
		SPI_Init(SPI_FLASH, &SPI_InitStructure); 
			
		SPI_Cmd(SPI_FLASH, ENABLE); 
	}
	#if 0
	/*if exist other SPI channel*/
	else if()
	{
	
	}
	else
	{
	
	}
	#endif
}

 /**
  * @brief  SPI write bytes
  * @param  TE_SPI_CHANNEL:cha,which channel to be used
  * @param  T_U8 :TxData,data to be written
  * @retval TE_BOOLEAN:E_TRUE if write success,E_FALSE otherwise
  */
TE_BOOLEAN Drv_SPI_WriteByte(TE_SPI_CHANNEL cha, T_U8 TxData)
{
	if(E_SPI_FLASH == cha)
	{
		T_U8 retry = 0;
		while(SPI_I2S_GetFlagStatus(SPI_FLASH, SPI_I2S_FLAG_TXE) == RESET) 
		{
				retry++;
				if(retry>200)
				{
					return E_FALSE;
				}
		}
		SPI_I2S_SendData(SPI_FLASH, TxData); 
		retry=0;
		//wait it finish to fix at release version it cannot work
    while (SPI_I2S_GetFlagStatus(SPI_FLASH, SPI_I2S_FLAG_TXE) == RESET) 
		{
				retry++;
				if(retry>200)
				{
					return E_FALSE;
				}
		}
	}
	return E_TRUE;
}

TE_BOOLEAN Drv_SPI_WaitFinish(TE_SPI_CHANNEL cha)
{

}


void Drv_SPI_Disable(TE_SPI_CHANNEL cha)
{
	if( E_SPI_FLASH == cha)
	{
		SPI_Cmd(SPI_FLASH, DISABLE);
	}
}


void Drv_SPI_Enable(TE_SPI_CHANNEL cha)
{
	if( E_SPI_FLASH == cha)
	{
		SPI_Cmd(SPI_FLASH, ENABLE);
	}
}


void Drv_SPI_ClearReceiveBuff(TE_SPI_CHANNEL cha)
{


}

T_U8 Drv_SPI_ReadWriteByte(TE_SPI_CHANNEL cha, T_U8 TxData)
{

}
