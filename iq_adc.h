

#include<delays.h>
#include<adc.h>

void init_adc();
unsigned char lecture_analogique();
void init_adc()
{
 OpenADC( ADC_FOSC_32      &
         ADC_RIGHT_JUST   &
         ADC_16_TAD,
         ADC_CH0          &
         ADC_REF_VDD_VSS  &
         ADC_INT_OFF, 12  );


Delay10TCYx( 5 );     // Delay for 50TCY

}

unsigned char lecture_analogique()
{
ConvertADC();         // Start conversion\par
while( BusyADC() );   // Wait for completion\par
return(ReadADC() >> 2);   // Read result\par
}
