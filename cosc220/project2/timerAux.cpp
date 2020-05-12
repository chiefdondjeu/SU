/*
 * timerAux.cpp
 * implementation of timer class
 * Author: Florent Dondjeu Tschoufack
 * created: November 2, 2019
 * current: November 5, 2019
 */
#include <iostream>
#include "timerAux.h"

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
	std :: cout << "\nTimer: " << ((float)t)/CLOCKS_PER_SEC << " sec " << std :: endl;
	resetTime();
}