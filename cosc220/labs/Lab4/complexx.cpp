#include <iostream>
#include "complexx.h"
using namespace std;

/*complexx :: complexx()
{
  //double x = 0.0;
  //double y = 0.0;
  real = 0.0;
  imag = 0.0;
}*/

complexx :: complexx(double x, double y)
{
  real = x;
  imag = y;
}

double complexx :: realPart() const
{
  return real;
}

double complexx :: imagPart() const
{
  return imag;
}

complexx complexx :: operator+ (const complexx& rhs)
{
  double tempReal = realPart() + rhs.realPart();
  double tempImag = imagPart() + rhs.imagPart();
  return complexx(tempReal,tempImag);
}

complexx complexx :: operator/ (const complexx& rhs)
{
    double tempReal = (real*rhs.realPart() + imag*rhs.imagPart()) / (rhs.realPart()*rhs.realPart() + rhs.imagPart()*rhs.imagPart());
    double tempImag = (imag*rhs.realPart() - real*rhs.imagPart()) / (rhs.realPart()*rhs.realPart() + rhs.imagPart()*rhs.imagPart());
    return complexx(tempReal, tempImag);
}

complexx complexx :: operator- () const
{
    double tempReal = -real;
    double tempImag = -imag;
    return complexx(tempReal,tempImag);
}

complexx operator- (const complexx& lhs, const complexx& rhs)
{
  double tempReal = lhs.realPart() - rhs.realPart();
  double tempImag = lhs.imagPart() - rhs.imagPart();
  return complexx(tempReal, tempImag);
}

bool operator== (const complexx& lhs, const complexx& rhs)
{
  if(lhs.realPart() == rhs.realPart() && lhs.imagPart() == rhs.imagPart())
  {
    return true;
  }
  else return false;
}

istream &operator>> (istream& istr,complexx& x)
{
   double a,b;
   char para, comma;
   cout << "Enter a complex number (real,imag): ";
   istr >> para >> a >> comma >> b >> para;
   x.real = a;
   x.imag = b;
   return istr;
}

//free functions
complexx operator* (const complexx& lhs, const complexx& rhs)
{
  double tempReal = (lhs.realPart()*rhs.realPart()) - (lhs.imagPart()*rhs.imagPart());
  double tempImag = (lhs.realPart()*rhs.imagPart()) + (lhs.imagPart()*rhs.realPart());
  return complexx(tempReal, tempImag);
}

ostream &operator << (ostream& ostr, const complexx& x)
{
  ostr << "(" << x.realPart() << "," << x.imagPart() << ")";
  return ostr;
}
