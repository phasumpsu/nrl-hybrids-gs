#define _DEFAULT_SOURCE

#include "mock_hal.h"

// Initialize the "Mock Hardware"
HAL_StatusTypeDef HAL_Init(void)
{
    #ifdef SIM_MODE
        printf("[MOCK] System Initialized.\n");
    #endif
    return HAL_OK; // Always succeed in simulation
}

// Delay: Convert Milliseconds (ms) to Microseconds (us)
void HAL_Delay(uint32_t Delay_ms)
{
    // 1 ms = 1000 us
    usleep(Delay_ms * 1000); 
}

// Write Pin: This is your "Actuator" control (Injectors, Coils)
void HAL_GPIO_WritePin(void* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
    #ifdef SIM_MODE
        if (PinState == GPIO_PIN_SET) {
            printf("[MOCK] Pin %d -> HIGH (ON)\n", GPIO_Pin);
        } else {
            printf("[MOCK] Pin %d -> LOW (OFF)\n", GPIO_Pin);
        }
    #endif
    // In real code: This would toggle a physical register
}

// Read Pin: This is your "Sensor" input (Switches, maybe simulated RPM)
GPIO_PinState HAL_GPIO_ReadPin(void* GPIOx, uint16_t GPIO_Pin)
{
    #ifdef SIM_MODE
        // Simulate a noisy sensor or a switch
        // Let's pretend Pin 13 is a "Crank Signal" that toggles randomly
        if (GPIO_Pin == 13) {
            return (rand() % 2) ? GPIO_PIN_SET : GPIO_PIN_RESET;
        }
        return GPIO_PIN_RESET;
    #endif
    return GPIO_PIN_RESET;
}