/*----------THIS IS A HEADER FILE WHICH INCLUDES THE PROTOTYPES OF OUR FUNCTIONS WHICH ARE WRITTEN IN A SINGLE C FILE------------,
------------BUT HERE IN GITHUB WRITTEN INTO SEPARATE FILES TO SHOW THE CONTRIBUTION OF EACH MEMBER------------*/

#ifndef GPIO_INIT_H_
#define GPIO_INIT_H_

#include "STD_TYPES.h"

/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

/* PIN Value Options */
#define HIGH   1
#define LOW    0

/* IO Ports Initialization Functions Prototypes*/
void PortE_Init (void);
void PortB_Init (void);
void PortF_Init (void);
void UART5_init (void);
u8 UART5_InChar(void);
void Parsing(f32 arr[]);
void RGB_LEDs (u16 Total_Dist);
u8 SW2_Input(void);
u8 SW1_Input(void);
void OUT(u8 hundreds, u8 tens, u8 units); // If used 3-digit seven segments instead of LCD
f32 Total_Distance (f32* yo, f32* xo, f32 y1, f32 x1); // We used call by reference to change in latitude and longitude by pointers
f32 calc_dist(f32 yo,f32 xo,f32 y1,f32 x1);
void delay_ms(int t);

#endif
