/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *lab5
 *main.cpp
 *Mar 3, 2020
 */

#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

#include "prioQ.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YEL "\033[33m"
#define BLUE "\033[34m"

int main()
{
	srand(time(0));

	HeapQ<int> Qi;

	std::cout << GREEN << "Priority Queue: Qi" << RESET << std::endl;
	std::cout << "Size: " << Qi.getSize() << std::endl;

	std::cout << BLUE << "\nInsert... 21(6), 16(3), 30(10), 2(15)\n" << RESET;
	std::cout << "  (..)--> denotes priority\n\n";
	Qi.Insert(21,6);
	Qi.Insert(16,3);
	Qi.Insert(30,10);
	Qi.Insert(2,15);
	std::cout << "Size: " << Qi.getSize() << std::endl;
	Qi.print();
	Qi.peek();

	std::cout << BLUE "\n(x1) Dequeue...\n" << RESET;
	Qi.Dequeue();
	std::cout << "Size: " << Qi.getSize() << std::endl;
	Qi.print();
	Qi.peek();

	std::cout << BLUE << "\n(x2) Dequeue...\n" << RESET;
	Qi.Dequeue();
	Qi.Dequeue();
	std::cout << "Size: " << Qi.getSize() << std::endl;
	Qi.print();
	Qi.peek();

	std::cout << BLUE << "\n(x1) Dequeue...\n" << RESET;
	Qi.Dequeue();
	std::cout << "Size: " << Qi.getSize() << std::endl;

	std::cout << YEL <<"\nError handling\n\n" << RESET;
	try
	{
		std::cout << BLUE << "(x1) Dequeue...\n" << RESET;
		Qi.Dequeue();
	}
	catch(std::string& caught)
	{
		std::cout << RED << caught << RESET << std::endl;
	}
	try
	{
		std::cout << BLUE << "\nPrint...\n" << RESET;
		Qi.print();
	}
	catch(std::string& caught)
	{
		std::cout << RED << caught << RESET << std::endl;
	}
	try
	{
		std::cout << BLUE <<"\nPeek...\n" << RESET;
		Qi.peek();
	}
	catch(std::string& caught)
	{
		std::cout << RED << caught << RESET << std::endl;
	}


	HeapQ<std::string> Qs;
	std::cout << GREEN << "\n\nPriority Queue: Qs" << RESET << std::endl;
	std::cout << "Size: " << Qs.getSize() << std::endl;

	std::cout << BLUE << "\nInsert... Florent(21), Justin(5), Ryan(10), Jacob(8)\n" << RESET;
	std::cout << "  (..)--> denotes priority\n\n";
	Qs.Insert("Florent",21);
	Qs.Insert("Justin",5);
	Qs.Insert("Ryan",10);
	Qs.Insert("Jacob",8);
	std::cout << "Size: " << Qs.getSize() << std::endl;
	Qs.print();
	Qs.peek();

	std::cout << BLUE << "\nInsert... Dr. Anderson(32)\n" << RESET;
	Qs.Insert("Dr. Anderson",32);
	std::cout << "Size: " << Qs.getSize() << std::endl;
	Qs.print();
	Qs.peek();

	std::cout << BLUE << "\nInsert... Grant(2), Zack(6), Keith(11)\n" << RESET;
	Qs.Insert("Grant",2);
	Qs.Insert("Zack",6);
	Qs.Insert("Keith",11);
	std::cout << "Size: " << Qs.getSize() << std::endl;
	Qs.print();
	Qs.peek();

	std::cout << BLUE << "\n(x3) Dequeue...\n" << RESET;
	Qs.Dequeue();
	Qs.Dequeue();
	Qs.Dequeue();
	std::cout << "Size: " << Qs.getSize() << std::endl;
	Qs.print();
	Qs.peek();


	std::cout << "\n\nEnd of program...\n";

	return 0;
}
