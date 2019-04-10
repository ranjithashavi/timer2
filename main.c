/*
 */

#include <avr/io.h>
#include<avr/interrupt.h>
volatile uint16_t overflow=0;
int main(void)
{
TCCR2B|=(1<<CS21); //no prescaller = 256
TCCR2B|=(1<<CS22);
TCNT2=0x00;
TIMSK2|=(1<<TOIE2);
sei();
DDRC|=(1<<PC0);

    while(1)
    {
        if(overflow>=12)
        {

            if(TCNT2>=64)
            {
                PORTC^=(1<<0);
                TCNT2=0;
                overflow=0;
            }
        }
    }

    return 0;
}
ISR(TIMER2_OVF_vect)
{
    overflow++;
}
