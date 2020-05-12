/*
 *Square.h
 *Derived class from Rectangle class
 *Author: Florent Dondjeu Tschoufack
 *created: September 13, 2019
 *current: September 29, 2019
 */

#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"
#include "Rectangle.h"

class Square : public Rectangle
{
	private:
		double side;
	public:
		Square(double s = 0.0);
			//initialize side to s

		double getSide() const;
			//return the value of side

		double setSide(double s);
			//used to change the value of side

		/*
		 *We do not need to implement area() and doesItFit() because a Square is a type of Rectangle
		 *the functions would mirror each other. A Square obj can access those functions from the 
		 *Rectangle class since they are inherited.
		 */
};

#endif