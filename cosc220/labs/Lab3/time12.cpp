#include "time12.h"
#include <iostream>
#include <string>
using namespace std;

time24 time12 :: convert12To24(int h, int m, timeUnit tunit)
{
	if(tunit == AM) //AM
	{
		if(h == 12)
		{
			time24 t(0, m);
			return t;
		}
		else
		{
			time24 t(h, m);
			return t;
		}
	}
	else //PM
	{
		if(h == 12)
		{
			time24 t(h, m);
			return t;
		}
		else
		{
			h+=12;
			time24 t(h,m);
			return t;
		}
	}
}

time12 :: time12()
{
	int h=12;
	int m=0;
	timeUnit tunit = AM;
	t = convert12To24(h, m, tunit);
}

time12 :: time12(int h, int m, timeUnit tunit)
{
	t = convert12To24(h, m, tunit);
}

void time12 :: addTime(int m)
{
	t.setMinute(t.getMinute()+m);
	//have to use set func b/c time24::addtime doesn't take paramters
	t.normalizeTime();
}

void time12 :: readTime()
{
	int h, m;
	char colon, unit[2];
	cin >> h >> colon >> m >> unit;
	string u = unit;
	//can't compare char to string so set string=char

	if(u == "AM")
	{
		t.setHour(h);
		t.setMinute(m);
	} 
	else if(u == "PM")
	{
		t.setHour(h+12);
		t.setMinute(m);
	}

	//used set func instead of constructor b/c my code has a wierd bug where it
	//resets the time to 12:00 AM 
}

void time12 :: writeTime()
{
	int hr = t.getHour();
	int min = t.getMinute();
	
	if(hr < 12)	//AM
	{
		if(hr == 0)
		{
			cout << hr+12;
		}
		else cout << hr;
	}
	else if(hr >= 12)	//PM
	{
		if(hr == 12)
		{
			cout << hr;
		}
		else cout << hr-12;
	}

	cout << ":";

	if(min<10)	//minutes
	{
		cout << "0" << min;
	}
	else cout << min;

	if(hr < 12)
	{
		cout << " AM" << endl;
	}
	else cout << " PM" << endl;

}