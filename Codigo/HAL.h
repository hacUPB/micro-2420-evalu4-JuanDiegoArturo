#ifndef HAL_H
#define HAL_H


#include "fsl_common.h"
#include "pin_mux.h"

void HAL_Delay(uint32_t tiempo);
void HAL_GPIO_WritePin(GPIO_Type *base, uint32_t pin, uint8_t output);
void HAL_GPIO_OutputConfig(GPIO_Type *base, uint32_t pin, uint8_t modo);

void DATA_OUTPUT(void);
void DATA_INPUT(void);

#endif // HAL_H
