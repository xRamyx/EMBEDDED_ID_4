#include "GPIO_INIT.h"
#include "tm4c123gh6pm.h"

int main(void){
    PortF_Init();
    PortA_Init();
    PortB_Init();

    u16 dist =450;

    while (1)
    {
        RGB_LEDs(dist);
        OUT(4,5,0);


    }
}