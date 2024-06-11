#include <stdint.h>
#include "main.h"


int main(void)
{
	RCC_AHB1ENR_t* RCC_AHB1ENR = (RCC_AHB1ENR_t*)0x40023830;
	GPIOx_MODER_t* GPIOA_MODER = (GPIOx_MODER_t*)0x40020000;
	GPIOx_MODER_t* GPIOC_MODER = (GPIOx_MODER_t*)0x40020800;
	GPIOx_ODR_t* GPIOA_ODR 	   = (GPIOx_ODR_t*)0x40020014;
	GPIOx_IDR_t* GPIOC_IDR 	   = (GPIOx_IDR_t*)0x40020810;

	RCC_AHB1ENR->gpioa_en = 1;
	GPIOA_MODER->moder5 = 1;
//	GPIOA_ODR->odr5 = 1;


	RCC_AHB1ENR->gpioc_en = 1;
	GPIOC_MODER->moder13 = 0;

    /* Loop forever */
	for(;;){
		if (GPIOC_IDR->idr13){
			GPIOA_ODR->odr5 = 1;
		}
		else if((GPIOC_IDR->idr13)==0){
			GPIOA_ODR->odr5 = 0;
		}



	}
}
