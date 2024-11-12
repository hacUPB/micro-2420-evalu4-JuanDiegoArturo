/*
 * low_level.h
 *
 *  Created on: 25/10/2024
 *      Author: Juan Diego
 */

#ifndef LOW_LEVEL_H_
#define LOW_LEVEL_H_

void lcd_send_command(int b7, int b6, int b5, int b4, int b3, int b2, int b1, int b0);
void lcd_send_data(int b7, int b6, int b5, int b4, int b3, int b2, int b1, int b0);

#endif /* LOW_LEVEL_H_ */
