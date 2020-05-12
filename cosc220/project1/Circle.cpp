/*
 *Circle.cpp
 *Definition of Circle class
 *Author: Florent Dondjeu Tschoufack
 *created: September 13, 2019
 *current: October 1, 2019
 */

#include "Circle.h"
#include <cmath>
#include <string>

Circle :: Circle(double r) : radius(r)
{

}

double Circle :: getRadius() const
{
	return radius;
}

double Circle :: calcArea()
{
	return M_PI * (radius * radius);
}

bool Circle :: doesItFit()
{
	//std :: string RadException = "ERROR: Radius is too Big.\nShape cannot be fitted int the grid.\n";
	std :: string CnoFit = "\tERROR: Circle does not fit in the grid.\n";

	if(radius > 5)
	{
		//throw RadException;
		return false;
	}

	//std :: string CnoFit = "ERROR: Circle does not fit in the grid.\n";
	double ptx1, ptx3, pty2, pty4, difference, cx, cy;
	bool fit = true;
		//if any of the the center coordinates are changed this will help us
		//throw the error after the center has been relocated

	cx = coordinate.getX();
	cy = coordinate.getY();
		//center coordinates
	ptx1 = coordinate.getX() + radius;	//				* <- pty2
	ptx3 = coordinate.getX() - radius;	//			 *	   *
										//	ptx3 ->	*	*	* <- ptx1
	pty2 = coordinate.getY() + radius;	//			 *	   *
	pty4 = coordinate.getY() - radius;	//				* <- ptry4

	if(ptx1 > 10 || ptx3 < -10)
	{
		if(ptx1 > 10)
		{
			difference = ptx1 - 10;
			cx -= difference;
				//moves center to the left
			moveCenter(cx, cy);

		}
		else if(ptx3 < -10)
		{
			difference = -10 - ptx3;
			cx += difference;
				//moves center to the right
			moveCenter(cx, cy);
		}
		fit = false;
	}

	if(pty2 > 5 || pty4 < -5)
	{

		if(pty2 > 5)
		{
			difference = pty2 - 5;
			cy -= difference;
				//moves the center down
			moveCenter(cx, cy);
		}
		else if(pty4 < -5)
		{
			difference = -5 - pty4;
			cy += difference;
				//moves the center up
			moveCenter(cx, cy);
		}
		fit = false;
	}

	if(fit != true)
	{
		throw CnoFit;
	}
	else return true;

}
