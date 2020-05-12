#ifndef BAR_H
#define BAR_H

class Bar
{
 public:
  Bar(float x = 3.0f);

  float getY() const;

 private:
  float y;
};

#endif