#include <iostream>
#include <iomanip>
using namespace std;

// This program demonstrates how to use an array of structures

// Florent Dondjeu Tschoufack

struct taxPayer
{
    float taxRate;
    float income;
    float taxes;
};

int main()
{
	taxPayer citizen[5];

	cout << fixed << showpoint << setprecision(2);

	cout << "Please enter the annual income and tax rate for 5 tax payers: ";
	cout << endl << endl << endl;

	for (int count = 0; count < 5; count++)
	{
		cout << "Enter this year's income for tax payer " << (count + 1);
		cout << ": ";

		cin >> citizen[count].income;

		cout << "Enter the tax rate for tax payer # " << (count + 1);
		cout << ": ";

		cin >> citizen[count].taxRate;

		citizen[count].taxes = (citizen[count].income)*(citizen[count].taxRate);

		cout << endl;
	}

	cout << "Taxes due for this year: " << endl << endl;

	for(int index = 0; index < 5; index++)
	{
		cout << "Tax Payer # " << (index + 1) << ": " << "$ "
		     << citizen[index].taxes << endl;
	}

	return 0;
}
