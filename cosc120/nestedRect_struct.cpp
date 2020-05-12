#include <iostream>
#include <iomanip>
using namespace std;

// This program uses a structure to hold data about a rectangle
// It calculates the area and perimeter of a box

// Florent Dondjeu Tschoufack

struct dimensions
{
    float length;
    float width;
};
struct results
{
    float area;
    float perimeter;
};
struct rectangle
{
    results attributes;
    dimensions sizes;
};

float getArea(float L, float W);
float getPerimeter(float L2, float W2);

int main()
{
	rectangle box;

	cout << "Enter the length of a rectangle: ";

	cin >> box.sizes.length;

	cout << "Enter the width of a rectangle: ";

	cin >> box.sizes.width;

	cout << endl << endl;

	box.attributes.area = getArea(box.sizes.length, box.sizes.width);

	box.attributes.perimeter = getPerimeter(box.sizes.length, box.sizes.width);

	cout << fixed << showpoint << setprecision(2);

	cout << "The area of the rectangle is " << box.attributes.area << endl;

	cout << "The perimeter of the rectangle is " << box.attributes.perimeter
		 << endl;

	return 0;
}

float getArea(float L, float W)
{
    return L*W;
}

float getPerimeter(float L2, float W2)
{
    return (2*L2)+(2*W2);
}
