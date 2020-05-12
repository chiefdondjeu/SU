#ifndef SQUARE_H
#define SQUARE_H
#include "rectangle.h"

class Square : public Rectangle
{
  public:
    Square(double s = 0.0);
    double setSide(double s); //set value of length and width
    double getSide();
};

#endif
