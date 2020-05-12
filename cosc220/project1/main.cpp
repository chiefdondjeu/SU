/*
 *main.cpp
 *Run the program
 *Author: Florent Dondjeu Tschoufack
 *created: September 13, 2019
 *current: October 1, 2019
 */

#include <iostream>
#include <string>

#include "Center.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"

int main()
{
	std :: cout << "\n";

	std :: cout << "********************************************************************\n";
	std :: cout << "**                           SHAPE FUN                            **\n";
	std :: cout << "********************************************************************\n";

	char para, comma;
		//variable to help read in user input. Para reads in parentheses, comma reads in comma
	double x, y;
		// variable for center
	std :: string choice, choice2;
		//choice is for user type of shape
		//choice2 is for the continuation of the program
	bool end = false;
		//when end is changed to true program cannot output the are and center coord
		//because the shape cannot be fitted in the surface
	bool goAgain = true;
		//for when the user wants to keep running the program

	while(goAgain != false)
	{
		std :: cout << "\n\tInput a shape (circle, rectangle, or square): ";
		std :: cin >> choice;

		end = false;

		if(choice == "circle")	//******************************************************************************************************************************************
		{
			double r;
				//variable for radius
			std :: cout << "\n\tEnter the radius of the circle: ";
			std :: cin >> r;

			Circle sc(r);
				//Circle object. sc = shape cirlce
			Shape *Cptr = &sc;
				//Shape object pointer points to Circle object
			std :: cout << "\tEnter the center coordinate of the cirlce (x,y): ";
			std :: cin >> para >> x >> comma >> y >> para;
			Cptr->moveCenter(x,y);

			try
			{
				Cptr->doesItFit();
					//checks if the circle fits in the surface
			}

			catch(std :: string CnoFit)
				//circle cannot fit but can be relocated
			{
				std :: cout << "\n";
				std :: cout << CnoFit;
				std :: cout << "\t\t\bThe center has been relocated.\n";
				end = false;
			}

			if(Cptr->doesItFit() == false)
				//when the circle absolutetly cannot be fitted
			{
				std :: cout << "\n\tERROR: Radius is too Big.\n\t\t\bShape cannot be fitted in the surface.\n\n";
				end = true;
					//set to true so the area and center coordinate are no printed
			}

			if(end == false)
			{
				std :: cout << "\n";
				Cptr->display();
			}
		}


		else if(choice == "rectangle")	//**********************************************************************************************************************************
		{
			double l, w;
				//variable for length & width
			std :: cout << "\n\tEnter the length of the rectangle: ";
			std :: cin >> l;

			std :: cout << "\tEnter the width of the rectangle: ";
			std :: cin >> w;

			Rectangle sr(l, w);
				//Rectangle object. sr = shape rectangle
			Shape *Rptr = &sr;
				//Shape object pointer points to Rectangle object
			std :: cout << "\tEnter the center coordinate of the rectangle (x,y): ";
			std :: cin >> para >> x >> comma >> y >> para;
			Rptr->moveCenter(x,y);

			try
			{
				Rptr->doesItFit();
					//check if rectangle can fit in the surface
			}

			catch(std :: string RnoFit)
				//when the rectangle does not fit in surface but can be relocated
			{
				std :: cout << "\n";
				std :: cout << RnoFit;
				std :: cout << "\t\t\bThe center has been relocated.\n";
				end = false;
			}

			if(Rptr->doesItFit() == false)
				//when the rectangle absolutly cannot be fitted
			{
				std :: cout << "\n\tERROR: Measurements are too long.\n\t\t\bRectangle cannot be fitted in the surface.\n\n";
				end = true;
					//changed to true so the area and center are no printed
			}

			if(end == false)
			{
				std :: cout << "\n";
				Rptr->display();
			}
		}


		else if(choice == "square")	//**************************************************************************************************************************************
		{
			double sideL;
				//variable for side length of square
			std :: cout << "\n\tEnter the side length of the square: ";
			std :: cin >> sideL;

			Square ss(sideL);
				//Square object. ss = shape square
			Shape *Sptr = &ss;
				//Shape pointer object points to square object

			std :: cout << "\tEnter the center coordinate of the Square (x,y): ";
			std :: cin >> para >> x >> comma >> y >> para;
			Sptr->moveCenter(x,y);

			try
			{
				Sptr->doesItFit();
					//checks if square can fit in the surface
			}

			catch(std :: string RnoFit)
				//when square does not fit in surface but can be relocated
			{
				std :: cout << "\n";
				std :: cout << RnoFit;
				std :: cout << "\t\t\bThe center has been relocated.\n";
				end = false;
			}

			if(Sptr->doesItFit() == false)
				//when the square absolutly cannot be fitted
			{
				std :: cout << "\n\tERROR: Measurements are too long.\n\t\t\bSquare cannot be fitted in the surface.\n\n";
				end = true;
			}

			if(end == false)
			{
				std :: cout << "\n";
				Sptr->display();
			}

		}

		std :: cout << "********************************************************************";
		std :: cout << "\n\tDo you want to try other shapes (yes or no): ";
		std :: cin >> choice2;

		if(choice2 == "no")
		{
			goAgain = false;
				//changed to false so the program can end
		}

	}

	std :: cout << "\n\t\t\tProgram ended.\n";
	std :: cout << "********************************************************************\n\n";
	return 0;
}
