
#ifndef INC_STM32F401xx_GPIO_DRIVER_H
#define INC_STM32F401xx_GPIO_DRIVER_H

#include <stm32f401xx.h>

// @GPIO_PIN_NUMBERS
/* GPIO pin numbers*/
#define GPIO_PIN_NUMBER_0 0
#define GPIO_PIN_NUMBER_1 1
#define GPIO_PIN_NUMBER_2 2
#define GPIO_PIN_NUMBER_3 3
#define GPIO_PIN_NUMBER_4 4
#define GPIO_PIN_NUMBER_5 5
#define GPIO_PIN_NUMBER_6 6
#define GPIO_PIN_NUMBER_7 7
#define GPIO_PIN_NUMBER_8 8
#define GPIO_PIN_NUMBER_9 9
#define GPIO_PIN_NUMBER_10 10
#define GPIO_PIN_NUMBER_11 11
#define GPIO_PIN_NUMBER_12 12
#define GPIO_PIN_NUMBER_13 13
#define GPIO_PIN_NUMBER_14 14
#define GPIO_PIN_NUMBER_15 15

// @GPIO_PIN_MODES
/*GPIO modes*/
#define GPIO_MODE_IN 0
#define GPIO_MODE_OUT 1
#define GPIO_MODE_ALTFN 2
#define GPIO_MODE_ANALOG 3
#define GPIO_MODE_IT_FT 4 //GPIO in input mode with interrupt on the falling edge trigger
#define GPIO_MODE_IT_RT 5 //GPIO in input mode with interrupt on the rising edge trigger
#define GPIO_MODE_IT_RFT 6 //GPIO in input mode with interrupt on the rising edge trigger

// @GPIO_OUTPUT_TYPE
/*GPIO port output type*/
#define GPIO_OP_TYPE_PP 0
#define GPIO_OP_TYPE_OD 1

// @GPIO_OUTPUT_SPEED
/*GPIO port output speed*/
#define GPIO_SPEED_LOW 0
#define GPIO_SPEED_MEDIUM 1
#define GPIO_SPEED_HIGH 2
#define GPIO_SPEED_VERY_HIGH 3

// @GPIO_PIN_PULLUP_PULLDOWN
/*GPIO port pull-up/pull-down*/
#define GPIO_NO_PUPD 0
#define GPIO_PIN_PU 1
#define GPIO_PIN_PD 2

/**
 * @brief This is a Configuration structure for a GPIO pin
 * 
 */
typedef struct
{
    uint8_t GPIO_PinNumber;
    uint8_t GPIO_PinMode; //possible values from @GPIO_PIN_MODES
    uint8_t GPIO_PinSpeed; // possible values from @GPIO_OUTPUT_SPEED
    uint8_t GPIO_PinPuPdControl; // possible values from @GPIO_PIN_PULLUP_PULLDOWN
    uint8_t GPIO_PinOPType; // possible values from @GPIO_OUTPUT_TYPE
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
