/*
 *studentClass.cpp
 *definition of Student class
 *Author: Florent Dondjeu Tschoufack
 *Created: November 29, 2019
 *Current: November 29, 2019
 */

#include "studentClass.h"

#include <iostream>
#include <iomanip>
#include <string>

Student::Student()
{
	id = 0;
	firstName = " ";
	lastName = " ";
	year = 0;
	GPA = 0.0;
}

Student::Student(int i, std::string fn, std::string ln, int y, double g) :
	id(i), firstName(fn), lastName(ln), year(y), GPA(g)
{}

void Student::setId(int i)
{
	id = i;
}

void Student::setName(std::string fn, std::string ln)
{
	firstName = fn;
	lastName = ln;
}

void Student::setYear(int y)
{
	year = y;
}

void Student::setGPA(double g)
{
	GPA = g;
}

int Student::getId() const
{
	return id;
}

std::string Student::getFname() const
{
	return firstName;
}

std::string Student::getLname() const
{
	return lastName;
}

int Student::getYear() const
{
	return year;
}
double Student::getGPA() const
{
	return GPA;
}

std::ostream& operator<<(std::ostream& out, const Student& s1)
{
	std::cout << std::setprecision(2) << std::fixed;
	out << std::left << std::setw(15) << s1.id << std::setw(10) << s1.firstName << " " << std::setw(20) << s1.lastName << std::setw(10) << s1.year << std::setw(10) << s1.GPA << std::endl;
	return out;
}