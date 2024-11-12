/*
 * low_level.c
 *
 *  Created on: 25/10/2024
 *      Author: Juan Diego
 */

#include "API.h"
#include "HAL.h"
#include "LOW_LEVEL.h"

#include <stdint.h>
#include "pin_mux.h"

//#include "clock_config.h"

/***************************
 * Code
 **************************/

void lcd_send_command(int b7, int b6, int b5, int b4, int b3, int b2, int b1, int b0) {

	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_RW, 0); // RW = 0
	HAL_GPIO_WritePin(BOARD_INITPINS_GPIOC,RS_PIN, 0); // RS = 0

	HAL_Delay(150);	//Tasu

	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 1); // E = 1

    DATA_OUTPUT();
        HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB0, b0);
        HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB1, b1);
        HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB2, b2);
        HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB3, b3);
        HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB4, b4);
        HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB5, b5);
        HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB6, b6);
        HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB7, b7);

    HAL_Delay(210);	//Tdsu

    HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 0); // E = 0
    HAL_Delay(1010);	//Tcycle
}

void lcd_send_data(int b7, int b6, int b5, int b4, int b3, int b2, int b1, int b0) {


	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_RW, 0); // RW = 0
	HAL_GPIO_WritePin(BOARD_INITPINS_GPIOC,RS_PIN, 1); // RS = 1

	HAL_Delay(150);	//Tasu

	HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 1); // E = 1

    DATA_OUTPUT();
        HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB0, b0);
        HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB1, b1);
        HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB2, b2);
        HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB3, b3);
        HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB4, b4);
        HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB5, b5);
        HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB6, b6);
        HAL_GPIO_WritePin(GPIO_DATA_GPIOD,BOARD_INITPINS_LCD_DB7, b7);

     HAL_Delay(210);	//Tdsu

     HAL_GPIO_WritePin(GPIO_DATA_GPIOD,EN_PIN, 0); // E = 0
     HAL_Delay(1010);	//Tcycle

}

