#include "GPIO_INIT.h"
#include "tm4c123gh6pm.h"
#include "Lcd.h"

int main(void)
{
  PortF_Init();
	PortE_Init();
	UART5_init ();
	PortB_Init();
	init_lcd();
	u16 buffer[10];
	f32 tot;
	f32 lato=0;
	f32 lono=0;
	f32 arr[2];
			
	while (1)
	{
			Parsing(arr);
	  	tot=Total_Distance(lato,lono ,arr[0], arr[1]);
			lcd_gotoxy(1,1);
			lcd_write_string("Distance reached");
			lcd_gotoxy(1,2);
			sprintf(buffer,"%d",(u16)tot);
		  lcd_write_string(buffer);
			lcd_gotoxy(5,2);
			lcd_write_string("M");
			if((SW2_Input()!=0x01)){
				RGB_LEDs((u16)tot);
				
			}
			
			delay_ms(1000);
		
	}
		
}
