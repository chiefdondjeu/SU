/*
 *proj3Driver.cpp
 *main function
 *Author: Florent Dondjeu Tschoufack
 *Created: November 29, 2019
 *Current: December 1, 2019
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "d_dnode.h"
#include "d_dnodeBase.h"
#include "studentClass.h"

int main()
{
	dNode<Student>* head = new dNode<Student>, *fix = NULL, *f ;
	read_file(head);

	char choice;
	std::string space = "\n";

	bool END = true;
	do
	{
		fix = head->prev;
		fix->next = head->next;
		//head now points to the front and back of the list, no node points at head

		f = head->next;
		f->prev = head->prev;
		//first node points at last node instead of head

		//first node check
		//std :: cout << space;
		//std :: cout << f->next->value;
		//std :: cout << f->value;
		//std :: cout << f->prev->value;
		//std :: cout << space;

		//last node check
		//std :: cout << fix->next->value;
		//std :: cout << fix->value;
		//std :: cout << fix->prev->value;
		//std :: cout << space;

		for (int i = 0; i < 75; i++)
			std::cout << space;

		std::cout << "=======================================================" << std::endl;
		std::cout << std::right << std::setw(38) << "Flo&Ryan's Database" << std::endl;
		std::cout << "=======================================================" << std::endl;

		std::cout << "V - View Database information" << std::endl;
		std::cout << "F - Find student" << std::endl;
		std::cout << "S - Sort students" << std::endl;
		std::cout << "A - Add a student" << std::endl;
		std::cout << "D - Delete a student" << std::endl;
		std::cout << "Q - Quit the program" << std::endl;

		std::cout << "=======================================================" << std::endl;
		std::cout << "There are currently " << size(head) << " students in the database." << std::endl;

		std::cout << "\nChoice selected -- ";
		std::cin >> choice;

		for (int i = 0; i < 75; i++)
			std::cout << space;

		switch (choice)
		{
			case 'v'://for case sensitivity
			case 'V':
				display(head);
				break;
			case 'f':
			case 'F':
				findStudent(head);
				break;
			case 's':
			case 'S':
				sortStudent(head);
				break;
			case 'a':
			case 'A':
				addStudent(head);
				break;
			case 'd':
			case 'D':
				deleteStudent(head);
				break;
			case 'q':
			case 'Q':
				END = false;
				std::cout << "You have successfully exited the program. Good day!\n\n" << std::endl;
				break;
		}

	} while (END == true);


	return 0;
}
