
#ifndef INC_STM32F401xx_GPIO_DRIVER_H
#define INC_STM32F401xx_GPIO_DRIVER_H

#include <stm32f401xx.h>


/**
 * @brief This is a Configuration structure for a GPIO pin
 * 
 */
typedef struct
{
    uint8_t GPIO_PinNumber;
    uint8_t GPIO_PinMode;
    uint8_t GPIO_PinSpeed;
    uint8_t GPIO_PinPuPdControl;
    uint8_t GPIO_PinOPType;
    uint8_t GPIO_PinAltFunMode;
    
} GPIO_PinConfig_t;

/**
 * @brief This is a Handle structure for GPIO pin
 * 
 */

typedef struct
{
    GPIO_RegDef_t *pGPIOx;
    GPIO_PinConfig_t GPIO_PinConfig;
} GPIO_Handle_t;

/**
 * @brief APIs supported by this driver
 *
 */


/**
 * @brief Enables or disables the peripheral clock for the GPIO port.
 *
 * @param pGPIOx Pointer to the GPIO peripheral register structure.
 * @param en     Enable or disable the peripheral clock. 0 = disable, 1 = enable.
 */
void GPIO_PeriClockControl(GPIO_RegDef_t* pGPIOx, uint8_t en);

/**
 * @brief Initializes the GPIO port or pin for use.
 *
 * @param pGPIOHandle Pointer to the GPIO handle structure.
 */
void GPIO_Init(GPIO_Handle_t* pGPIOHandle);

/**
 * @brief De-initializes the GPIO port or pin.
 *
 * @param pGPIOx Pointer to the GPIO peripheral register structure.
 */
void GPIO_DeInit(GPIO_RegDef_t* pGPIOx);

/**
 * @brief Reads the input value of a specific GPIO pin.
 *
 * @param pGPIOx    Pointer to the GPIO peripheral register structure.
 * @param pinNumber GPIO pin number.
 *
 * @return Input value of the specified GPIO pin. 0 = low, 1 = high.
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t* pGPIOx, uint8_t pinNumber);

/**
 * @brief Reads the input values of all GPIO pins in a port.
 *
 * @param pGPIOx Pointer to the GPIO peripheral register structure.
 *
 * @return Input values of all GPIO pins in the specified port. Each bit represents the input value of a GPIO pin.
 */
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t* pGPIOx);

/**
 * @brief Writes a value to a specific GPIO pin.
 *
 * @param pGPIOx    Pointer to the GPIO peripheral register structure.
 * @param pinNumber GPIO pin number.
 * @param value     Value to be written to the specified GPIO pin. 0 = low, 1 = high.
 */
void GPIO_WriteToOutputPin(GPIO_RegDef_t* pGPIOx, uint8_t pinNumber, uint8_t value);

/**
 * @brief Writes values to all GPIO pins in a port.
 *
 * @param pGPIOx Pointer to the GPIO peripheral register structure.
 * @param value  Values to be written to all GPIO pins in the specified port. Each bit represents the value to be written to a GPIO pin.
 */
void GPIO_WriteToOutputPort(GPIO_RegDef_t* pGPIOx, uint16_t value);

/**
 * @brief Toggles the output value of a specific GPIO pin.
 *
 * @param pGPIOx    Pointer to the GPIO peripheral register structure.
 * @param pinNumber GPIO pin number.
 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t* pGPIOx, uint8_t pinNumber);

/**
 * @brief Configures the GPIO interrupt for a specific pin.
 *
 * @param IRQNumber   Interrupt request number.
 * @param IRQPriority Interrupt priority.
 * @param en          Enable or disable the interrupt. 0 = disable, 1 = enable.
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t en);

/**
 * @brief Handles the GPIO interrupt when it occurs.
 *
 * @param pinNumber GPIO pin number.
 */
void GPIO_IRQHandling(uint8_t pinNumber);

#endif // INC_STM32F401xx_GPIO_DRIVER_H
