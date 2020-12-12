#include <stdint.h>
#include "system_stm32l4xx.h"
#include "stm32l475xx.h"


#define SYS_CLOCK_HZ 4000000u
#define SYSTICK_FREQ   1 //1 ms

unsigned int tickCount = 0;

void SysTick_Initialize(void);

// This will be called for every 1ms through SysTick_Handler
void incTick(void)
{
    tickCount+= SYSTICK_FREQ;
}


void delay(unsigned int delay)
{
    // Get the present tickCount
    unsigned int tickStart = tickCount;

    while((tickCount - tickStart) < delay);
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

    SysTick_Initialize();

    while(1)
    {
        GPIOA->ODR ^= GPIO_ODR_OD5;
        delay(100); // delay for 100ms
    }

  return 0;
}


void SysTick_Initialize(void)
{
    SysTick->LOAD = (SYS_CLOCK_HZ/1000)-1;
    SysTick->VAL = 0x0;
    SysTick->CTRL = 0x7;
}

void SysTick_Handler(void)
{
    __disable_irq();
    incTick();
    __enable_irq();
}
