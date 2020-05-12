/*
 * timerAux.h
 * declaration of timer class
 * Author: Florent Dondjeu Tschoufack
 * created: November 2, 2019
 * current: November 5, 2019
 */
#ifndef TIMERAUX_H
#define TIMERAUX_H

#include <time.h>

class Timer
{
	private:
		clock_t t;
	public:
		//Timer
		//initialize t to zero
		//parameter: none
		//returns: none
		//precondition: none
		//postcondition: t is equal to zero
		Timer();
		
		//resetTime
		//reinitialize t to zero
		//parameter: none
		//returns: none
		//precondition: none
		//postcondition: t is equal to zero
		void resetTime();
		
		//startTime
		//starts the timer count
		//parameter: none
		//returns: none
		//precondition: none
		//postcondition: t is greater than zero
		void startTime();
		
		//endTime
		//stops the timer count and output the time in seconds
		//parameter: none
		//return: none
		//precondition: t is greater than zero
		//postcondition: timer is outputed and t is reset to zero 
		void endTime();
		
};

#endif