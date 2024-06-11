#include <stdint.h>
#include<stdio.h>



int main(void)
{

	uint32_t *RCC_AHB1ENR = (uint32_t *)0x40023830;
	uint32_t *GPIOC_MODER = (uint32_t *)0x40020800;
	uint32_t *GPIOA_MODER = (uint32_t *)0x40020000;
	uint32_t *GPIOA_ODR = (uint32_t *)0x40020014;
	uint32_t *GPIOC_IDR = (uint32_t *)0x40020810;
//	uint32_t *GPIOC_PUPDR = (uint32_t *)0x4002080C;

	*RCC_AHB1ENR |= 0x05;				//Enable clock for AHB1 for PORTA nd PORTC
	*GPIOA_MODER &= 0xFFFFF3FF;			//Output mode
	*GPIOA_MODER |= 0x00000400;




	*GPIOC_MODER &= 0x00000000;			//Input mode



    /* Loop forever */
	for(;;){

		if (*GPIOC_IDR & (1<<13)){
			*GPIOA_ODR |= 0x20;
		}
		else if((*GPIOC_IDR & (1<<13))==0){
		   	*GPIOA_ODR &= 0x00;
		}
		printf("%ld",*GPIOC_IDR);
	}
}
