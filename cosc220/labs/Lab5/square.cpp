#include "square.h"

Square :: Square(double s)
{
  setLength(s);
  setWidth(s);
}

double Square :: setSide(double s)
{
  setLength(s);
  return setWidth(s);  //do both so we can use the calc func
}

double Square :: getSide()
{
  return getlength();   //could also be getWidth()
}
