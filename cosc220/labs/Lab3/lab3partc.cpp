#include <iostream>
#include "time24.h"
#include "time12.h"
using namespace std;

int main()
{
	time12 lab3t(12, 0, AM);
	cout << "Enter time at which the job begins: ";
	lab3t.readTime();
	lab3t.addTime(320);
	cout << "The job ends at ";
	lab3t.writeTime();
	cout << endl;

	return 0;
}
