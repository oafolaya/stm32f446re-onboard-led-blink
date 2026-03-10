#include <stdint.h>

// PERIPHERAL BASE
#define PERIPHERAL_BASE (0x40000000UL)

// OFFSET ADDRESS
#define AHB1_OFFSET    (0x00020000UL)
#define RCC_OFFSET     (0x3800UL)
#define AHB1ENR_OFFSET (0x30UL)

#define GPIOA_OFFSET   (0x0000UL)
#define MODER_OFFSET   (0x00UL)
#define ODR_OFFSET     (0x14UL)

// BASE ADDRESSES
#define AHB1_BASE      (PERIPHERAL_BASE + AHB1_OFFSET)
#define RCC_BASE       (AHB1_BASE + RCC_OFFSET)
#define GPIOA_BASE     (AHB1_BASE + GPIOA_OFFSET)

// REGISTERS
#define RCC_AHB1ENR    (*(volatile unsigned int *)(RCC_BASE + AHB1ENR_OFFSET))
#define GPIOA_MODER    (*(volatile unsigned int *)(GPIOA_BASE + MODER_OFFSET))
#define GPIOA_ODR      (*(volatile unsigned int *)(GPIOA_BASE + ODR_OFFSET))

int main(void)
{
    RCC_AHB1ENR |= (1U << 0);

    GPIOA_MODER &= ~(1U << 11);
    GPIOA_MODER |=  (1U << 10);

    while (1) {
        GPIOA_ODR ^= (1U << 5);

        for (volatile int i = 0; i < 1000000; i++) {
        }
    }
}