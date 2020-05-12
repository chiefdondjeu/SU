/*
 *Circle.h
 *Derived class from Shape class
 *Author: Florent Dondjeu Tschoufack
 *created: September 13, 2019
 *current: October 1, 2019
 */

#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape
{
	private:
		double radius;
	public:
		Circle(double r = 0.0);
			//initialize radius

		double getRadius() const;
			//returns the raduis

		double calcArea();
			//calcArea
			//calculate the area of the circle
			//parameter: none
			//return: area of circle
			//precondition: none
			//postcondition: returns the area of the circle

		bool doesItFit();
			//doesItFit
			//checks if the circle fits in the surface, relocates its center if need be or throw an error
			//parameter: none
			//returns true if circle fits without relocating its center
			//precondition: the circle has a radius and center coordinate
			//postcondition: The circle either fits or its center gets relocated else get an error
};

#endif