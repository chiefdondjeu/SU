/*
 * timerAux.cpp
 * implementation of timer class
 * Author: Florent Dondjeu Tschoufack
 * created: November 2, 2019
 * current: April 1, 2020 
 */

#include <iostream>
#include "timer.h"

Timer :: Timer(): t(0)
{}

void Timer :: resetTime()
{
	t = 0;
}

void Timer :: startTime()
{
	t = clock();
}

void Timer :: endTime()
{
	t = clock() - t;
	std::cout << ((float)t)/CLOCKS_PER_SEC << " s\n";
	resetTime();
}
