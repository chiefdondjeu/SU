#include <iostream>
#include "time24.h"
#include "time24Aux.h"
using namespace std;

int main()
{
  time24 clock(9,0);
  clock.writeTime();
  time24 end(17,0);
  while(isLater(clock, end) == false)
  {
    clock.addTime();
    clock.writeTime();
  }
  cout << "Final time: ";
  clock.writeTime();

  return 0;
}
