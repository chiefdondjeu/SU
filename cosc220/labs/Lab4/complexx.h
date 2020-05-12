#ifndef COMPLEXX_H
#define COMPLEXX_H
#include <iostream>
using namespace std;

class complexx
{
private:
double real; //real part
double imag; //complex part

public:
//complexx();

complexx(double x = 0.0, double y = 0.0);


// return the real part of the complex number
double realPart() const;


// return the imaginary part of the complex number
double imagPart() const;


// addition of complex numbers
//rhs - imaginary#
//lhs - real#
complexx operator+ (const complexx& rhs);

// division of complex numbers
complexx operator/ (const complexx& rhs);

// negation of a complex number
complexx operator- () const;


// subtraction of complex numbers
friend complexx operator- (const complexx& lhs, const complexx& rhs);


// comparison of complex numbers
friend bool operator== (const complexx& lhs, const complexx& rhs);


// stream input in format (real,imag)
friend istream &operator>> (istream& istr,complexx& x);
};


// multiplication of complex numbers
complexx operator* (const complexx& lhs, const complexx& rhs);

// stream output in format (real,imag)
ostream &operator<< (ostream& ostr, const complexx& x);

#endif
