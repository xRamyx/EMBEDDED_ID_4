#include "GPIO_INIT.h"
#include "tm4c123gh6pm.h"

u8 SW1_Input(void)
{
	return GPIO_PORTF_DATA_R&0x10;
}

u8 SW2_Input(void)
{
	return GPIO_PORTF_DATA_R&0x01;
}