/*
 * API.h
 *
 *  Created on: 25/10/2024
 *      Author: Juan Diego
 */

#ifndef API_H_
#define API_H_

#include <stdint.h>

void lcd_init(void);
void Comleft(void);
void Comright(void);


void lcd_clear(void);
void lcd_set_cursor(uint8_t row, uint8_t col);

#endif /* API_H_ */
