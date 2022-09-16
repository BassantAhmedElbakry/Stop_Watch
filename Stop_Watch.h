/*
 * StopWatch.h
 *
 *  Created on: ١١‏/٠٩‏/٢٠٢٢
 *      Author: BASSNT
 */

#ifndef STOP_WATCH_H_
#define STOP_WATCH_H_

typedef unsigned char uint8;

uint8 i ,Flag , Time[6];

#define SET_BIT(REG,VAL_PIN)    REG |= (1 << VAL_PIN)
#define CLEAR_BIT(REG,VAL_PIN)  REG &= ~(1 << VAL_PIN)

void Timer1_Init(void);
void INT0_Init(void);
void INT1_Init(void);
void INT2_Init(void);

void Stop_Watch(void);

#endif /* STOP_WATCH_H_ */
