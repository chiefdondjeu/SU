#include "time24.h"
#include <iostream>
using namespace std;

time24 :: time24(int h, int m): hours(h), minutes(m)
{
  hours = h;
  minutes = m;
}

void time24 :: readTime()
{
	int h, m;
  char colon;
	cout << "Enter the time of the day ";
	cin >> h >> colon >> m;
	time24 time(h,m);
	addTime();
	writeTime();

}

void time24 :: writeTime()
{
  if(minutes < 10)
  {
    cout << hours << ":0" << minutes << endl;
  }
  else if(minutes >= 10)
  {
    cout << hours << ":" << minutes << endl;
  }
}

time24 time24 :: duration(const time24& t)
{
	int timeofday = (hours*60)+minutes;
	int t_time = (hours*60)+minutes;
	return time24(0, t_time-timeofday);
}

void time24 :: addTime()
{
	int add_time;
	cout << "Enter an increment in minutes: ";
	cin >> add_time;
	minutes+=add_time;
	normalizeTime();
}

int time24 :: getHour() const
{
  return hours;
}

int time24 :: getMinute() const
{
  return minutes;
}

void time24 :: normalizeTime()
{
	minutes += (hours*60); //convert hr to min and add the mins together
  hours = 0;
	hours = minutes/60; //sets the normal hour
  minutes %= 60; //sets the minute
}
