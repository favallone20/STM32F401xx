#ifndef INC_STM32F401XX_H
#define INC_STM32F401XX_H

#include <stdint.h>

//-----------------------------------BASE ADDRESSES REGION---------------------------------------------
/**
 * base addresses of Flash and SRAM memories
 *
 */

#define FLASH_BASEADDR 0x08000000U
#define SRAM1_BASEADDR 0x20000000U
#define SRAM SRAM1_BASEADDR
#define ROM 0x1FFF0000U

/**
 * AHBx and APBx Peripheral base addresses
 *
 */

#define PERIPH_BASEADDR 0x40000000U
#define APB1PERIPH_BASEADDR PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR 0x40010000U
#define AHB1PERIPH_BASEADDR 0x40020000U
#define AHB2PERIPH_BASEADDR 0x50000000U

/**
 * Base addresses of peripherals which are hanging on
 * AHB1 bus
 *
 */

#define GPIOA_BASEADDR (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOH_BASEADDR (AHB1PERIPH_BASEADDR + 0x1C00)
#define CRC_BASEADDR (AHB1PERIPH_BASEADDR + 0x3000)
#define RCC_BASEADDR (AHB1PERIPH_BASEADDR + 0x3800)
#define FLASH_INTERFACE_REGISTER_BASEADDR (AHB1PERIPH_BASEADDR + 0x3C00)
#define DMA1_BASEADDR (AHB1PERIPH_BASEADDR + 0x6000)
#define DMA2_BASEADDR (AHB1PERIPH_BASEADDR + 0x6400)

/**
 * Base addresses of peripherals which are hanging on
 * APB1 bus
 *
 */

#define TIM2_BASEADDR (APB1PERIPH_BASEADDR + 0x0000)
#define TIM3_BASEADDR (APB1PERIPH_BASEADDR + 0x0400)
#define TIM4_BASEADDR (APB1PERIPH_BASEADDR + 0x0800)
#define TIM5_BASEADDR (APB1PERIPH_BASEADDR + 0x0C00)
#define RTC_BKP_REGISTERS_BASEADDR (APB1PERIPH_BASEADDR + 0x2800)
#define WWDG_BASEADDR (APB1PERIPH_BASEADDR + 0x2C00)
#define IWDG_BASEADDR (APB1PERIPH_BASEADDR + 0x3000)
#define I2S2EXT_BASEADDR (APB1PERIPH_BASEADDR + 0x3400)
#define SPI2_I2S2_BASEADDR (APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_I2S3_BASEADDR (APB1PERIPH_BASEADDR + 0x3C00)
#define I2S3EXT_BASEADDR (APB1PERIPH_BASEADDR + 0x4000)
#define USART2_BASEADDR (APB1PERIPH_BASEADDR + 0x4400)
#define I2C1_BASEADDR (APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR (APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR (APB1PERIPH_BASEADDR + 0x5C00)
#define PWR_BASEADDR (APB1PERIPH_BASEADDR + 0x7000)

/**
 * Base addresses of peripherals which are hanging on
 * APB2 bus
 *
 */

#define TIM1_BASEADDR (APB2PERIPH_BASEADDR + 0x0000)
#define USART1_BASEADDR (APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR (APB2PERIPH_BASEADDR + 0x1400)
#define ADC1_BASEADDR (APB2PERIPH_BASEADDR + 0x2000)
#define SDIO_BASEADDR (APB2PERIPH_BASEADDR + 0x2C00)
#define SPI1_BASEADDR (APB2PERIPH_BASEADDR + 0x3000)
#define SPI4_BASEADDR (APB2PERIPH_BASEADDR + 0x3400)
#define SYSCFG_BASEADDR (APB2PERIPH_BASEADDR + 0x3800)
#define EXTI_BASEADDR (APB2PERIPH_BASEADDR + 0x3C00)
#define TIM9_BASEADDR (APB2PERIPH_BASEADDR + 0x4000)
#define TIM10_BASEADDR (APB2PERIPH_BASEADDR + 0x4400)
#define TIM11_BASEADDR (APB2PERIPH_BASEADDR + 0x4800)

//--------------------------------------------------------------------------------


//-----------------------------------STRUCTURES REGION---------------------------------------------
/**
 * @brief Structure representing the GPIO port register map
 */

typedef struct
{
    volatile uint32_t MODER;   /*!< GPIO port mode register */
    volatile uint32_t OTYPER;  /*!< GPIO port output type register */
    volatile uint32_t OSPEEDR; /*!< GPIO port output speed register */
    volatile uint32_t PUPDR;   /*!< GPIO port pull-up/pull-down register */
    volatile uint32_t ODR;     /*!< GPIO port output data register */
    volatile uint32_t BSRR;    /*!< GPIO port bit set/reset register */
    volatile uint32_t LCKR;    /*!< GPIO port configuration lock register */
    volatile uint32_t AFRL;    /*!< GPIO alternate function low register */
    volatile uint32_t AFRH;    /*!< GPIO alternate function high register */
} GPIO_RegDef_t;

/**
 * @brief Pointer definitions for GPIO peripherals.
 *
 * These macros define pointers to the GPIO peripherals for the STM32 microcontroller.
 * (Peripheral base addresses typecasted to xxx_RegDef_t)
 */
#define GPIOA ((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOH ((GPIO_RegDef_t *)GPIOH_BASEADDR)

/**

    @brief Reset and Clock Control Register Definition structure
    This structure maps the RCC peripheral memory in the device's memory.
    **/
