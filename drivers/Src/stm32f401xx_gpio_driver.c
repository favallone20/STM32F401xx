
#include <stm32f401xx_gpio_driver.h>

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t en)
{
}

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOHandle)
{
}

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber)
{
    return 0;
}

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
    return 0;
}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber, uint8_t value)
{
}

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value)
{
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber)
{
}

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t en)
{
}

void GPIO_IRQHandling(uint8_t pinNumber)
{
}
