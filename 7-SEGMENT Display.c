#include "tm4c123gh6pm.h"
#include "STD_TYPES.h"

void OUT( u8 hundreds , u8 tens , u8 units)
{
while(1)
{
    GPIO_PORTE_DATA_R &= 0xF7; //1111 0111
    GPIO_PORTE_DATA_R |= 0x06; //0000 0110
    switch (hundreds)
    {
        case 0 : GPIO_PORTB_DATA_R = 0x7E;
        break;
        case 1 : GPIO_PORTB_DATA_R = 0x30;
        break;
        case 2 : GPIO_PORTB_DATA_R = 0x6D; 
        break;
        case 3 : GPIO_PORTB_DATA_R = 0x79;
        break;
        case 4 : GPIO_PORTB_DATA_R = 0x33;
        break;
        case 5 : GPIO_PORTB_DATA_R = 0x5B;
        break;
        case 6 : GPIO_PORTB_DATA_R = 0x5F;
        break;
        case 7 : GPIO_PORTB_DATA_R = 0x70;
        break;
        case 8 : GPIO_PORTB_DATA_R = 0x7F;
        break;
        case 9 : GPIO_PORTB_DATA_R = 0x73;
        break;
    }
    delay_ms(1);
    GPIO_PORTE_DATA_R &= 0xFB; //1111 1011
    GPIO_PORTE_DATA_R |= 0x0A; //0000 1010
    switch (tens)
    {
        case 0 : GPIO_PORTB_DATA_R = 0x7E;
        break;
        case 1 : GPIO_PORTB_DATA_R = 0x30;
        break;
        case 2 : GPIO_PORTB_DATA_R = 0x6D;
        break;
        case 3 : GPIO_PORTB_DATA_R = 0x79;
        break;
        case 4 : GPIO_PORTB_DATA_R = 0x33;
        break;
        case 5 : GPIO_PORTB_DATA_R = 0x5B;
        break;
        case 6 : GPIO_PORTB_DATA_R = 0x5F;
        break;
        case 7 : GPIO_PORTB_DATA_R = 0x70;
        break;
        case 8 : GPIO_PORTB_DATA_R = 0x7F;
        break;
        case 9 : GPIO_PORTB_DATA_R = 0x73;
        break;
    }
    delay_ms(1);
    GPIO_PORTE_DATA_R &= 0xFD; //1111 1101
    GPIO_PORTE_DATA_R |= 0x0C; //0000 1100
    switch (units)
    {
        case 0 : GPIO_PORTB_DATA_R = 0x7E;
        break;
        case 1 : GPIO_PORTB_DATA_R = 0x30;
        break;
        case 2 : GPIO_PORTB_DATA_R = 0x6D;
        break;
        case 3 : GPIO_PORTB_DATA_R = 0x79;
        break;
        case 4 : GPIO_PORTB_DATA_R = 0x33;
        break;
        case 5 : GPIO_PORTB_DATA_R = 0x5B;
        break;
        case 6 : GPIO_PORTB_DATA_R = 0x5F;
        break;
        case 7 : GPIO_PORTB_DATA_R = 0x70;
        break;
        case 8 : GPIO_PORTB_DATA_R = 0x7F;
        break;
        case 9 : GPIO_PORTB_DATA_R = 0x73;
        break;
    }
    delay_ms(1);
}
}
