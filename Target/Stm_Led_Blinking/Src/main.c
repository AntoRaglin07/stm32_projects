#include <stdint.h>

//#if !defined(__SOFT_FP__) && defined(__ARM_FP)
//  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
//#endif




int main(void)
{
	uint32_t *RCC_AHB1ENR = (uint32_t *)0x40023830;
	uint32_t *GPIOA_MODER = (uint32_t *)0x40020000;
	uint32_t *GPIOA_ODR = (uint32_t *)0x40020014;
	*RCC_AHB1ENR |= 0x01;
	*GPIOA_MODER &= 0xFFFFF3FF;
	*GPIOA_MODER |= 0x00000400;
	*GPIOA_ODR |= 0x20;
    /* Loop forever */
	for(;;)
	{
		*GPIOA_ODR |= 0x20;
        uint32_t i;
        for(i=0;i<2000000;i++);
    	*GPIOA_ODR &= 0x00;
        for(i=0;i<2000000;i++);
	}
//	for(;;);
}
