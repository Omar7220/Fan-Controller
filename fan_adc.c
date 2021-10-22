/*
 * fan_adc.c
 *
 *
 *      Author: omar
 */


#include "avr/io.h"
#include "fan_adc.h"
#include "common_macros.h"



//function to set the prescaler and the voltage of the ADC

void ADC_init(const ADC_ConfigType * Config_Ptr) {

	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt)<<6); //insert the required voltage to the last three bits (REFS0 & REFS1)

	ADCSRA = (1<<ADEN) ; //ADC Enable

	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr->prescaler) ; //insert the required prescaler to the first three bits(ADPS0,ADPS1,ADPS2)


}


//function to read the digital value from the ADC channel

uint16 Read_adc(uint8 channel) {

channel &= 0x07 ;
ADMUX &= 0xE0 ;

ADMUX = ADMUX | channel ;
SET_BIT(ADCSRA,ADSC) ;
while (BIT_IS_CLEAR(ADCSRA,ADIF)) ;

SET_BIT(ADCSRA,ADIF) ;

return ADC ;


}
