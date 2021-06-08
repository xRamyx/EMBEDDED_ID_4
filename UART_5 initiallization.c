#include "GPIO_INIT.h"
#include "tm4c123gh6pm.h"

void UART5_init (void){ 
	SYSCTL_RCGCUART_R |= 0x0020;
	while((SYSCTL_PRUART_R & 0x0020)==0){};
	UART5_CTL_R &= ~0x0001;
	UART5_IBRD_R = 104;
	UART5_FBRD_R = 11; 
	UART5_LCRH_R = 0x0070; 
	UART5_CTL_R = 0x0301;
}