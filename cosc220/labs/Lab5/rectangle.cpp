#include "rectangle.h"

Rectangle :: Rectangle(double l, double w): length(l), width(l)
{

}

double Rectangle :: setLength(double l)
{
  return length = l;
}

double Rectangle :: setWidth(double w)
{
  return width = w;
}

double Rectangle :: getlength() const
{
  return length;
}

double Rectangle :: getWidth() const
{
  return width;
}

double Rectangle :: getPerimeter()
{
  return 2 * (length + width);
}

double Rectangle :: getArea()
{
  return length * width;
}
