#include "GPIO_INIT.h"
#include "tm4c123gh6pm.h"
#include <string.h> // For strtok function
#include <stdlib.h> // For strtod function

void Parsing(f32 arr[]) //When an array is passed as an argument then its base address is passed to the function so whatever changes made to the copy of the array, it is changed in the original array.
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
		while(flag==0){ // Check for the raw data of the gps >> $GPGGA which contains the latitude and longitude and the fix
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
										}
									}
								}
							}
						}
					}
				}
			lat = strtok(inchar, ",");
			lat = strtok(NULL, ",");
			NorS = strtok(NULL, ",");
			lon = strtok(NULL, ",");
			EorW = strtok(NULL, ",");
		  fix = strtok(NULL, ",");
				if(fix[0]=='1'){ // Check for the first fix
					flag=1;
				}
		}
		flat= strtod(lat,NULL); // Convert string to float
		flon= strtod(lon,NULL);
		flat=flat/100;
		flon=flon/100;
		ilat=(u8)flat;
		ilon=(u8)flon;
		flat=flat-ilat;
		flon=flon-ilon;
		flat=(flat*100)/60;
		flon=(flon*100)/60;
		rlat=ilat+flat; // Now we have latitude and longitude in decimal format instead of degrees and minutes
		rlon=ilon+flon;
		if(NorS[0] == 'S'){ //South means -ve
			rlat*=-1;
		}
		if(EorW[0]=='W'){ // West means -ve
			rlon*=-1;
		}
			arr[0]=rlat;
			arr[1]=rlon;
}
