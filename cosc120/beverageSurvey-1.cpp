//Florent Dondjeu Tschoufack
#include <iostream>
using namespace std;

int main()
{
    //while(!cin.fail)
    cout << "1.Coffee   2.Tea   3.Coke  4.Orange Juice" << endl;
    int choice = 0;
    int coffee = 0;
    int tea = 0;
    int coke = 0;
    int orangejuice = 0;
    int counter = 0;
    do
    {
        cout << "\nPlease input the favorite beverage of person #" << ++counter <<": Choose 1, 2, 3, or 4 from\nabove menu or -1 to exit the program:" << endl;
        cin >> choice;
        if(choice==1)
        {
            coffee++;
        }
        if(choice==2)
        {
            tea++;
        }
        if(choice==3)
        {
            coke++;
        }
        if(choice==4)
        {
            orangejuice++;
        }
        while(choice > 4)
        {
            cout << "\nThat is not an option." << endl;
            cout << "\nPlease input the favorite beverage of person #" << counter <<": Choose 1, 2, 3, or 4 from\nabove menu or -1 to exit the program:" << endl;
            cin >> choice;
            if(choice==1)
            {
                coffee++;
            }
            if(choice==2)
            {
                tea++;
            }
            if(choice==3)
            {
                coke++;
            }
            if(choice==4)
            {
                orangejuice++;
            }
        }
    } while(choice !=-1);

    cout << "\nThe total number of people surveyed is " << counter-1 << ". The results are as follows: " << endl;
    cout << "\nBeverages\tNumber of Votes\n********************************" << endl;
    cout << "Coffee\t\t" << coffee << "\nTea\t\t" << tea << "\nCoke\t\t" << coke << "\nOrange Juice\t" << orangejuice << endl;

    return 0;
}
