#include "STD_TYPES.h"
#include "tm4c123gh6pm.h"
void RGB_LEDs(u16 Total_Dist){
	if(Total_Dist > 100){
		GPIO_PORTF_DATA_R |= 0x02; // Make RGB LEDs light up
 }
}
