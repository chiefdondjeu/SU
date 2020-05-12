/*
 *studentClass.h
 *Declaration of Student class
 *Author: Florent Dondjeu Tschoufack
 *Created: November 29, 2019
 *Current: November 29, 2019
 */

#ifndef STUDENTCLASS
#define STUDENTCLASS

#include <iostream>
#include <string>

class Student
{
private:
	int id;
	std::string firstName, lastName;
	int year;
	double GPA;

public:

	//Student
	//default constructor
	//parameter: none
	//returns: none
	//precondition: none
	//postcondition: private variable have been initialized
	Student();

	//Student
	//default constructor
	//parameter: n for name
	//returns: none
	//precondition: none
	//postcondition: name has been initialized
	//Student(std :: string n);

	//Student
	//constructor
	//parameter: i for id, fn for fname, ln for lname, y for year, g for GPA
	//returns: none
	//precondition: none
	//postcondition: private variable have been initialized
	Student(int, std::string, std::string, int, double);

	//setId
	//initialize id
	//parameter: i for id
	//returns: none
	//precondition: none
	//postcondition: value of id has been updated
	void setId(int i);

	//setName
	//initialize name
	//parameter: n for name
	//returns: none
	//precondition: none
	//postcondition: value of name has been updated
	void setName(std::string fn, std::string ln);

	//setYear
	//initialize year
	//parameter: y for year
	//returns: none
	//precondition: none
	//postcondition: value of year has been updated
	void setYear(int y);

	//setGPA
	//initialize GPA
	//parameter: g for GPA
	//returns: none
	//precondition: none
	//postcondition: value of GPA has been updated
	void setGPA(double g);

	//getId
	//returns id
	//parameter: none
	//return: value of id
	//precondition: none
	//postcondition: none
	int getId() const;

	//geFname
	//returns firstName
	//parameter: none
	//return: value of FirstName
	//precondition: none
	//postcondition: none
	std::string getFname() const;

	//getLname
	//returns the lastName
	//parameter: none
	//return: value of LastName
	//precondition: none
	//postcondition: none
	std::string getLname() const;

	//getYear
	//returns the year
	//parameter: none
	//return: value of year
	//precondition: none
	//postcondition: none
	int getYear() const;

	//getGPA
	//returns the GPA
	//parameter: none
	//return: value of GPA
	//precondition: none
	//postcondition: none
	double getGPA() const;

	//operator<<
	//prints out the student information
	//parameter: ostream object and student object
	//returns: ostream object
	//precondition: none
	//postcondition: students information have been printed out
	friend std::ostream& operator<<(std::ostream& out, const Student& s1);

};

#endif
