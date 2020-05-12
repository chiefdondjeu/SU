#include "time24.h"
#include <iostream>
using namespace std;

time24 :: time24(int h, int m): hours(h), minutes(m)
{}

void time24 :: readTime()
{
	/*
	int h, m;
  	char colon;
	cout << "Enter the time of the day ";
	cin >> h >> colon >> m;
	time24 time(h,m);
	addTime();
	writeTime();
	*/
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

void time24 :: addTime(int m)
{
	minutes += m;
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
  	while(hours > 23)
  		//when hours > 23 new day starts
  	{
  		hours -= 24;
  	}
}

time24 operator+ (const time24& t1, const time24& t2)
{
	int newH = t1.getHour() + t2.getHour();
	int newM = t1.getMinute() + t2.getMinute();
	return time24(newH, newM);
}

time24& time24 :: operator+= (const time24& t)
{
	this->hours = this->hours + t.getHour();
	this->minutes = this->minutes + t.getMinute();
	this->normalizeTime();
	return *this;

}

bool operator< (const time24& t1, const time24& t2)
{
	if(t1.getHour() == t2.getHour())
		if(t1.getMinute() < t2.getMinute()) return true;

	if(t1.getHour() < t2.getHour()) return true;

	else return false;

}

std :: ostream& operator<< (std :: ostream& out, const time24& t)
{
	out << t.getHour() << ":" << t.getMinute() << " ";
	return out;
}
