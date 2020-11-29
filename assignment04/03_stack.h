/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>

void stack_init(void);
int push(int data);
int pop(void);
bool IsStackFull(void);
bool IsStackEmpty(void);

#endif
