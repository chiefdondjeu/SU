/*
 *Center.h
 *Center class holds variable and functions to help determine the center of a shape
 *Author: Florent Dondjeu Tschoufack
 *created: September 13, 2019
 *current: September 27, 2019
 */

#ifndef CENTER_H
#define CENTER_H

class Center
{
	private:
		//Both made private so they cannot be easily changed
		double x_coord;
		double y_coord;
	public:
		Center();
			//initialize x_coord and y_coord to 0

		Center(double x, double y);
			//initialize x_coord to x and y_coord to y

		double getX() const;
			//return x_coord value

		double getY() const;
			//return y_coord value

		double setX(double x);
			//used to change value of x_coord

		double setY(double y);
			//used to change value of y_coord

};

#endif