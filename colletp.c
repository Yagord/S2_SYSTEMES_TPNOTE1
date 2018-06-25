#include "iq.h"
#include "iq_adc.h"
#define byte unsigned char

byte *trisb = (byte *)0xf93 ;
byte *portb = (byte *)0xf81 ;
byte *trisc = (byte *)0xf94 ;
byte *portc = (byte *)0xf82 ;
byte *trisd = (byte *)0xf95 ;
byte *portd = (byte *)0xf83 ;

unsigned char seconde = 99;
unsigned char valB0;
unsigned char valB1;
unsigned char valB2;

void init(void)
{
*trisb=0;
*trisc=0xff;
*trisd=0;
init_adc();
}

unsigned char convert_hex_dec(unsigned char hex) {

	unsigned char deb;
	unsigned char fin;	
	
	deb = hex % 10;
	fin = hex / 10;
	
	return deb + fin*16;
}

void main(void)
{
init();

while(1)
	{
		if (PORTCbits.RC0 == 0) {
			PORTBbits.RB0 = 0b00000001;
			PORTBbits.RB1 = 0b00000000;
			PORTBbits.RB2 = 0b00000000;
		}
		else {
			delayms(3000);
			PORTBbits.RB0 = 0b00000000;
			PORTBbits.RB2 = 0b00000001;
			delayms(5000);
			PORTBbits.RB2 = 0b00000000;
			PORTBbits.RB1 = 0b00000001;
			delayms(1000);
			PORTBbits.RB1 = 0b00000000;
			PORTBbits.RB0 = 0b00000001;
		}
	}

}