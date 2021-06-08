#include "GPIO_INIT.h"
#include "tm4c123gh6pm.h"

void Parsing(f32 arr[])
{
	u8 c;
	u8 flag=0;
	u8* lat;
	u8* lon;
	u8* NorS;
	u8* EorW;
	u8* fix;
	f32 flat;
	f32 flon;
	u8 ilat;
	u8 ilon;
	f32 rlat;
	f32 rlon;
	u8 inchar[50];
		while(flag==0){
			   c = UART5_InChar();
				if(c =='$'){
					c = UART5_InChar();
					if(c=='G'){
						c = UART5_InChar();
						if(c=='P'){
							c = UART5_InChar();
							if(c=='G'){
								c = UART5_InChar();
								if(c=='G'){
									c = UART5_InChar();
									if(c=='A'){
										c = UART5_InChar();
										if(c==','){
											for(int i=0;i<50;i++){
												inchar[i]= UART5_InChar();
											}
											flag==1;
										}
									}
								}
							}
						}
					}
				}

		}

}