#include "GPIO_INIT.h"
#include "tm4c123gh6pm.h"

int main(void)
{
    PortF_Init();
    PortE_Init();
    PortB_Init();

    u16 dist =450; // dummy data to be displayed on the 3-digit seven segments

    while (1)
    {
        RGB_LEDs(dist);
        OUT(4,5,0); // data will be passed to the function in form of hundreds ,tens and digits


    }
}
