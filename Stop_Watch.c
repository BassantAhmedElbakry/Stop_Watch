/*
 * Stop_Watch.c
 *
 *  Created on: ١١‏/٠٩‏/٢٠٢٢
 *      Author: BASSNT
 */
#include "Stop_Watch.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void Timer1_Init(void){
	TCCR1B = (1 << WGM12) | (1 << CS10) | (1 << CS12);
	TCNT1 = 0;
	OCR1A = 977;
	SET_BIT(TIMSK,OCIE1A);
	SET_BIT(SREG,7);
	}

void INT0_Init(void){
	CLEAR_BIT(DDRD,2);//D2 --> InPut Pin
	SET_BIT(MCUCR,ISC01);
	SET_BIT(GICR,INT0);
	SET_BIT(SREG,7);
}

void INT1_Init(void){
	CLEAR_BIT(DDRD,3);//D3 --> InPut Pin
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
	SET_BIT(GICR,INT1);
	SET_BIT(SREG,7);
}

void INT2_Init(void){
	CLEAR_BIT(DDRB,2); //B2 --> InPut Pin
	CLEAR_BIT(MCUCSR,ISC2);
	SET_BIT(GICR,INT2);
	SET_BIT(SREG,7);
}

void Stop_Watch(void){

	Time[0]++;

	if(Time[0] > 9){
		Time[1]++;
		Time[0] = 0;

		if(Time[1] == 6){
			Time[2]++;
			Time[1] = 0;
		}
	}

	if(Time[2] > 9){
		Time[3]++;
		Time[2] = 0;

		if(Time[3] == 6){
			Time[4]++;
			Time[3] = 0;
		}
	}

	if(Time[4] > 9){
		Time[5]++;
		Time[4] = 0;

		if(Time[5] > 9){
			for(i = 0; i < 6 ; i++)
				Time[i] = 0;
		}
	}
}
