#include "time24Aux.h"

bool isLater(const time24& t1, const time24& t2)
{
  int h1, h2, m1, m2;
  h1 = t1.getHour();
  h2 = t2.getHour();
  m1 = t1.getMinute();
  m2 = t2.getMinute();

  m1 += (h1*60);
  m2 += (h2*60);

  if(m1 <= m2)
  {
    return false;
  }
  else return true;
}
