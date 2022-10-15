/*********************************************************
DISCOVERY KIT STM32F407VGT6 (MB997D)
STM32F407G-DISC1

GPIOD Pin13 --> LD3 (Orange)
GPIOD Pin12 --> LD4 (Green)
GPIOD Pin14 --> LD5 (Red)
GPIOD Pin15 --> LD6 (Blue)

FLIP-FLOP

Michael Daranto - YD3BRB
GPLv3
**********************************************************/
#include "stm32f4xx.h"

//Simple delay
void delay (void){
	for (uint32_t i=0; i < 500000; i++)
		__asm("nop");
}
int main (void) {
	
	// Turn on the GPIOD peripheral
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    
	// Set GPIOD Pin12-Pin15 Output
	GPIOD->MODER|= (GPIO_MODER_MODE12_0|GPIO_MODER_MODE13_0|GPIO_MODER_MODE14_0|GPIO_MODER_MODE15_0);
	GPIOD->MODER&=~(GPIO_MODER_MODE12_1|GPIO_MODER_MODE13_1|GPIO_MODER_MODE14_1|GPIO_MODER_MODE15_1);

	while (1) {
	    //XOR to toggle
			delay();
    	    GPIOD->ODR |=(GPIO_ODR_OD12|GPIO_ODR_OD14); 
    	    GPIOD->ODR&=~(GPIO_ODR_OD13|GPIO_ODR_OD15);
    	    delay();
    	    GPIOD->ODR&=~(GPIO_ODR_OD12|GPIO_ODR_OD14); 
    	    GPIOD->ODR|=(GPIO_ODR_OD13|GPIO_ODR_OD15);
    	    
			delay();
	}
	// Return 0 to satisfy compiler
	return 0;
}
