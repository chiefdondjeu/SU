/*
 *Center.cpp
 *Definition of Center class
 *Author: Florent Dondjeu Tschoufack
 *created: September 13, 2019
 *current: September 28, 2019
 */

#include "Center.h"


Center :: Center(): x_coord(0), y_coord(0)
{

}

Center :: Center(double x, double y): x_coord(x), y_coord(y)
{

}

double Center :: getX() const
{
	return x_coord;
}

double Center :: getY() const
{
	return y_coord;
}

double Center :: setX(double x)
{
	return x_coord = x;
}

double Center :: setY(double y)
{
	return y_coord = y;
}