typedef struct
{
    volatile uint32_t CR;            // RCC clock control register, Address offset: 0x00
    volatile uint32_t PLLCFGR;       // RCC PLL configuration register, Address offset: 0x04
    volatile uint32_t CFGR;          // RCC clock configuration register, Address offset: 0x08
    volatile uint32_t CIR;           // RCC clock interrupt register, Address offset: 0x0C
    volatile uint32_t AHB1RSTR;      // RCC AHB1 peripheral reset register, Address offset: 0x10
    volatile uint32_t AHB2RSTR;      // RCC AHB2 peripheral reset register, Address offset: 0x14
    volatile uint32_t RESERVED0;     // Reserved, 0x18
    volatile uint32_t RESERVED1;     // Reserved, 0x1C
    volatile uint32_t APB1RSTR;      // RCC APB1 peripheral reset register, Address offset: 0x20
    volatile uint32_t APB2RSTR;      // RCC APB2 peripheral reset register, Address offset: 0x24
    volatile uint32_t RESERVED2[2];  // Reserved, 0x28-0x2C
    volatile uint32_t AHB1ENR;       // RCC AHB1 peripheral clock enable register, Address offset: 0x30
    volatile uint32_t AHB2ENR;       // RCC AHB2 peripheral clock enable register, Address offset: 0x34
    volatile uint32_t RESERVED3[2];  // Reserved, 0x38-0x3C
    volatile uint32_t APB1ENR;       // RCC APB1 peripheral clock enable register, Address offset: 0x40
    volatile uint32_t APB2ENR;       // RCC APB2 peripheral clock enable register, Address offset: 0x44
    volatile uint32_t RESERVED4[2];  // Reserved, 0x48-0x4C
    volatile uint32_t AHB1LPENR;     // RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50
    volatile uint32_t AHB2LPENR;     // RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54
    volatile uint32_t RESERVED5[2];  // Reserved, 0x58-0x5C
    volatile uint32_t APB1LPENR;     // RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60
    volatile uint32_t APB2LPENR;     // RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64
    volatile uint32_t RESERVED6[2];  // Reserved, 0x68-0x6C
    volatile uint32_t BDCR;          // RCC Backup domain control register, Address offset: 0x70
    volatile uint32_t CSR;           // RCC clock control & status register, Address offset: 0x74
    volatile uint32_t RESERVED7[2];  // Reserved, 0x78-0x7C
    volatile uint32_t SSCGR;         // RCC spread spectrum clock generation register, Address offset: 0x80
    volatile uint32_t PLLI2SCFGR;    // RCC PLLI2S configuration register, Address offset: 0x84
    volatile uint32_t RESERVED14;    // Reserverd, 0x88
    volatile uint32_t DCKCFGR;    // RCC Dedicated Clock Configuration Register, Address offset: 0x8C

} RCC_RegDef_t;

/**
 * @brief Pointer definitions for RCC peripheral.
 *
 * These macros define pointer to the RCC peripheral for the STM32 microcontroller.
 * (Peripheral base addresses typecasted to xxx_RegDef_t)
 */
#define RCC ((RCC_RegDef_t *)RCC_BASEADDR)

//--------------------------------------------------------------------------------


//-----------------------------------CLOCK ENABLE REGION---------------------------------------------

/**
 * @brief Clock Enable Macros for GPIOx peripherals
 * 
 */
#define GPIOA_PCLOCK_EN() (RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLOCK_EN() (RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLOCK_EN() (RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLOCK_EN() (RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLOCK_EN() (RCC->AHB1ENR |= (1<<4))
#define GPIOH_PCLOCK_EN() (RCC->AHB1ENR |= (1<<7))

//--------------------------------------------------------------------------------

//-----------------------------------CLOCK DISABLE REGION---------------------------------------------

/**
 * @brief Clock Disable Macros for GPIOx peripherals
 * 
 */
#define GPIOA_PCLOCK_DI() (RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLOCK_DI() (RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLOCK_DI() (RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLOCK_DI() (RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLOCK_DI() (RCC->AHB1ENR &= ~(1<<4))
#define GPIOH_PCLOCK_DI() (RCC->AHB1ENR &= ~(1<<7))

//--------------------------------------------------------------------------------

//-----------------------------------REGISTERS RESET REGION---------------------------------------------
#define GPIOA_REG_RESET() do{(RCC->AHB1RSTR |= (1<<0)); (RCC->AHB1RSTR &= (0<<0))}while(0)
#define GPIOB_REG_RESET() do{(RCC->AHB1RSTR |= (1<<1)); (RCC->AHB1RSTR &= (0<<1))}while(0)
#define GPIOC_REG_RESET() do{(RCC->AHB1RSTR |= (1<<2)); (RCC->AHB1RSTR &= (0<<2))}while(0)
#define GPIOD_REG_RESET() do{(RCC->AHB1RSTR |= (1<<3)); (RCC->AHB1RSTR &= (0<<3))}while(0)
#define GPIOE_REG_RESET() do{(RCC->AHB1RSTR |= (1<<4)); (RCC->AHB1RSTR &= (0<<4))}while(0)
#define GPIOH_REG_RESET() do{(RCC->AHB1RSTR |= (1<<7)); (RCC->AHB1RSTR &= (0<<7))}while(0)

// we don't need of a cycle, but this is a way to execute more instructions with one macro in C.

//---------------------- GENERIC MACROS --------------------------
#define ENABLE 1
#define DISABLE 0
#define SET ENABLE
#define RESET DISABLE
#define GPIO_PIN_SET SET
#define GPIO_PIN_RESET RESET
#endif // INC_STM32F401XX
