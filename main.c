/*
 * main.c
 *
 *
 *      Author: Omar Gomaa
 */

#include "PWM.h"
#include"fan_motor.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "fan_adc.h"






int main () {

	ADC_ConfigType setup = {INTERNAL_VOLATAGE,FACTOR_8} ; //internal voltage 2.56 & prescaler/8



	ADC_init(&setup);
	LCD_init();
	DcMotor_Init();

	uint8 temp_read ;


	LCD_displayStringRowColumn(1,2,"Temp =    C") ;

	while (1) {

		temp_read = LM35_getTemperature();

		if (temp_read < 30 ){
			DcMotor_Rotate(STOP,0) ;
			LCD_displayStringRowColumn(0,2,"FAN is OFF") ;
		}
		else {
			LCD_displayStringRowColumn(0,2,"FAN is ON") ;
			LCD_displayCharacter(' ');


			if (temp_read>=30 && temp_read < 60) {
				DcMotor_Rotate(CW,25) ;
			}
			else if (temp_read>=60 && temp_read < 90) {
				DcMotor_Rotate(CW,50) ;
			}
			else if (temp_read>=90 && temp_read < 120) {
				DcMotor_Rotate(CW,75) ;
			}
			else if (temp_read >= 120) {
				DcMotor_Rotate(CW,100) ;
			}

		}


		if (temp_read < 100) {
			LCD_moveCursor(1,8);
			LCD_intgerToString(temp_read);
			LCD_displayCharacter(' ');
		}
		else {
			LCD_moveCursor(1,8);
			LCD_intgerToString(temp_read);
		}



	}












}
