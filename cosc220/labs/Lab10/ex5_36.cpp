/*
  ex5_36.cpp
  Exercise 36, Chapter 5, Ford/Topp "Data Structures With C++ using STL"
  For Cosc-220  Lab
  Thomas Anastasio
  Created: November 5, 2002
  Current: November 5, 2002
*/

/********************  as provided on K drive *****************/

#include "d_rect.h"
#include "ex5_36Aux.h"

int main()
{
  using namespace std;

  rectangle ** rooms = getRoomArray();

  getRoomData(rooms);

  reportOnTotalArea(rooms);
  
  rectangle largePerim = largestPerimeter(rooms);
  
  reportOnLargest(largePerim);


  return 0;
}

