#include "GPIO_INIT.h"
#include "tm4c123gh6pm.h"
#include "Lcd.h"
#include "KPD.h"

int main(void)
{
  PortF_Init();
	PortE_Init();
	UART5_init ();
	PortB_Init();
	init_lcd();
	Keypad_Init();
	u16 buffer[10]; //a buffer used to store a string to be displayed on LCD
	f32 tot=0; //variable to store total distance
	f32 lato=0; //variable to store latitude
	f32 lono=0; // variable to store longitude
	f32 arr[2]; // arr[0] for latitude and arr[1] for longitude
	u8 flagsw1=0; // a flag used to check if switch 1 is pressed or not
	u8 dest[3]; //an array used to store the entered distance through keypad
	lcd_write_string("Enter distance");
	lcd_gotoxy(5,2);
	lcd_write_string("M");
	for(int i=0;i<3;i++){
				dest[i]=Keypad_Getkey();
		    delay_ms(250);
				lcd_gotoxy(1+i,2);
				lcd_write(dest[i]);
			}
	
			u16 destination = 0;
			for (int i = 0; i < 3; i++){ // Convert string to int
				destination = (10 * destination) + (dest[i] - '0');
			}
			lcd_cmd(lcd_Clear);
			
	while (1)
	{
			Parsing(arr);
	  	tot+= Total_Distance(&lato, &lono , arr[0], arr[1]);
			lcd_gotoxy(1,1);
			lcd_write_string("Distance reached");
			lcd_gotoxy(1,2);
			sprintf(buffer,"%d",(u16)tot); // Change integer to string and making explicit type casting from float to integer
		  lcd_write_string(buffer);
			lcd_gotoxy(5,2);
			lcd_write_string("M");
			if((SW2_Input()!=0x01 || (tot>=destination))){ // If switch2 is pressed >> 0x00, Turn on LEDs and stop adding new points or if distance equals to the pre-defined distance
				RGB_LEDs((u16)tot);
				while(flagsw1==0){
					if(SW1_Input()!=0x10){ // If switch1 is pressed >> 0x00, Continue adding new points
						flagsw1=1;
					}
				}
				flagsw1=0;
			}
			
			delay_ms(1000); // Delay between each point taken from the gps module
		
	}
		
}
