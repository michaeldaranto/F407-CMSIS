/*********************************************************
DISCOVERY KIT STM32F407VGT6 (MB997D)
STM32F407G-DISC1
GPIOD Pin13 --> LD3 (Orange)
Blink LD3
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
    
	// Set GPIOD Pin13 Output
	GPIOD->MODER|= GPIO_MODER_MODE13_0;
	GPIOD->MODER&=~GPIO_MODER_MODE13_1;

	while (1) {
	    //XOR to toggle
    	    GPIOD->ODR ^=GPIO_ODR_OD13; 
    	    delay();
	}
	// Return 0 to satisfy compiler
	return 0;
}
