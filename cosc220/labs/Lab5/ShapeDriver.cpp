#include <iostream>
#include "rectangle.h"
#include "square.h"
using namespace std;

int main()
{
  double l;
  cout << "\nWelcome!!\nEnter the length of a side of a Square: ";
  cin >> l;
  Square sq(l);
  cout << "The perimeter of the object is " << sq.getPerimeter() << " and the area is " << sq.getArea() << endl;
  cout << "\nThe length has been double" << endl;
  l*=2;
  sq.setSide(l);
  cout << "The new perimeter of the object is " << sq.getPerimeter() << " and the new area is " << sq.getArea() << endl;
  cout << "\nThe program is over." << endl;
  
  return 0;
}
