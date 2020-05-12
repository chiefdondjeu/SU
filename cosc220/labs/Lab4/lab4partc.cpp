#include <iostream>
#include "complexx.h"
using namespace std;

complexx polynomialfunc(complexx &z);

int main()
{
  complexx num1(2,3), num2(-1,1), num3(1,-1), num4(1,0);

  cout << "\nComplex polynomial function"  << endl;
  cout << num1 << " the polynomial is " << polynomialfunc(num1) << endl;
  cout << num2 << " the polynomial is " << polynomialfunc(num2) << endl;
  cout << num3 << " the polynomial is " << polynomialfunc(num3) << endl;
  cout << num4 << " the polynomial is " << polynomialfunc(num4) << endl << endl;

  return 0;
}

complexx polynomialfunc(complexx &z)
{
  complexx temp;
  temp = ((z*z)*z)-(3*(z*z)) + (4*(z)) - 2;

  return temp;
}
