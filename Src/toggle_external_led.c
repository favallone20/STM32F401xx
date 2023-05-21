
#include <stdint.h>
#include "stm32f401xx_gpio_driver.h"

int main(void)
{
    /*The interal LED is linked with the PA5 pin.
    So we will use this one to blink the intenal led and the extenal one.*/
	GPIO_Handle_t gpio_handle;
	gpio_handle.pGPIOx = GPIOA;
	gpio_handle.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NUMBER_5;
	gpio_handle.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	gpio_handle.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpio_handle.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	gpio_handle.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GPIO_PeriClockControl(gpio_handle.pGPIOx, ENABLE);
	GPIO_Init(&gpio_handle);

    /*The button is linked with the PC13 pin and has a pull up resistor.
    This implies that the default value will be 1 when the button is not pressed,
    while the value read will be 0 when pressed.*/
    GPIO_Handle_t gpio_handle_btn;
	gpio_handle_btn.pGPIOx = GPIOC;
	gpio_handle_btn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NUMBER_13;
	gpio_handle_btn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	gpio_handle_btn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	gpio_handle_btn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GPIO_PeriClockControl(gpio_handle_btn.pGPIOx, ENABLE);
	GPIO_Init(&gpio_handle_btn);

    while (1)
    {
        uint8_t new_value = GPIO_ReadFromInputPin(gpio_handle_btn.pGPIOx, gpio_handle_btn.GPIO_PinConfig.GPIO_PinNumber);
        if (0 == new_value)
        {
            GPIO_ToggleOutputPin(gpio_handle.pGPIOx, gpio_handle.GPIO_PinConfig.GPIO_PinNumber);
            for (int i = 0; i < 500000; i++);
        }
    }
}
