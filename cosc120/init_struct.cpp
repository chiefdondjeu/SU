#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// This program demonstrates partially initialized structure variables

// Florent Dondjeu Tschoufack

struct taxPayer
{
	string name;
	long socialSecNum;
	float taxRate;
	float income;
	float taxes;
};

int main()
{
	taxPayer citizen1;
	citizen1.name = "Time McGuiness";
	citizen1.socialSecNum = 255871234;
    citizen1.taxRate = 0.35;

	taxPayer citizen2;
    citizen2.name = "John Kane";
    citizen2.socialSecNum = 278990582;
    citizen2.taxRate = 0.29;

	cout << fixed << showpoint << setprecision(2);

	// calculate taxes due for citizen1

	cout << "Please input the yearly income for Tim McGuiness: ";

	cin >> citizen1.income;

	citizen1.taxes = (citizen1.income)*(citizen1.taxRate);

	cout << "Name: " << citizen1.name << endl;

	cout << "Social Security Number: " << citizen1.socialSecNum << endl;

	cout << "Taxes due for this year: $" << citizen1.taxes << endl << endl;

	// calculate taxes due for citizen2

	cout << "Please input the yearly income for John Kane: ";

	cin >> citizen2.income;

	citizen2.taxes = (citizen2.income)*(citizen2.taxRate);

	cout << "Name: " << citizen2.name << endl;

	cout << "Social Security Number: " << citizen2.socialSecNum << endl;

	cout << "Taxes due for this year: $" << citizen2.taxes << endl << endl;

	return 0;
}
