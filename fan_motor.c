/*
 * fan_motor.c
 *
 *  Created on: Oct 6, 2021
 *      Author: lenovo
 */


#include "fan_motor.h"
#include "gpio.h"
#include <avr/io.h>
#include "PWM.h"


//function to set the direction of the motor pins

void DcMotor_Init(void) {

	GPIO_setupPinDirection(MOTOR_PORT,MOTOR_IN1,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT,MOTOR_IN2,PIN_OUTPUT);

	GPIO_writePin(MOTOR_PORT,MOTOR_IN1,LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT,MOTOR_IN2,LOGIC_LOW);


}

// The function responsible for rotate the DC Motor CW/ or A-CW
//or stop the motor based on the state input state value.
//and Send the required duty cycle to the PWM driver based on the required speed value.


void DcMotor_Rotate(DcMotor_State state,uint8 speed){

	uint8 Duty_Cyc ;

	Duty_Cyc = ((float)speed/100)*255 ;

	Timer0_PWM_Init(Duty_Cyc) ;


	if (state == CW){
		GPIO_writePin(MOTOR_PORT,MOTOR_IN1,LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT,MOTOR_IN2,LOGIC_LOW);
	}

	else if (state == ACW) {
		GPIO_writePin(MOTOR_PORT,MOTOR_IN1,LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT,MOTOR_IN2,LOGIC_HIGH);
	}

	else {
		GPIO_writePin(MOTOR_PORT,MOTOR_IN1,LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT,MOTOR_IN2,LOGIC_LOW);
	}







}
