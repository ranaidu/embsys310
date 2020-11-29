## 1. Follow the same steps as we did in the class to blink LED1 (PA5) at a visible rate using the bit-band region to enable the clock to Port A, then answer the following:
### a. What instructions does the compiler produce in assembly for “writing” to the GPIO bit when using bit-band address?
LDR.N and STR instructions.
### b. What were the instructions produced when writing to the GPIOx_ODR without using bit-banding?
LDR.N, LDR, ORR and STR instructions.

## 2. Create a function “func1” with 5 arguments and call “func1” from within another function “func2”. Trace thru the assembler and note:
### a. How does the calling function “func2” pass the values to the called function “func1”?
func2 uses registers and memory in stack to pass the values.
### b. What extra code did the compiler generate before calling the function “func1” with the multiple arguments?
- Push the registers and LR to the stack.
- Adjust(decrement in this case) the stack pointer
- Copies the arguments to registor and stach memory depending on the number of variables
### c. What extra code did the compiler generate inside the called function “funct1” with the multiple list of arguments?
- copies the arguments back to register from stack memory ex: LDR R4, [SP, #0x44]
### d. Any other observations?
- registers and PC will be pop'ed from Stack.