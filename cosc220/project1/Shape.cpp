/*
 *Shape.cpp
 *Definition of Shape class
 *Author: Florent Dondjeu Tschoufack
 *created: September 13, 2019
 *current: September 29, 2019
 */

#include "Shape.h"
#include <iostream>

Shape :: Shape(double x, double y)
{
	coordinate.setX(x);
	coordinate.setY(y);
}

void Shape :: moveCenter(double x, double y)
{
	coordinate.setX(x);
	coordinate.setY(y);
}

std :: ostream &operator<<(std :: ostream& out, const Center& c)
	//function has to be implemented before display() since display() will use the operator to cout a center object
{
	out << "(" << c.getX() << "," << c.getY() << ")" << std :: endl;
	return out;
}

void Shape :: display()
{
	std :: cout << "\tArea: " << calcArea() << "\n\tCenter: " << coordinate << std :: endl;
}
