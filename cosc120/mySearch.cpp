#include <iostream>
using namespace std;

bool searchId(int *uid, int nid, int sid);

int main()
{
    int numId, id, searchid;
    bool check;
    cout << "Please in put the number of id numbers to be read" << endl;
    cin >> numId;
    int *usersId=new int[numId];
    for(int i=0; i<numId; i++)
    {
        cout << "Please enter an id number\n";
        cin >> id;
        usersId[i]=id;
    }
    cout << "\nPlease input an id to be searched\n";
    cin >> searchid;
    check=searchId(usersId, numId, searchid);
    if(check==true)
    {
        cout << searchid << " is in the array" << endl;
    }
    if(check==false)
    {
        cout << searchid << " is not in the array" << endl;
    }
    delete []usersId;
    usersId=NULL;

    return 0;
}

bool searchId(int *uid, int nid, int sid)
{
    for(int i=0;i<nid;i++)
    {
        if(sid==uid[i])
        {
            return true;
        }
    }
    return false;
}
