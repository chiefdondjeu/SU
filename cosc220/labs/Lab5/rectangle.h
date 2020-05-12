#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
  private:
    double length, width;

  public:
    Rectangle(double l = 0.0, double w = 0.0);
    double setLength(double l);
    double setWidth(double w);
    double getlength() const;
    double getWidth() const;
    double getPerimeter();
    double getArea();
};

#endif
