/*
 * fan_adc.h
 *
 *  Created on: Oct 6, 2021
 *      Author: omar
 */

#ifndef FAN_ADC_H_
#define FAN_ADC_H_

#define ADC_MAX_VALUE   1023
#define ADC_REF_VOLTAGE 2.56



#include "std_types.h"

typedef enum {
	AREF,AVCC,RESERVED,INTERNAL_VOLATAGE
} ADC_ReferenceVolatge ;



typedef enum {
	FACTOR_2,FACTOR__2,FACTOR_4,FACTOR_8,FACTOR_16,FACTOR_32,FACTOR_64,FACTOR_128
}ADC_Prescaler;



typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;




void ADC_init(const ADC_ConfigType * Config_Ptr) ;

uint16 Read_adc(uint8 channel) ;








#endif /* FAN_ADC_H_ */
