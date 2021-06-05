#include "tm4c123gh6pm.h"

void PORTE_init (void){
	SYSCTL_RCGCGPIO_R |= 0X10;
	while((SYSCTL_PRGPIO_R & 0X10) == 0){};
	GPIO_PORTE_LOCK_R = 0X4C4F434B;
	GPIO_PORTE_CR_R |= 0X0E;
	GPIO_PORTE_DIR_R |= 0X0E;
	GPIO_PORTE_DEN_R |= 0X0E;
	GPIO_PORTE_AMSEL_R &= ~ 0X0E;
	GPIO_PORTE_AFSEL_R &= ~ 0X0E;
	GPIO_PORTE_PCTL_R &= ~ 0X00001110;
	GPIO_PORTE_PUR_R &= ~ 0x0E;
}
/*int main(){
	PORTA_init();
	PORTE_init();
}*/
//we were using port A0,A1 for the uart0 but we relised that port A0,A1 wasn't suitable for the gps so we used port E4,E5 for the uart
