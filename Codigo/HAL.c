/*
 * HAL.c
 *
 *  Created on: 25/10/2024
 *      Author: Juan Diego
 */


#include "../../hvpke18f_led_blinky/drivers/HAL.h"

#include "API.h"
#include "LOW_LEVEL.h"

#include <stdint.h>
#include "fsl_gpio.h"
#include "fsl_common.h"
#include "pin_mux.h"
#include "math.h"


void HAL_GPIO_WritePin(GPIO_Type *base, uint32_t pin, uint8_t output)
{
    uint32_t u32flag = 1;

    if (output == 0U)
    {
        base->PCOR = GPIO_FIT_REG(u32flag << pin);
    }
    else
    {
        base->PSOR = GPIO_FIT_REG(u32flag << pin);
    }
}

void HAL_GPIO_OutputConfig(GPIO_Type *base, uint32_t pin, uint8_t modo)
{

	base->PDDR = GPIO_FIT_REG(modo << pin);
	// 0 entrada / 1 salida
}

void DATA_OUTPUT(void)
{
HAL_GPIO_OutputConfig(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB0,1);
HAL_GPIO_OutputConfig(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB1,1);
HAL_GPIO_OutputConfig(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB2,1);
HAL_GPIO_OutputConfig(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB3,1);
HAL_GPIO_OutputConfig(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB4,1);
HAL_GPIO_OutputConfig(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB5,1);
HAL_GPIO_OutputConfig(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB6,1);
HAL_GPIO_OutputConfig(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB7,1);
}

void DATA_INPUT(void)
{
HAL_GPIO_OutputConfig(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB0,0);
HAL_GPIO_OutputConfig(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB1,0);
HAL_GPIO_OutputConfig(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB2,0);
HAL_GPIO_OutputConfig(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB3,0);
HAL_GPIO_OutputConfig(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB4,0);
HAL_GPIO_OutputConfig(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB5,0);
HAL_GPIO_OutputConfig(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB6,0);
HAL_GPIO_OutputConfig(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB7,0);
}

void HAL_Delay(uint32_t tiempo) // nanosegundos
{
	float x = tiempo/5.952;
	int num = ceil(x);    //redondeo para arriba
	for(int i =0; i <= num; i++)
	{
	asm("nop");
	}
}
