#ifndef TIME24_H
#define TIME24_H
#include <ostream>

class time24
{
  private:
    int hours;
    int minutes;

  public:
    time24(int h = 0, int m = 0);

    void readTime();
      //ask the user to enter a time-of-day in form of hours:minutes

    void writeTime();
      //prints out the time-of-day in forms of hours:minutes

    time24 duration(const time24& t);
      //Measure the length of time from the current time to  a time24
      //object passing through function  and return the result as a time24 value

    void addTime(int m);
      //add a specified number of minutes to a time-of-day
      //and adjust the hours and minutes to fall in their specified range

    int getHour() const;
      //return the hour

    int getMinute() const;
      //return the minute

    void normalizeTime();
      //utility function sets the hour value in the range 0 to 23
      //and the minute value in the range 0 to 50

    friend time24 operator+ (const time24& t1, const time24& t2);
      //add 
    time24& operator+= (const time24& t);

    friend std :: ostream& operator<< (std :: ostream& out, const time24& t);

};

#endif
