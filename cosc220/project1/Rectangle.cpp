/*
 *Rectangle.cpp
 *Definition of Rectangle class
 *Author: Florent Dondjeu Tschoufack
 *created: September 13, 2019
 *current: October 1, 2019
 */

#include "Rectangle.h"
#include <string>

Rectangle :: Rectangle(double l, double w): length(l), width(w)
{

}

double Rectangle :: getLength() const
{
	return length;
}

double Rectangle :: getWidth() const
{
	return width;
}

double Rectangle :: setLength(double l)
{
	return length = l;
}

double Rectangle :: setWidth(double w)
{
	return width = w;
}

double Rectangle :: calcArea()
{
	return length * width;
}

bool Rectangle :: doesItFit()
{
	std :: string RnoFit = "\tERROR: Shape does not fit in the surface.\n";

	if(length > 20 || width > 10)
	{
		return false;
			//returns false because reactangle/square absolutly cannot fit in the surface
	}

	//std :: string RnoFit = "ERROR: Shape does not fit in the surface.\n";
	double pt1x, pt1y, pt3x, pt3y, difference, cx, cy;
	bool fit = true;
		//if any of the the center coordinates are changed this will help us
		//throw the error after the center has been relocated

	cx = coordinate.getX();
	cy = coordinate.getY();
		//center coordinates

	pt1x = coordinate.getX() + (length / 2);	//					* * * * * * *	<- pt1x, pt1y
	pt1y = coordinate.getY() + (width / 2);		//					*			*
		//top right corner coordinates			//					*	  *		*
												//					*			*
	pt3x = coordinate.getX() - (length / 2);	//	pt3x, pt3y ->	* * * * * * *
	pt3y = coordinate.getY() - (width / 2);
		//bottom left coordinates

	if(pt1x > 10 || pt1y > 5)
	{
		if(pt1x > 10)
		{
			difference = pt1x - 10;
			cx -= difference;
				//moves center to the left
			moveCenter(cx, cy);
		}
		else if(pt1y > 5)
		{
			difference = pt1y - 5;
			cy -= difference;
				//moves the center down
			moveCenter(cx, cy);
		}
		fit = false;
	}

	if(pt3x < -10 || pt3y < -10)
	{
		if(pt3x < -10)
		{
			difference = -10 - pt3x;
			cx += difference;
				//moves the center to the right
			moveCenter(cx, cy);
		}
		else if(pt3y < -5)
		{
			difference = -5 - pt3y;
			cy += difference;
				//moves the center up
			moveCenter(cx, cy);
		}
		fit = false;
	}

	if(fit != true)
	{
		throw RnoFit;
			//lets the user know rectangle could not fit and the center can be relocated
	}
	else return true;
		//if no problem occured
}
