/*
 * main.c
 *
 *  Created on: ١٠‏/٠٩‏/٢٠٢٢
 *      Author: BASSNT
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Stop_Watch.h"

int main (void){

		/*Define pins In/Out Pins*/

	DDRA |= 0x3F; //OutPut Pins A0 --> A5
	DDRC |= 0x0F ; //OutPut Pins C0 --> C3

		/*Initialization Values*/

	PORTC &= 0xF0; //7-segment displays 0 as initial value
	PORTA |=0x3F;
	Flag = 0;
	Timer1_Init();
	INT0_Init();
	INT1_Init();
	INT2_Init();

		/*Active Internal Pull up Resistor*/

	SET_BIT(PORTB,2);
	SET_BIT(PORTD,2);

	while(1){


		for(i = 0; i < 6; i++){

			PORTA = (PORTA & 0xC0) | (1<<i);
			PORTC = (PORTC & 0xF0) | (Time[i] & 0x0F);
			_delay_ms(1);

		}

		if(Flag == 1){
			Stop_Watch();
			Flag = 0;
		}

	}

	return 0;
}

ISR(TIMER1_COMPA_vect){
	Flag = 1;
}

ISR(INT0_vect){
	PORTC &= 0xF0; //7-segment displays 0 as initial value

	for(i = 0; i < 6 ; i++)
		Time[i] = 0;
}

ISR(INT1_vect){
	CLEAR_BIT(TIMSK,OCIE1A);
}

ISR(INT2_vect){
	SET_BIT(TIMSK,OCIE1A);
}

