#include "stm32l4xx_it.h"
#pragma section="CSTACK"

void __iar_program_start(void);

int const __vectortable[] @ ".intvec" = {
        (int)__section_end("CSTACK"),
    (int)__iar_program_start,
    (int)NMI_Handler,
    (int)HardFault_Handler,
    (int)MemManage_Handler,
    (int)BusFault_Handler,
    (int)UsageFault_Handler,
    0,      // Reserved
    0,      // Reserved
    0,      // Reserved
    0,      // Reserved
    (int)SVC_Handler,
    (int)DebugMon_Handler,
    0,      // Reserved
    (int)PendSV_Handler,
    (int)SysTick_Handler
};

void NMI_Handler(void)
{
}


void HardFault_Handler(void)
{
  // Go to infinite loop when Hard Fault exception occurs
  while (1)
  {
  }
}


void MemManage_Handler(void)
{
  // Go to infinite loop when Memory Manage exception occurs
  while (1)
  {
  }
}


void BusFault_Handler(void)
{
  // Go to infinite loop when Bus Fault exception occurs
  while (1)
  {
  }
}


void UsageFault_Handler(void)
{
  // Go to infinite loop when Usage Fault exception occurs
  while (1)
  {
  }
}


void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}
