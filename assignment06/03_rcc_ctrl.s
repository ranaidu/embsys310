/*******************************************************************************
File name       : rcc_ctrl.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/

    PUBLIC enable_rcc        // Exports symbols to other modules

        EXTERN delay                    // delay() is defined outside this file

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions,
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8.
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)

    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions

/*******************************************************************************
Function Name   : enable_rcc
Description     : - Uses Bit-Band registers at base 0x4200.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void enable_rcc(uint32_t port)
                : Where port indicates wich port to enable the clock for
Parameters      : R0: uint32_t port

Return value    : None
*******************************************************************************/

// Bitband address calculation formula
// (0x42000000+(0x2104C *32) + (1*4))) = 0x1;

BASE_ADDR   EQU     0x42000000
OFFSET      EQU     0x2104C
BIT_NUM     EQU     1

enable_rcc
    LDR R1, = BASE_ADDR
    LDR R2, = OFFSET
    MOVS R3, #32
    MUL R2, R2, R3
    LDR R4, = BIT_NUM
    MOVS R3, #4
    MUL R3, R3,R4
    ADD R1, R1, R2
    ADD R1, R1, R3
    STR R0,[R1]
    MOV R0, #10000
    PUSH {R0,LR}
    BL delay
    POP {R0, LR}
    STR R0,[R2]
    BX LR

    END
