#include <stdint.h>
#include "system_stm32l4xx.h"
#include "stm32l475xx.h"


void delay(unsigned int iteration)
{
    while (iteration > 0)
    {
        iteration--;
    }
}

int main()
{

    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // RCC Base Address: 0x40021000
    // Address offset: 0x4C
    // Set bit[1] to 1
    // 1. Enable clock to Peripheral
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;

    while(1)
    {
        GPIOA->ODR |= GPIO_ODR_OD5;
        delay(100000);

        GPIOA->ODR &= ~GPIO_ODR_OD5;
        delay(100000);
    }

  return 0;
}
