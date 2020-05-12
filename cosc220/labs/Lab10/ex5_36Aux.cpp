#include "ex5_36Aux.h"
#include <iostream>

rectangle ** getRoomArray()
{
	rectangle ** arrPtr;

	int r;
	std :: cout << "How many rooms? ";
	std :: cin >> r;
  r++;

  arrPtr = new rectangle*[r];
  for(int i = 0; i < r-1; i++)
  	arrPtr[i] = new rectangle;

  arrPtr[r-1] = NULL;

  return arrPtr;
}

// getRoomData
// PreCondition:  rooms is a properly constructed array of pointers 
// to rectangle (see documentation for getRoomArray)
// Prompts for length and width of each room (i.e. rectangle) and gets those 
// data from the keyboard.
// PostCondition: each room has received its length and width from the keyboard
void getRoomData(rectangle ** rooms)
{
	double l,w;

	int i = 0;
	while(rooms[i] != NULL)
	{
		std :: cout << "length and width Room#" << i << " ";
		std :: cin >> l >> w;
		rooms[i]->setSides(l,w);
		i++;
	}

}

// getTotalArea
// Returns the total area of the rooms on the array of pointers to rectangle.
// Precondition: the array is properly constructed (see documentation for getRoomArray)
double getTotalArea(rectangle ** rooms)
{
	double total;

	int i = 0;
	while(rooms[i] != NULL)
	{	
		total += rooms[i]->area();
		i++;
	}

	return total;
}

// largestPerimeter
// Returns a copy of the room that has the largest perimeter of all the rooms.
// Precondition: rooms is properly constructed (see documentation for getRoomArray) 
rectangle largestPerimeter(rectangle ** rooms)
{	
	double l, w, check, highest = rooms[0]->perimeter();

	int i = 1;
	while(rooms[i] != NULL)
	{
		check = rooms[i]->perimeter();
		if(check > highest)
		{
			highest = rooms[i]->perimeter();
			l = rooms[i]->getLength();
			w = rooms[i]->getWidth();
		}
		i++;
	}

	return rectangle(l,w);
}

// reportOnLargest
// Prints a report on largeRoom.
// The report gives the perimeter of largeRoom as well as its dimensions.
void reportOnLargest(rectangle & largeRoom)
{
	std :: cout << "Largest Room" << std :: endl;
	std :: cout << "perimeter " << largeRoom.perimeter() << std :: endl;
	std :: cout << "length " << largeRoom.getLength() << std :: endl;
	std :: cout << "width " << largeRoom.getWidth() << std :: endl;
}

// reportOnTotalArea
// Prints a report on the total area in rooms.
// Precondition: rooms is properly constructed (see documentation for getRoomArray)
void reportOnTotalArea(rectangle ** rooms)
{
	double total;

	int i = 0;
	while(rooms[i] != NULL)
	{
		total += rooms[i]->area();
		i++;
	}

	std :: cout << "Total area " << total << std :: endl;
}