
//Florent Dondjeu Tschoufack

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int totalSales;
    float stateTaxPerc,localTaxPerc, stateTax, localTax;

    cout << setprecision(2) << fixed <<showpoint;

    cout << "Please input the total sales for the month" << endl;
    cin >> totalSales;

    cout << "Please input the state tax percentage in decimal form (0.2 for 2%)" << endl;
    cin >> stateTaxPerc;

    cout << "Please input the local tax percentage in decimal form (0.2 for 2%)" << endl;
    cin >> localTaxPerc;

    stateTax = totalSales*stateTaxPerc;
    localTax = totalSales*localTaxPerc;

    cout << "\nThe total sales for the month is $" << totalSales << endl;
    cout << "The state tax for the month is $" << stateTax << endl;
    cout << "The local tax for the month is $" << localTax << endl;

    return 0;
}
