//Florent Dondjeu Tschoufack
#include <iostream>
using namespace std;

int main()
{
    char state, room;
    int bill = 0;

    cout << "Please input \"I\" if you are in-state or \"O\" if you are out-of-state: " << endl;
    cin >> state;
    if(state == 'I')
    {
        bill=+3000;
        cout << "\nPlease input \"Y\" if you require room and board and \"N\" if you do not: " << endl;
        cin >> room;
        if(room == 'Y')
        {
            cout << "\nYour total bill this semester is $" <<  bill+2500 <<endl;
        }
        else if(room == 'N')
        {
            cout << "\nYour total bill this semester is $" <<  bill <<endl;
        }

    }
    if(state == 'O')
    {
        bill=+4500;
        cout << "\nPlease input \"Y\" if you require room and board and \"N\" if you do nor: " << endl;
        cin >> room;
        if(room == 'Y')
        {
            cout << "\nYour total bill this semester is $" <<  bill+3500 <<endl;
        }
        else if(room == 'N')
        {
            cout << "\nYour total bill this semester is $" <<  bill <<endl;
        }

    }
    return 0;
}
