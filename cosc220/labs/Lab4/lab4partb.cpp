#include <iostream>
#include "complexx.h"
using namespace std;

int main()
{
  complexx num1, num2, result;  //num1 is the first complex number and
                          //num2 is the second complex number
  cout << "\n***First complex number***" << endl;
  cin >> num1;
  cout << "***Second complex number***" << endl;
  cin >> num2;

  if(num1 == num2)
  {
    cout << "\nThe complex numbers are equal." << endl;
  }
  else cout << "\nThe complex numbers are not equal." << endl;

  cout << "\nThe addition of the complex numbers are: ";
  result = num1+num2;
  cout << result;

  cout <<"\nThe subraction of the complex numbers are: ";
  result = num1-num2;
  cout << result;

  cout << "\nThe multiplication of the complex numbers are: ";
  result = num1*num2;
  cout << result;

  cout << "\nThe division of the complex numbers are: ";
  result = num1/num2;
  cout << result;

  cout << "\n\nThe Program is over. Thank you for your time!\n" << endl;

  return 0;
}
