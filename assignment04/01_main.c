
#define RCC_BASE    0x40021000
#define GPIOA_BASE 0x48000000
#define GPIOB_BASE 0x48000400

#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR   (*((unsigned int*)(GPIOA_BASE + 0x14)))
#define GPIOA_AFRL   (*((unsigned int*)(GPIOA_BASE + 0x20)))

#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x0)))
#define GPIOB_ODR   (*((unsigned int*)(GPIOB_BASE + 0x14)))

//PB14 and PA5
volatile int counter = 0;
int main()
{

    *((unsigned int *)((0x42000000)+(0x2104C * 32) + (0 * 4))) = 0x1;       //Bit Banding the 0thbit for GPIOB
    *((unsigned int *)((0x42000000)+(0x2104C * 32) + (1 * 4))) = 0x1;       //Bit Banding the 1stbit for GPIOB


    // GPIOA Base address: 0x48000000
    //GPIOA_MODER = 0xABFFF7FF; // GPIOA_MODER: Set GPIOA to output //0xABFFFAFF
    //GPIOB_MODER =  0xDFFFFEBF;
    //Set 01 in 29 and 28th bit respectively to set the mode as GPIO Output
    GPIOB_MODER |=  (0x01 << 0x1C); // Set 28th bit
    GPIOB_MODER &=  ~(0x01 << 0x1D);//Clear 29th bit

    //Set 01 in 11 and 10th bit respectively to set the mode as GPIO Output
    GPIOA_MODER |=  (0x01 << 0xA);
    GPIOA_MODER &=  ~(0x01 << 0xB);


     while(1)
    {
        counter = 0;
        while(counter <100000)
            counter++;
        //GPIOB_ODR = 0x4000;      // GPIOB_ODR: Turn LED2 (PB14) on
        //GPIOB_ODR |= (0x01 << 0xE);
        //GPIOA_ODR |= (0x01 << 0x5);
        GPIOB_ODR ^= (0x01 << 0xE);
        GPIOA_ODR ^= (0x01 << 0x5);     // XOR to toggle LED1(PA5)


    }

  return 0;
}
