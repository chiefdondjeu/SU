/*
 *Square.cpp
 *Definition of Square class
 *Author: Florent Dondjeu Tschoufack
 *created: September 13, 2019
 *current: September 29, 2019
 */

#include "Square.h"

Square :: Square(double s): side(s)
{
	setLength(side);
	setWidth(side);
}

double Square :: getSide() const
{
	return side;
}

double Square :: setSide(double s)
{
	setLength(s);
	setWidth(s);
	return side = s;
}