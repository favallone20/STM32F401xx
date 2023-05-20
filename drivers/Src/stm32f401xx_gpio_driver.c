
#include <stm32f401xx_gpio_driver.h>

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t en)
{
    if (en == ENABLE)
    {
        if (GPIOA == pGPIOx)
            GPIOA_PCLOCK_EN();
        else if (GPIOB == pGPIOx)
            GPIOB_PCLOCK_EN();
        else if (GPIOC == pGPIOx)
            GPIOC_PCLOCK_EN();
        else if (GPIOD == pGPIOx)
            GPIOD_PCLOCK_EN();
        else if (GPIOE == pGPIOx)
            GPIOE_PCLOCK_EN();
        else if (GPIOH == pGPIOx)
            GPIOH_PCLOCK_EN();
    }
    else
    {
        if (GPIOA == pGPIOx)
            GPIOA_PCLOCK_DI();
        else if (GPIOB == pGPIOx)
            GPIOB_PCLOCK_DI();
        else if (GPIOC == pGPIOx)
            GPIOC_PCLOCK_DI();
        else if (GPIOD == pGPIOx)
            GPIOD_PCLOCK_DI();
        else if (GPIOE == pGPIOx)
            GPIOE_PCLOCK_DI();
        else if (GPIOH == pGPIOx)
            GPIOH_PCLOCK_DI();
    }
}

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
    /* In this function we have to set the registers associated to the pGPIOHandle*/
    
    /*1. configure the mode of gpio pin*/
    if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG){
        /*Each pin takes 2 bit fields -> for this reason 2* */
        pGPIOHandle->pGPIOx->MODER &= ~(0x3 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //clearing

        pGPIOHandle->pGPIOx->MODER |=
            pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    }
    else{
        // in case of interrupt mode
    }
    /*2. configure the speed of gpio pin*/
    pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //clearing
    pGPIOHandle->pGPIOx->OSPEEDR |=
        pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    
    /*3. configure the pull up / pull down of gpio pin*/
    pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); // clearing
    pGPIOHandle->pGPIOx->PUPDR |=
        pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

    /*4. configure op type*/
    pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->OTYPER |= pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

    /*5. configure the alternate function of gpio pin*/
     if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
     {
        if (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber <= 7){
            pGPIOHandle->pGPIOx->AFRL &= ~(0xF * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); // clearing
            pGPIOHandle->pGPIOx->AFRL |=
                pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
         } else
         {
            pGPIOHandle->pGPIOx->AFRH &= ~(0xF * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8)); // clearing
            pGPIOHandle->pGPIOx->AFRH |=
                pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8));
         }
     }
}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
     if (GPIOA == pGPIOx)
         GPIOA_REG_RESET();
     else if (GPIOB == pGPIOx)
         GPIOB_REG_RESET();
     else if (GPIOC == pGPIOx)
         GPIOC_REG_RESET();
     else if (GPIOD == pGPIOx)
         GPIOD_REG_RESET();
     else if (GPIOE == pGPIOx)
         GPIOE_REG_RESET();
     else if (GPIOH == pGPIOx)
         GPIOH_REG_RESET();
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
