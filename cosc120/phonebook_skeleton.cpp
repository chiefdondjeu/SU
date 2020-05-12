
// Name: Florent Dondjeu Tschoufack


#include <fstream>
#include<iostream>
using namespace std;

enum Choice {LETTER,NUMBER,QUIT};

const int NAME_LEN = 20;

/* typedef is an indirect way of type declaration.
* e.g., in the Entry structure, name is a type of
* Name, which is simplay a character array.
*/
typedef char Name[NAME_LEN+1];

struct Entry {
  Name name;
  int  PN;
};

//Pre: file "phonenum.txt" must be in directory
//Post: opens file, reads all name/phone-number pairs,
//      and returns how many there were.
int ReadPNs(Entry[]);


//Post: prints out the names of the people with that phone number.
//      prints nothing if that number isn't in the list.
void NumList(const Entry[], int size, int num);

//Post: prints all the name/phone number pairs of everyone whose
//      name starts with that letter.
void LetterList(const Entry[], int size, char ch);

//Pre: int must be at most 7 digits
//Post: prints out as 7-digit phone number in the format of xxx-xxxx;
//if a phone number is less than 7 digits, padding 0s in the front.
void ShowPN(int n);


//Post: prints the menu
void Menu();


int main()
{

  Entry L[50];
  int size, numChoice;
  char ch;
  int num;

  size = ReadPNs(L);
  numChoice=0;
  while (numChoice != QUIT + 1) {
    Menu();
    cin >> numChoice;
    switch (numChoice) {
    case  LETTER+1 :
      cout << "Enter initial:";
      cin >> ch;
      LetterList ( L, size, ch );
      break;
    case  NUMBER+1:
      cout << "Enter number as 7 digits:";
      cin >> num;
      NumList ( L, size, num );
      break;
    case QUIT+1:
      cout << "Thank you!" << endl;
      break;
    default:
      cerr << "Not an Option!" << endl;
      break;
    }
  }
  return 0;
}

void NumList(const Entry L[],int size,int num)
{
    for(int i=0; i<size; i++)
    {
        if(num==L[i].PN)
        {
            cout << L[i].name << endl;
        }
    }

}

void LetterList(const Entry L[],int size,char ch)
{
    int n;
    for(int i=0; i<size; i++)
    {
        if(L[i].name[0]==ch)
        {
            n=L[i].PN;
            cout << L[i].name << " ";
            ShowPN(n);
        }
    }

}

void ShowPN(int n)
{
    int temp=n, counter=0, mod=10;
    while(n!=temp)
    {
        temp%=mod;
        mod*=10;
        counter++;
    }
    if(counter<7)
    {
        int n1=0,n2,n3,n4,n5,n6,n7;
        n7 = n%10;
        n6 = ((n%100)-n7)/10;
        n5 = ((n%1000)-(n%100))/100;
        n4 = ((n%10000)-(n%1000))/1000;
        n3 = ((n%100000)-(n%10000))/10000;
        n2 = ((n%1000000)-(n%100000))/100000;
        n1 = 0;
        cout << n1 << n2 << n3 << "-" << n4 << n5 << n6 << n7 << endl;
    }
    if(counter==7)
    {
        cout << ((n-(n%100000))/10000) << "-" << n%100000 << endl;
    }
}

int ReadPNs(Entry L[])
{
    int i=0;
    ifstream infile;
    infile.open("phonenum.txt");
    while(!infile.eof())
    {
        infile >> L[i].name;
        infile >> L[i].PN;
        i++;
    }
    return i;

}

void Menu()
  {cout<<endl;
   cout<<"Enter "<<LETTER+1<<" to look up names starting"
       <<" with a certain letter\n";
   cout<<"      "<<NUMBER+1<<" to look up a number\n";
   cout<<"      "<<QUIT+1<<" to quit\n";
   cout<<"    ";
  }


