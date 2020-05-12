/*
 *Shape.h
 *Base class
 *Author: Florent Dondjeu Tschoufack
 *created: September 13, 2019
 *current: October 1, 2019, 2019
 */

#ifndef SHAPE_H
#define SHAPE_H

#include "Center.h"
#include <iostream>

class Shape
{
	protected:
		Center coordinate;		
			//made protected so the derived class can access it in order to implement the virtual functions

	public:
		Shape(double x = 0.0, double y = 0.0);
			//initialize center object private member

		void moveCenter(double x, double y);
			//moveCenter
			//changes the center coordinates
			//parameter: x is the new x center coordinate and y is the new y center coordinate
			//returns: none
			//precondition: none
			//postcondition: values of x_coord and y_coord changed

		virtual void display();	
			//display
			//prints out the area of a shape and the shape center coordinate
			//parameter: none
			//returns: none
			//precondition: the shape can be fitted in the surface
			//postcondition: the area and center coordinate is to be printed out

		virtual double calcArea() = 0;
			//CalcArea
			//calculates the are of the shape
			//parameter: none
			//returns: the area of a shape
			//precondition: every shape must implement its own calcArea
			//postcondition: the area of the shape is to be returned

		virtual bool doesItFit() = 0;
			//doesItFit
			//checks if the shape fits in grid (-10<x<10 and -5<y<5) and relocates the center if it does not, else it throw an error that the shape cannot fit
			//parameter: none
			//returns true when shape fits without being relocated
			//precondition: type of shape as been chose
			//postcondition: The shape either fit or its center gets relocated else get an error

		friend std :: ostream &operator<<(std :: ostream& out, const Center& c);
			//operator<<
			//overload the cout operator so the center coordinate can be printed out like (x,y)
			//parameter: reference of ostream object called out and reference of center object called c 
			//returns: return ostream object
			//precondition: none
			//postcondition: the center is to be printed in format (x,y)

};

#endif