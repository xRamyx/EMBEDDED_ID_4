#include "KPD.h"
#include "STD_TYPES.h"
#include "tm4c123gh6pm.h"

u8 symbol[N_row][N_col] = {{ '1', '2',  '3', 'A'},      
                           { '4', '5',  '6', 'B'},      
                           { '7', '8',  '9', 'C'},      
                           { '*', '0',  '#', 'D'}};

													 

void Keypad_Init(void)
{
  SYSCTL_RCGCGPIO_R |= 0x00000005;  
  while ((SYSCTL_PRGPIO_R&0x05) == 0){}; 
	GPIO_PORTA_LOCK_R = 0x4C4F434B;
	GPIO_PORTC_LOCK_R = 0x4C4F434B;
  GPIO_PORTC_CR_R |= 0xF0;           
  GPIO_PORTA_CR_R |= 0x3C;             
	GPIO_PORTC_DIR_R |= 0xF0;     
  GPIO_PORTA_DIR_R = 0x00;             
  GPIO_PORTA_PDR_R = 0x3C;            
  GPIO_PORTC_DEN_R |= 0xF0;
  GPIO_PORTA_DEN_R = 0x3C;
	GPIO_PORTA_AMSEL_R = 0x00;
	GPIO_PORTA_AFSEL_R = 0x00;
	GPIO_PORTA_PCTL_R = 0x00000000;
}

u8 Keypad_Getkey(void)
{
  while(1)
  {
    for(int i = 0; i < N_col; i++)  
    {
      GPIO_PORTC_DATA_R = (1 << i+4);
      for(int j = 0; j < N_row; j++)  
      {
        if((GPIO_PORTA_DATA_R & 0x3C) & (1 << j+2))
          return symbol[j][i];
      }
    }
  }
}