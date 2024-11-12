/*
 * API.c
 *
 *  Created on: 25/10/2024
 *      Author: Juan Diego
 */

#include "API.h"
#include "HAL.h"
#include "LOW_LEVEL.h"

#include "pin_mux.h"
#include <stdint.h>
#include "fsl_gpio.h"
#include "fsl_common.h"

void lcd_init(void) {
    // Inicialización
    // P3.2 = 0	--> 0 en RST
    HAL_GPIO_WritePin(BOARD_INITPINS_GPIOE,BOARD_INITPINS_RST, 0);
    HAL_Delay(1000);
    // P3.2 = 1 --> 1 en RST
    HAL_GPIO_WritePin(BOARD_INITPINS_GPIOE,BOARD_INITPINS_RST, 1);
    HAL_Delay(1000);
    // P3.4 = 0 --> 0 en Enable
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 0);
    HAL_Delay(1000);
    // P3.0 = 0 --> 0 en RS
    HAL_GPIO_WritePin(BOARD_INITPINS_GPIOC,RS_PIN, 0);
    HAL_Delay(1000);
    // P3.7 = 0 --> 0 en RW
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_RW, 0);
    HAL_Delay(1000);
    // P3.6 = 0 --> 0 en CS2
    HAL_GPIO_WritePin(BOARD_INITPINS_GPIOE,BOARD_INITPINS_CS1, 0);
    HAL_Delay(1000);
    // P3.1 = 0 --> 0 en CS1
    HAL_GPIO_WritePin(BOARD_INITPINS_GPIOE,BOARD_INITPINS_CS1, 0);
    HAL_Delay(1000);


    Comleft();      // display on
    Comright();     // display on
}

void Comleft(void) {
	lcd_send_command(0,0,1,1,1,1,1,1); //3F
	HAL_Delay(1000);
    //Set P3.6 --> 1 en CS2
    HAL_GPIO_WritePin(BOARD_INITPINS_GPIOE,BOARD_INITPINS_CS2, 1);
    HAL_Delay(1000);
    // P3.0 = 0 --> 0 en RS
    HAL_GPIO_WritePin(BOARD_INITPINS_GPIOC,RS_PIN, 0);
    HAL_Delay(1000);
    // P3.4 = 1 --> 1 en E
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 1);
    HAL_Delay(1000);
    // P3.4 = 0 --> 0 en E
    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 0);
    HAL_Delay(1000);
    //Reset P3.6 --> 0 en CS2
    HAL_GPIO_WritePin(BOARD_INITPINS_GPIOE,BOARD_INITPINS_CS2, 0);
    HAL_Delay(1000);
}

void Comright(void) {
	lcd_send_command(0,0,1,1,1,1,1,1); //3F
	HAL_Delay(1000);
	//Set P3.1 --> 1 en CS1
	HAL_GPIO_WritePin(BOARD_INITPINS_GPIOE,BOARD_INITPINS_CS1, 1);
	HAL_Delay(1000);
    // P3.0 = 0 --> 0 en RS
	HAL_GPIO_WritePin(BOARD_INITPINS_GPIOC,RS_PIN, 0);
	HAL_Delay(1000);
	// P3.4 = 1 --> 1 en E
	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 1);
	HAL_Delay(1000);
	// P3.4 = 0 --> 0 en E
	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 0);
	HAL_Delay(1000);
	//Reset P3.1 --> 0 en CS1
	HAL_GPIO_WritePin(BOARD_INITPINS_GPIOE,BOARD_INITPINS_CS1, 0);
	HAL_Delay(1000);
}

void lcd_clear(void){
	lcd_send_command(0,0,0,0,0,0,0,1);
	HAL_Delay(1000);
}

void lcd_set_cursor(uint8_t col, uint8_t row){
	// Extraer bits de 'col' y 'row'
	uint8_t y3 = (col >> 3) & 1; // Bit 3 de 'col'
	uint8_t y2 = (col >> 2) & 1; // Bit 2 de 'col'
	uint8_t y1 = (col >> 1) & 1; // Bit 1 de 'col'
	uint8_t y0 = col & 1;        // Bit 0 de 'col'

	uint8_t x2 = (row >> 2) & 1; // Bit 2 de 'row'
	uint8_t x1 = (row >> 1) & 1; // Bit 1 de 'row'
	uint8_t x0 = row & 1;        // Bit 0 de 'row'

	lcd_send_command(0, 0, 0, 1, y3, y2, y1, y0); // Bits de 'col' (y3, y2, y1, y0)
	HAL_Delay(100);

	lcd_send_command(0, 0, 0, 1, 1, x2, x1, x0); // Bits de 'row' (x2, x1, x0)
}


