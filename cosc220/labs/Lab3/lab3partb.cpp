#include <iostream>
#include "time24.h"
#include "time12.h"

using namespace std;

int main()
{
	time12 NY(12, 0, AM);
	cout << "Time in New York: ";
	NY.writeTime();
	NY.addTime(360);
	cout << "Time in Frankfurt, Germany: ";
	NY.writeTime();

	return 0;
}