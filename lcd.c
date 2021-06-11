#include "STD_TYPES.h"
#include "GPIO_INIT.h"
#include "tm4c123gh6pm.h"
#include "Lcd.h"



void init_lcd (void)                     
{
	
	lcd_cmd(lcd_FunctionSet8bit);
	delay_ms(1);

	
	
	lcd_cmd(lcd_EntryMode);
	delay_ms(1);
	
	
	lcd_cmd(lcd_DisplayOn);
	delay_ms(1);
	

	lcd_cmd(lcd_Clear);
	delay_ms(2);
	
	
	lcd_cmd(lcd_Home);
	delay_ms(2);
	
	return;
}



void lcd_cmd(u8 cmd)            
{
	GPIO_PORTB_DATA_R=cmd;
	
	GPIO_PORTE_DATA_R=(LOW<<PIN1)|(LOW<<PIN2)|(HIGH<<PIN3);
	delay_ms(1);
	GPIO_PORTE_DATA_R=(LOW<<PIN1)|(LOW<<PIN2)|(LOW<<PIN3);
	delay_ms(50);
	
	return;
}





void lcd_write(u8 data)
{
	GPIO_PORTB_DATA_R=data;
	
	GPIO_PORTE_DATA_R=(HIGH<<PIN1)|(LOW<<PIN2)|(HIGH<<PIN3);
	delay_ms(1);
	GPIO_PORTE_DATA_R=(HIGH<<PIN1)|(LOW<<PIN2)|(LOW<<PIN3);
	delay_ms(50);
	
	return;
}




void lcd_write_string(u8 *str)         
{
	int		i=0;
	while(str[i]!='\0')
	{
		lcd_write(str[i]);
		i++;
		
	}
	
	delay_ms(100);
	
	return;
	
}
void lcd_gotoxy(u8 x,u8 y)             
{
	u8 firstcharadr[]={0x80,0xC0}; // firstcharadr[0]=0x80  ,,,, firstcharadr[1]=0xC0 
	lcd_cmd(firstcharadr[y-1] + x - 1);
	delay_ms(50);
}
