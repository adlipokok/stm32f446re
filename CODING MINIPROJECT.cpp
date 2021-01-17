#include "mbed.h"
#define TX PA_9
#define RX PA_10

void delayMs(int n);

Serial bluetooth(TX, RX);

DigitalOut LEDA(PC_1, 0);
DigitalOut LEDB(PC_2, 0);
DigitalOut MOTORA(PA_1, 0);
DigitalOut MOTORB(PA_5, 0);
DigitalOut MOTORC(PA_6, 0);
DigitalOut BUZZER(PC_6, 0);

int main(void)
{
    char Buffer[10];

     while(1)
    {
        bluetooth.scanf("%s", Buffer);
        if(Buffer[0] == 'O' && Buffer[1] == 'N')
        {
            if(Buffer[2] == 'A')
            {
                 LEDA = 1 ;
                 BUZZER=1;
                 delayMs(1000);
                 BUZZER=0;
                 delayMs(1000);
                 BUZZER=1;
                 delayMs(1000);
                 BUZZER=0;
            }
            else if(Buffer[2] == 'B')
            {
                 MOTORA =1;
                 BUZZER=1;
                 delayMs(1000);
                 BUZZER=0;
                 delayMs(1000);
                 BUZZER=1;
                 delayMs(1000);
                 BUZZER=0;
            }
            else if(Buffer[2] == 'C')
            {
                 LEDB = 1;
                 BUZZER=1;
                 delayMs(1000);
                 BUZZER=0;
                 delayMs(1000);
                 BUZZER=1;
                 delayMs(1000);
                 BUZZER=0;
            }
            else if(Buffer[2] == 'D')
            {

                 MOTORB=1;
                 delayMs(2000);
                 MOTORB=0;
                 BUZZER=1;
                 delayMs(1000);
                 BUZZER=0;
                 delayMs(1000);
                 BUZZER=1;
                 delayMs(1000);
                 BUZZER=0;
            }
            else if(Buffer[2] == 'E')
            {
                 LEDA = 1;
                 LEDB = 1;
                 BUZZER=1;
                 delayMs(1000);
                 BUZZER=0;
                 delayMs(1000);
                 BUZZER=1;
                 delayMs(1000);
                 BUZZER=0;
            }

        }
        else if(Buffer[0] == 'O' && Buffer[1] == 'F' && Buffer[2] == 'F')
        {
            if(Buffer[3] == 'A')
            {
                 LEDA = 0;
                 BUZZER=1;
                 delayMs(2000);
                 BUZZER=0;
            }
            else if(Buffer[3] == 'B')
            {
                 MOTORA = 0;
                 BUZZER=1;
                 delayMs(2000);
                 BUZZER=0;
            }
            else if(Buffer[3] == 'C')
            {
                 LEDB = 0;
                 BUZZER=1;
                 delayMs(2000);
                 BUZZER=0;
            }
            else if(Buffer[3] == 'D')
            {
                 MOTORC = 1;
                 delayMs(2000);
                 MOTORC =0;
                 BUZZER=1;
                 delayMs(2000);
                 BUZZER=0;
            }
            else if(Buffer[3] == 'E')
            {
                 MOTORA = 0;
                 MOTORC = 1;
                 delayMs(2000);
                 MOTORC =0;
                 LEDA = 0;
                 LEDB = 0;
                 BUZZER=1;
                 delayMs(2000);
                 BUZZER=0;
            }
        }

    }
}
void delayMs(int n){
    int i;
    for (; n>0;n--)
        for (i=0; i<3195;i++);
}
