/*
 *d_dnodeBase.h
 *definition of dnode class
 *Author: Ryan Kern
 *Created: November 29, 2019
 *Current: November 1, 2019
 */

#ifndef DNODEBASE_H
#define DNODEBASE_H

#include<iostream>
#include<fstream>
#include<iomanip>
#include<ctype.h>
#include "d_dnode.h"
#include "studentClass.h"

//display
//displays the elements in the list
//parameter: dnode pointer
//returns: none
//precondition: list is not empty
//postcondition: every element in the list has been printed
template <typename T>
void display(dNode<T>* head);

//add
//adds element into the list
//parameter: dnode pointer, and element to be added
//returns: list with new element
//precondition: none
//postcondition: the new element is in the list
template <typename T>
dNode<T>* add(dNode<T>* head, T val);

//read_file
//reads students information from a file and puts it in the list
//parameter: dnode pointer
//returns: none
//precondition: file is not empty
//postcondition: every students information from the file is in the list
template <typename T>
void read_file(dNode<T>* head);

//addStudent
//adds one student information
//parameter: dnode pointer
//returns: none
//precondition: none
//postcondition: the new student information is in the list
template <typename T>
void addStudent(dNode<T>* head);

//search
//searchs students in datdabase based on user's description
//parameter: dnode pointer, char variable
//returns: true if search found else false
//precondition: none
//postcondition: either true or false is returned
template<typename T>
bool search(dNode<T>* head, char choice);

//findStudent
//determines how the student should be searched
//parameter: dnode pointer
//returns: none
//precondition: none
//postcondition: notifies the user if the student is in or not in the list
template <typename T>
void findStudent(dNode<T>* head);

//deleteStudent
//searches and delete student in the list
//parameter: dnode pointer
//returns: dnode pointer
//precondtion: needs at lead two student in the list
//postcondition: one student as been removed  from the list if found
template <typename T>
dNode<T>* deleteStudent(dNode<T>* head);

//size
//counts number of student in the list
//parameter: dnode pointer
//return: number of students
//precondition: none
//postcondition: correct number of students is returned
template <typename T>
int size(dNode<T>* head);

//sortStudent
//sorts students by id, name, year, and GPA
//parameter: dnode pointer
//returns: none
//preconditon: none
//postcondition: the list is ordered accordingly
template <typename T>
void sortStudent(dNode<T>* head);

