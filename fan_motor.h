/*
 * fan_motor.h
 *
 *  Created on: Oct 6, 2021
 *      Author: lenovo
 */

#ifndef FAN_MOTOR_H_
#define FAN_MOTOR_H_

#define MOTOR_PORT PORTB_ID
#define MOTOR_IN1 PIN0_ID
#define MOTOR_IN2 PIN1_ID
#define MOTOR_ENABLE PIN3_ID

#include "std_types.h"


typedef enum {
	STOP,CW,ACW
}DcMotor_State;


void DcMotor_Init(void) ;

void DcMotor_Rotate(DcMotor_State state,uint8 speed);



#endif /* FAN_MOTOR_H_ */
