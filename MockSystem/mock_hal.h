#ifndef MOCK_HAL_H
#define MOCK_HAL_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // For rand()
#include <unistd.h> // For usleep

// 1. Status Types: Keep these. They just mean "Did the function work?"
typedef enum {
    HAL_OK       = 0x00,
    HAL_ERROR    = 0x01,
    HAL_BUSY     = 0x02,
    HAL_TIMEOUT  = 0x03
} HAL_StatusTypeDef;

// 2. Pin States: Make these explicit. 
// SET = High Voltage (ON), RESET = Low Voltage (OFF)
typedef enum {
    GPIO_PIN_RESET = 0,
    GPIO_PIN_SET   = 1
} GPIO_PinState;

// 3. Function Declarations
HAL_StatusTypeDef HAL_Init(void);
void              HAL_Delay(uint32_t Delay_ms);
void              HAL_GPIO_WritePin(void* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
GPIO_PinState     HAL_GPIO_ReadPin(void* GPIOx, uint16_t GPIO_Pin);

#endif