////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void display(dNode<T>* head)
{
	if(head->next == NULL)
		return;

	dNode<T>* p = head->next;

	std::cout << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << std::left << std::setw(15) << "Student ID" << std::setw(31) << "Name" << std::setw(10) << "Year" << std::setw(10) << "GPA" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;

	if(head->next != NULL)
	{
		do
		{
			std::cout << p->value;
			p = p->next;
		} while(p != head->next);
	}

	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "\nStudent count - " << size(head) << std::endl;

	std::cout << "\n\nPress enter to continue...";
	std::cin.ignore();
	std::cin.get();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
dNode<T>* add(dNode<T>* head, T val)
{
	dNode<T>* newNode, * prevNode;

	newNode = new dNode<T>(val);

	if(head->next == NULL)
	{
		head->next = newNode;
	}

	prevNode = head->prev;

	newNode->prev = prevNode;
	newNode->next = head->next;

	prevNode->next = newNode;
	head->prev = newNode;

	return newNode;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void read_file(dNode<T>* head)
{
	int id, year;
	double GPA;
	std::string firstname, lastname;

	std::ifstream infile;
	infile.open("student.txt");
	while (infile >> id >> firstname >> lastname >> year >> GPA)
	{
		add(head, Student(id, firstname, lastname, year, GPA));
	}
	infile.close();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void addStudent(dNode<T>* head)
{
	bool input = false;
	std::string space = "\n";
	int id, year;
	double GPA;
	std::string firstname, lastname;

	std :: ofstream outfile;

	std::cout << "\n=======================================================" << std::endl;
	std::cout << "New student's info...\n" << std::endl;
	std::cout << "ID\t-- ";

	while(!(std::cin >> id)){
		std::cout << "ID -- ";
		std::cin.clear();
		std::cin.ignore();
		for (int i = 0; i < 75; i++)
			std::cout << space;
		std::cout << "\n=======================================================" << std::endl;
		std::cout << "New student's info...\n" << std::endl;
		std::cout << "ID\t-- ";
	}
	dNode<T>* test = head;
	for(int i = 0; i < size(head); i++){
		if(test->value.getId() == id){
			for (int i = 0; i < 75; i++)
				std::cout << space;
			std::cout<<"Student ID already exists." << std::endl;
			std::cout << "\n\nPress enter to continue...";
			std::cin.ignore();
			std::cin.get();
			return;
		}
		test = test->next;
	}

	std::cout << "Name\t-- ";
	std::cin >> firstname >> lastname;

	std::cout << "Year\t-- ";
	while(!(std::cin >> year)){
		std::cout << "Year -- ";
		std::cin.clear();
		std::cin.ignore();
		for (int i = 0; i < 75; i++)
			std::cout << space;
		std::cout << "\n=======================================================" << std::endl;
		std::cout << "New student's info...\n" << std::endl;
		std::cout << "ID\t-- " << id << std::endl;
		std::cout << "Name\t-- " << firstname << " " << lastname << std::endl;
		std::cout << "Year\t-- ";
	}


	std::cout << "GPA\t-- ";
	while(!(std::cin >> GPA)){
		std::cout << "GPA -- ";
		std::cin.clear();
		std::cin.ignore();
		for (int i = 0; i < 75; i++)
			std::cout << space;
		std::cout << "\n=======================================================" << std::endl;
		std::cout << "New student's info...\n" << std::endl;
		std::cout << "ID\t-- " << id << std::endl;
		std::cout << "Name\t-- " << firstname << " " << lastname << std::endl;
		std::cout << "Year\t-- " << year << std::endl;
		std::cout << "GPA\t-- ";
	}


	add(head, Student(id, firstname, lastname, year, GPA));

	outfile.open("student.txt", std :: fstream :: app);
	outfile << id << ' ' << firstname << ' ' << lastname << ' ' << year << ' ' << GPA << std :: endl;

	std::cout<< "\n Student Added!" << std::endl;
	std::cout << "\n\nPress enter to continue...";
	std::cin.ignore();
	std::cin.get();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
bool search(dNode<T>* head, char choice)
{
	std::string space = "\n";
	bool isTrue = false;
	int id;
	std::string firstname, lastname;

	dNode<T>* p = head->next;

	if (choice == 'I' || choice == 'i')
	{
		std::cout << "ID -- ";
		while(!(std::cin >> id)){
			std::cout << "ID -- ";
			std::cin.clear();
			std::cin.ignore();
			for (int i = 0; i < 75; i++)
				std::cout << space;
			std::cout << "invalid ID - Try Again."<< std::endl;
			std::cout << "ID -- ";
		}

		do {
			if (p->value.getId() == id)
			{
				std::cout << p->value.getFname();
				return true;
			}
			else p = p->next;
		} while(p != head->next);
	}

	if (choice == 'F' || choice == 'f')
	{
		std::cout << "First name -- ";
		std::cin >> firstname;


		do {
			if (p->value.getFname() == firstname)
			{
				std::cout << p->value.getFname();
				return true;
			}
			else p = p->next;
		} while(p != head->next);

	}

	if (choice == 'L' || choice == 'l')
	{
		std::cout << "Last name -- ";
		std::cin >> lastname;

		do {
			if (p->value.getLname() == lastname)
			{
				std::cout << p->value.getFname();
				return true;
			}
			else p = p->next;
		} while(p != head->next);
	}

	return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void findStudent(dNode<T>* head)
{
	std::string space = "\n";
	char c, c1;
	bool tell;
	bool isTrue = false;


	while(isTrue != true){
	std::cout << "\n=======================================================" << std::endl;
	std::cout << "Find by...\n" << std :: endl;
	std::cout << "I - ID" << std :: endl;
	std::cout << "F - First name" << std :: endl;
	std::cout << "L - Last name" << std :: endl;

	std::cout << "\nChoice selected -- ";
	std::cin >> c;
	std::cout << std::endl;
	if(c == 'i' || c == 'I' || c == 'f' || c == 'F' || c == 'l' || c == 'L'){
		isTrue = true;
	}
	if(isTrue == false){
		for (int i = 0; i < 75; i++)
			std::cout << space;
	}
  }

	switch (c)
	{
	case 'i':
	case 'I':
		tell = search(head, c);
		break;
	case 'f':
	case 'F':
		tell = search(head, c);
		break;
	case 'l':
	case 'L':
		tell = search(head, c);
		break;
	}

	if (tell == true)
	{
		std::cout << " is in the database." << std::endl;
	}
	else
	{
		std::cout << "This student is not in the database." << std::endl;

		std::cout << "\n\nPress enter to continue...";
		std::cin.ignore();
		std::cin.get();

		isTrue = false;
		while(isTrue != true){
			std::cout << "\nWould you like to add the student... " << std::endl;
			std::cout << "\nY - Yes\nN - No" << std::endl;
			std::cout << "\nChoice selected -- ";
			std::cin >> c1;
			if(c1 == 'Y' || c1 == 'y' || c1 == 'N' || c1 == 'n'){
				isTrue = true;
			}
			if(isTrue == false){
				for (int i = 0; i < 75; i++)
					std::cout << space;
			}
		}


		if (c1 == 'Y' || c1 == 'y')
		{
			addStudent(head);

		}
	}

if(c1 != 'Y' && c1 != 'y' ){
	std::cout << "\n\nPress enter to continue...";
	std::cin.ignore();
	std::cin.get();
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
dNode<T>* deleteStudent(dNode<T>* head)
{
	std::string space = "\n";
	bool isTrue = false;
	if(head->next == head->prev)
	{
		std :: cout << "ERROR: not allowed to remove last student" << std :: endl;

		std::cout << "\n\nPress enter to continue...";
		std::cin.ignore();
		std::cin.get();
		return head;
	}

	int id;
	std::string firstname, lastname;

	char del;
	bool check = false;
	while(isTrue != true){
	std::cout << "\n=======================================================" << std::endl;
	std::cout << "Delete by...\n" << std::endl;
	std::cout << "I - ID" << std::endl;
	std::cout << "F - First name" << std::endl;
	//std :: cout << "L - Last name" << std :: endl;

	std::cout << "\nChoice selected -- ";
	std::cin >> del;
	std::cout << std::endl;
	if(del == 'I' || del == 'i' || del == 'F' || del == 'f'){
		isTrue = true;
	}
	if(isTrue == false){
		for (int i = 0; i < 75; i++)
			std::cout << space;
	}
	}
	dNode<T>* delt = NULL;	//node that will be deleted
	dNode<T>* start = head->next;	//to end loop
	dNode<T>* curNode, * prevNode, *succNode;	//node

	switch (del)
	{
		case 'i':	//for case sensitivity
		case 'I':
			std::cout << "ID -- ";
			while(!(std::cin >> id)){
				std::cout << "ID -- ";
				std::cin.clear();
				std::cin.ignore();
				for (int i = 0; i < 75; i++)
					std::cout << space;
				std::cout << "invalid ID - Try Again."<< std::endl;
				std::cout << "ID -- ";
			}


			if(head->next->value.getId() == id)//for first student on the list only, head->next
			{
				check = true;

				delt = head->next;
				prevNode = delt->prev;
				succNode = delt->next;

				head->next = succNode;
				prevNode->next = succNode;
				succNode->prev = prevNode;

				std::cout << delt->value.getFname() << " has been removed from the database." << std::endl;
				delt->next = NULL;
				delt->prev = NULL;
				delete delt;

				break;//break needed here or program crashes
			}

			if(head->prev->value.getId() == id)//for last student on the list only, head->prev
			{
				check = true;

				delt = head->prev;
				prevNode = delt->prev;
				succNode = delt->next;

				head->prev = prevNode;
				prevNode->next = succNode;
				succNode->prev = prevNode;

				std::cout << delt->value.getFname() << " has been removed from the database." << std::endl;
				delt->next = NULL;
				delt->prev = NULL;
				delete delt;
			}

			else if(head->next->value.getId() != id)//for students in the middle
			{
				curNode = head->next;
				prevNode = curNode->prev;
				succNode = curNode->next;
				do
				{
					if(curNode->value.getId() == id)
					{
						check = true;

						delt = curNode;
						prevNode->next = succNode;
						succNode->prev = prevNode;

						std::cout << curNode->value.getFname() << " has been removed from the database." << std::endl;
						delt->next = NULL;
						delt->prev = NULL;
						delete delt;
					}

					curNode = succNode;
					prevNode = curNode->prev;
					succNode = curNode->next;
				}while(curNode != start);
			}

			break;//end of I case

		case 'f':
		case 'F':
			std::cout << "First name -- ";
			std::cin >> firstname;

			if(head->next->value.getFname() == firstname)//for first student on the list only, head->next
			{
				check = true;

				delt = head->next;
				prevNode = delt->prev;
				succNode = delt->next;

				head->next = succNode;
				prevNode->next = succNode;
				succNode->prev = prevNode;

				std::cout << delt->value.getFname() << " has been removed from the database." << std::endl;
				delt->next = NULL;
				delt->prev = NULL;
				delete delt;

				break;//break needed here or program crashes
			}

			if(head->prev->value.getFname() == firstname)//for last student on the list only, head->prev
			{
				check = true;

				delt = head->prev;
				prevNode = delt->prev;
				succNode = delt->next;

				head->prev = prevNode;
				prevNode->next = succNode;
				succNode->prev = prevNode;

				std::cout << delt->value.getFname() << " has been removed from the database." << std::endl;
				delt->next = NULL;
				delt->prev = NULL;
				delete delt;
			}

			else if(head->next->value.getFname() != firstname)//for students in the middle
			{
				curNode = head->next;
				prevNode = curNode->prev;
				succNode = curNode->next;
				do
				{
					if(curNode->value.getFname() == firstname)
					{
						check = true;

						delt = curNode;
						prevNode->next = succNode;
						succNode->prev = prevNode;

						std::cout << curNode->value.getFname() << " has been removed from the database." << std::endl;
						delt->next = NULL;
						delt->prev = NULL;
						delete delt;
					}

					curNode = succNode;
					prevNode = curNode->prev;
					succNode = curNode->next;
				}while(curNode != start);
			}

			break;//end of F case
	}//end of switch

	if(check == false)
		std::cout << "The student you are trying to delete does not exist." << std::endl;

	std::cout << "\n\nPress enter to continue...";
	std::cin.ignore();
	std::cin.get();

	return head;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
int size(dNode<T>* head)
{
	if(head->next == head->prev)//for when there is one student in the list
		return 1;

	int count = 0;
	dNode<T>* p = head->next;

	do
	{
		p = p->next;
		count++;
	} while (p != head->next);

	return count;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void sortStudent(dNode<T>* head)
{
	bool isTrue = false;
	std::string space = "\n";
	dNode<T>* Sorter;
	dNode<T>* Sorter2;
	char choice;


	while(isTrue != true){
	std::cout << "\n=======================================================" << std::endl;
	std::cout << "Sort by...\n" << std::endl;
	std::cout << "\nI - ID\nF - First name\nL - Last name\nY - Year\nG - GPA" << std::endl;
	std::cout << "\nChoice selected -- ";

	std::cin >> choice;
	std::cout << std::endl;
	if(choice == 'I' || choice == 'i' || choice == 'F' || choice == 'f' || choice == 'L' || choice == 'l' || choice == 'Y' || choice == 'y' || choice == 'G' || choice == 'g'){
		isTrue = true;
	}
	if(isTrue == false){
		for (int i = 0; i < 75; i++)
			std::cout << space;
	}
	}
	Sorter = head;

	if (choice == 'I' || choice == 'i') {
		Student x;
		for (int i = 0; i < size(head); i++) {
			Sorter2 = Sorter->next;
			do
			{
				if (Sorter->value.getId() > Sorter2->value.getId()) {
					x = Sorter->value;
					Sorter->value = Sorter2->value;
					Sorter2->value = x;

				}
				Sorter2 = Sorter2->next;
			} while (Sorter2 != head->next);
			Sorter = Sorter->next;
		}
	}
	if (choice == 'F' || choice == 'f') {
		Student x;
		for (int i = 0; i < size(head); i++) {
			Sorter2 = Sorter->next;
			do
			{
				if (Sorter->value.getFname() > Sorter2->value.getFname()) {
					x = Sorter->value;
					Sorter->value = Sorter2->value;
					Sorter2->value = x;

				}
				Sorter2 = Sorter2->next;
			} while (Sorter2 != head->next);
			Sorter = Sorter->next;
		}
	}
	if (choice == 'L' || choice == 'l') {
		Student x;
		for (int i = 0; i < size(head); i++) {
			Sorter2 = Sorter->next;
			do
			{
				if (Sorter->value.getLname() > Sorter2->value.getLname()) {
					x = Sorter->value;
					Sorter->value = Sorter2->value;
					Sorter2->value = x;

				}
				Sorter2 = Sorter2->next;
			} while (Sorter2 != head->next);
			Sorter = Sorter->next;
		}
	}
	if (choice == 'Y' || choice == 'y') {
		Student x;
		for (int i = 0; i < size(head); i++) {
			Sorter2 = Sorter->next;

			do
			{
				if (Sorter->value.getYear() > Sorter2->value.getYear()) {
					x = Sorter->value;
					Sorter->value = Sorter2->value;
					Sorter2->value = x;

				}
				Sorter2 = Sorter2->next;
			} while (Sorter2 != head->next);
			Sorter = Sorter->next;
		}
	}
	if (choice == 'G' || choice == 'g') {
		Student x;
		for (int i = 0; i < size(head); i++) {
			Sorter2 = Sorter->next;

			do
			{
				if (Sorter->value.getGPA() > Sorter2->value.getGPA()) {
					x = Sorter->value;
					Sorter->value = Sorter2->value;
					Sorter2->value = x;

				}
				Sorter2 = Sorter2->next;
			} while (Sorter2 != head->next);
			Sorter = Sorter->next;
		}
	}



	std::cout << "\n\nPress enter to continue...";
	std::cin.ignore();
	std::cin.get();

}

#endif
