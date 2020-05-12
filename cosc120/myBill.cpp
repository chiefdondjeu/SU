// This program will read in the quantity of a particular item and its price.
// It will then print out the total price.
// The input will come from the keyboard and the output will go to
// the screen.

// Florent Dondjeu Tschoufack

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int	quantity;		// contains the amount of items purchased
	float itemPrice;	// contains the price of each item
	float totalBill;	// contains the total bill.
	string itemName;

	cout << "Please input the name of item" << endl;
	getline(cin, itemName);

	cout << setprecision(2) << fixed << showpoint;	// formatted output
	cout << "Please input the number of items bought" << endl;

	cin >> quantity;

	cout << "Please input the price of each item" << endl;

	cin >> itemPrice;

	totalBill = quantity*itemPrice;

	cout << "\nThe item you bought is " << itemName << endl;
	cout << "The total bill is $" << totalBill << endl;
	// with a label to the screen.

	return 0;
}
