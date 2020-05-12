#ifndef TIME12_H
#define TIME12_H
#include "time24.h"

// specifies clock time units
enum timeUnit {AM, PM};

// maintains clock time
class time12
{
	private:
		time24 t;
			// store time in 24-hour format
		time24 convert12To24(int h, int m, timeUnit tunit);
	      // build t from standard time
	public:
		time12();
		time12(int h, int m, timeUnit tunit);
			// initialize time24 data member t

		void addTime(int m);
			// add m minutes to update current time

		void readTime();
		void writeTime();
	      // I/O member functions use format HH:MM: AM (PM)
};

#endif
