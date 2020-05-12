#include <iostream>
#include <iomanip>
using namespace std;

// This program uses a structure to hold data about a rectangle

// Florent Dondjeu Tschoufack

struct rectangle
{
    float length;
    float width;
    float area;
    float perimeter;
};

int main()
{
	rectangle box;

	cout << "Enter the length of a rectangle: ";

	cin >> box.length;

	cout << "Enter the width of a rectangle: ";

	cin >> box.width;

	cout << endl << endl;

	box.area = (box.length)*(box.width);

	box.perimeter = 2*(box.length)+2*(box.width);

	cout << fixed << showpoint << setprecision(2);

	cout << "The area is of the rectangle is " << box.area << endl;

	cout << "The perimeter of the rectangle is " << box.perimeter << endl;

	if(box.length == box.width)
    {
        cout << "It's a square." << endl;
    }
    else cout << "It's a rectangle." << endl;

	return 0;
}
