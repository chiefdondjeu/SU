/*
 * timerAux.cpp
 * implementation of timer class
 * Author: Florent Dondjeu Tschoufack
 * created: November 2, 2019
 * current: April 2, 2020 
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

double Timer :: endTime()
{
	t = clock() - t;
	double time = ((double)t)/CLOCKS_PER_SEC;
	resetTime();
  return time;
}
