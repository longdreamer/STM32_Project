#ifndef __DRV_SPI_FLASH_H
#define __DRV_SPI_FLASH_H

#include "stm32f10x.h"
#include "drv_spi.h"
/**
 *Declare exported functions
*/
extern void Drv_SPI_Flash_Init(void);
extern void Drv_SPI_Flash_WriteByte(void);
extern void Drv_SPI_Flash_ReadByre(void);

#endif
/***************************END OF FILE*******************************/
