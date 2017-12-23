#ifndef __DRV_SPI_FLASH

/**
 *SPI FLASH GPIO PORT definition
 */

/*Define SPIx*/
#define SPIx_FLASH                      SPI1 
#define SPI_FLASH_CLK                   RCC_APB2Periph_SPI1

/*Define SPI GPIO Port*/
#define SPI_FLASH_GPIO_CLK              RCC_APB2Periph_GPIOA
#define SPI_FLASH_GPIO_PORT             GPIOA

#define SPI_FLASH_GPIO_CS_PIN           GPIO_Pin_4
#define SPI_FLASH_GPIO_CLK_PIN          GPIO_Pin_5
#define SPI_FLASH_GPIO_MISO_PIN         GPIO_Pin_6
#define SPI_FLASH_GPIO_MOSI_PIN         GPIO_Pin_7


/**
 *Declare exported functions
*/
exterm void Drv_SPI_Flash_Init(void);
extern void Drv_SPI_Flash_WriteByte(void);
extern void Drv_SPI_Flash_ReadByre(void);

#endif