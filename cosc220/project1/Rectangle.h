/*
 *Rectangle.h
 *Derived class from Shape class
 *Author: Florent Dondjeu Tschoufack
 *created: September 13, 2019
 *current: October 1, 2019
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape
{
	private:
		double length;
		double width;
	public:
		Rectangle(double l = 0.0, double w = 0.0);
			//initialize length to l and width to w

		double getLength() const;
			//returns the value of length

		double getWidth() const;
			//returns the value of width

		double setLength(double l);
			//used to change value of length

		double setWidth(double w);
			//used to change value of width

		double calcArea();
			//calcArea
			//calculate the area of the rectangle/square
			//parameter: none
			//return: area of rectangle/square
			//precondition: none
			//postcondition: returns the area of the rectangle/square

		bool doesItFit();
			//doesItFit
			//checks if the rectangle/square fits in the surface, relocates its center if need be or throw an error
			//parameter: none
			//returns true if rectangle/square fits without relocating its center
			//precondition: the rectangle/square has a length&witdh and center coordinate
			//postcondition: The rectangle/square either fits or its center gets relocated else get an error
};

#endif