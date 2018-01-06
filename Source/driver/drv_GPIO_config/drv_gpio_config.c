/**
  ******************************************************************************
  * @file    drv_gpio_config.c
  * @author  fei long
  * @version V1.0
  * @date    2017-12-24
  * @brief   
  *****************************************************************************
  */
#include "drv_gpio_config.h"
	

/*related port with RCC, used to get RCC from GPIO*/
typedef struct
{
    GPIO_TypeDef* port;
    T_U32 RCC_Periph;
}TS_GPIO_PORT_AND_RCC;

/*GPIO Port<->RCC Map:used to get RCC from GPIO*/
const static TS_GPIO_PORT_AND_RCC g_gpio_rcc_map[] = 
{
    {GPIOA, RCC_APB2Periph_GPIOA},
    {GPIOB, RCC_APB2Periph_GPIOB},
    {GPIOC, RCC_APB2Periph_GPIOC},
    {GPIOD, RCC_APB2Periph_GPIOD},
    {GPIOE, RCC_APB2Periph_GPIOE},
    {GPIOF, RCC_APB2Periph_GPIOF},
    {GPIOG, RCC_APB2Periph_GPIOG}   
};
 /**
  * @brief  GPIO general init
  * @param  GPIO_TypeDef: port, select which GPIO prot to be initialize
  * @param  T_U16       : pin,  select which GPIO Pin to be used
  * @param  TE_IO_MODE  : mode, select GPIO input/output mode
  * @param  TE_BOOLEAN  : init_valie,when it is output mode, this is the init value of output. other mode it is not use
  * @retval None
  */
static void Drv_GPIO_Init(GPIO_TypeDef* port, T_U16 pin, GPIOMode_TypeDef mode, TE_BOOLEAN init_value)
{
		GPIO_InitTypeDef  GPIO_InitStructure;
    T_U32 rcc_periph = 0;
    T_U32 i = 0; 

    /*Select the RCC clock according to related GPIO Port*/
    for(i=0; i<sizeof(g_gpio_rcc_map)/sizeof(g_gpio_rcc_map[0]); i++)
    {
        if(port == g_gpio_rcc_map[i].port)
        {
            rcc_periph = g_gpio_rcc_map[i].RCC_Periph;
            break;
        }
    }

    /*Enable GPIO clock*/
    RCC_APB2PeriphClockCmd(rcc_periph, ENABLE);	

    /*init GPIO*/
    GPIO_InitStructure.GPIO_Pin = pin;
    GPIO_InitStructure.GPIO_Mode = mode; 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//use this speed for common if no special
    GPIO_Init(port, &GPIO_InitStructure);

    /*set the initial value*/
    if((mode == GPIO_Mode_Out_OD) || (mode == GPIO_Mode_Out_PP))
    {
        if(init_value)
        {
            GPIO_SetBits(port, pin);	
        }
        else
        {
            GPIO_ResetBits(port, pin);	
        }
    }
}
 /**
  * @brief  GPIO input init with mode
  * @param  GPIO_TypeDef: port, select which GPIO prot to be initialize
  * @param  T_U16       : pin,  select which GPIO Pin to be used
  * @param  GPIOMode_TypeDef : mode,use which input mode
  * @retval None
  */
void Drv_GPIO_InputInit(GPIO_TypeDef* port, T_U16 pin, GPIOMode_TypeDef mode)
{
    Drv_GPIO_Init(port, pin, mode, E_FALSE);
}

 /**
  * @brief  GPIO output init
  * @param  GPIO_TypeDef: port, select which GPIO prot to be initialize
  * @param  T_U16       : pin,  select which GPIO Pin to be used
  * @param  TE_IO_MODE  : mode, select GPIO input/output mode
  * @param  TE_BOOLEAN  : init_valie,when it is output mode, this is the init value of output. other mode it is not use
  * @retval None
  */
void Drv_GPIO_OutputInit(GPIO_TypeDef* port, T_U16 pin,GPIOMode_TypeDef mode,TE_BOOLEAN init_value)
{
		Drv_GPIO_Init(port, pin, mode, init_value);
}

/***************************END OF FILE*******************************/
