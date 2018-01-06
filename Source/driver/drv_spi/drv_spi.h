/**
   ******************************************************************************
   * @file    drv_spi.h
   * @author  fei long
   * @version V1.0
   * @date    2017-12-26
   * @brief   spi driver header file
   *****************************************************************************
	*/
#ifndef __DRV_SPI_H_
#define __DRV_SPI_H_

#include "stm32f10x.h"
#include "common_define.h"
/*enum definition*/
typedef enum 
{
	E_SPI_FLASH,
	/*if exist other spi channel,add below*/
	
	/*don't add any member below*/
	E_SPI_MAX
}TE_SPI_CHANNEL;

/*declare exported functions*/
extern void        Drv_SPI_Init(TE_SPI_CHANNEL cha);
extern TE_BOOLEAN  Drv_SPI_WriteByte(TE_SPI_CHANNEL cha, T_U8 TxData);
extern TE_BOOLEAN  Drv_SPI_WaitFinish(TE_SPI_CHANNEL cha);
extern void        Drv_SPI_Disable(TE_SPI_CHANNEL cha);
extern void        Drv_SPI_Enable(TE_SPI_CHANNEL cha);
extern T_U8        Drv_SPI_ReadWriteByte(TE_SPI_CHANNEL cha, T_U8 TxData);

#endif
