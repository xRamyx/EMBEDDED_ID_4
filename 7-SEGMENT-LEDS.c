#include "tm4c123gh6pm.h"
void 7-SEGMENT-LEDS(void){
while (1){
GPIO_PORTF_DATA_R |=  0X7F;
GPIO_PORTE_DATA_R &= ~0X0E;
}
}