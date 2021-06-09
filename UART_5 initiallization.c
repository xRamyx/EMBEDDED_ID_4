#include "GPIO_INIT.h"
#include "tm4c123gh6pm.h"

void UART5_init (void){ 
	SYSCTL_RCGCUART_R |= 0x0020;
	while((SYSCTL_PRUART_R & 0x0020)==0){};
	UART5_CTL_R &= ~0x0001;
	UART5_IBRD_R = 104; // int(16000000/(16*9600))=104
	UART5_FBRD_R = 11; // int(0.16667 * 64 + 0.5)=11
	UART5_LCRH_R = 0x0070; // 8-bit word length, enable FIFO
	UART5_CTL_R = 0x0301;
}

u8 UART5_InChar(void)
{
	while((UART5_FR_R & 0x10)!=0); //Wait if the reciever FIFO is empty
	return ((u8)(UART5_DR_R & 0xFF)); //Returns the first 8-bit (Data)
}
