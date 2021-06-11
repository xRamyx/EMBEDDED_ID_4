#include "tm4c123gh6pm.h"

void PortE_Init ()
{ // for RS , RW , E pins (1,2,3) , UART5 pins(4,5)
	SYSCTL_RCGCGPIO_R |= 0x00000010;
        while ((SYSCTL_PRGPIO_R&0x10) == 0){};
	GPIO_PORTE_LOCK_R = 0x4C4F434B;
	GPIO_PORTE_CR_R |= 0x3E;
	GPIO_PORTE_DIR_R = 0x0E;
	GPIO_PORTE_DEN_R = 0x3E;
	GPIO_PORTE_AMSEL_R = 0x00;
	GPIO_PORTE_AFSEL_R = 0x30;
	GPIO_PORTE_PCTL_R = 0x00110000;
        GPIO_PORTE_PUR_R = 0x00;
  
}
/*int main(){
	PORTA_init();
	PORTE_init();
}*/
//we were using port A0,A1 for the uart0 but we relised that port A0,A1 wasn't suitable for the gps so we used port E4,E5 for the uart
