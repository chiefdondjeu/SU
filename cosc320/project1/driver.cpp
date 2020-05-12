/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Project 1
 *driver.cpp
 *Mar 8, 2020
 */

#include<iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <chrono>
#include <fstream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YEL "\033[33m"
#define BLUE "\033[34m"
#define MAG "\033[35m"
#define CY "\033[36m"

#include "matrix.h"
#include "heapQ.h"


int main()
{
	srand(time(0));
	
	std::cout << "\nNote: Inverse function does not check for singular matrix!\n";
	std::cout << "      If by any chance a randomly generated matrix is singular,\n"; 
	std::cout << "      please restart the program. :D\n\n";

	std::cout << "      When calculating identity, a rounding down funtion was used\n"; 
	std::cout << "      to make output look nicer\n\n";

	std::cout << "      press [enter] to continue...";
	std::cin.ignore();
	std::cout << "\n";


	
	/////////////////////////////////////////////////////////////////////////////demoes

	//for nice layout output
	std::string line = "\n=====================================";
	std::string append = "======";

	//inverse
	for(unsigned long s = 1; s <= 10; s++)
	{
		if(s >= 6)
			line += append;
		std::cout << line;

		std::cout << "\nDemo: Matrix Inverse " << s << "x" << s << "\n";

		Matrix A(s,s);
		A.fillrandom();
		std::cout << "Matrix A:\n";
		A.print();

		Matrix A_ = A.Inverse();
		std::cout << "\nA inverse:\n";
		std::cout << std::setprecision(3) << std::fixed << std::showpoint;
		A_.print();
		std::cout << std::noshowpoint << std::setprecision(0);

		Matrix I = A*A_;
		std::cout << "\nProduct: A*Ainv\n";
		I.round();
		I.print();
	}

	std::cout << "\n=====================================================================";
	line = "\n=====================================";

	//addition
	for(unsigned long s = 1; s <= 10; s++)
	{
		if(s >= 6)
			line += append;
		std::cout << line;

		std::cout << "\nDemo: Matrix addition " << s << "x" << s << "\n";

		Matrix A(s,s);
		A.fillrandom();
		std::cout << "Matrix A:\n";
		A.print();

		Matrix B(s,s);
		B.fillrandom();
		std::cout << "Matrix B:\n";
		B.print();

		Matrix C = A+B;
		std::cout << "Sum: A+B\n";
		C.print();
	}

	std::cout << "\n=====================================================================";
	line = "\n=====================================";

	//subtraction
	for(unsigned long s = 1; s <= 10; s++)
	{
		if(s >= 6)
			line += append;
		std::cout << line;

		std::cout << "\nDemo: Matrix subtraction " << s << "x" << s << "\n";

		Matrix A(s,s);
		A.fillrandom();
		std::cout << "Matrix A:\n";
		A.print();

		Matrix B(s,s);
		B.fillrandom();
		std::cout << "Matrix B:\n";
		B.print();

		Matrix C = A-B;
		std::cout << "Sum: A-B\n";
		C.print();
	}

	std::cout << "\n=====================================================================";
	line = "\n=====================================";

	//multiplication
	for(unsigned long s = 1; s <= 10; s++)
	{
		if(s >= 6)
			line += append;
		std::cout << line;

		std::cout << "\nDemo: Matrix multiplication " << s << "x" << s << "\n";

		Matrix A(s,s);
		A.fillrandom();
		std::cout << "Matrix A:\n";
		A.print();

		Matrix B(s,s);
		B.fillrandom();
		std::cout << "Matrix B:\n";
		B.print();

		Matrix C = A*B;
		std::cout << "Sum: A*B\n";
		C.print();
	}

	std::cout << "\n\n";



	/////////////////////////////////////////////////////////////////////////////iomodel
	std::cout << "Input-Output model\n";
	std::cout << "press [enter] to continue...";
	std::cin.ignore();

	std::ifstream infile;	//file reading
	infile.open("otherdata");

	//if file is not empty
	if(infile.tellg() == 0)
	{

		while(!infile.eof())
		{
			//queue to store names from file
			HeapQ<std::string> prod_nm;
			std::string input_nm;
			int namek = 200, count = 0;

			//company names
			while(infile.peek() != '-')
			{
				std::getline(infile,input_nm);
				prod_nm.Insert(input_nm,namek);
				namek--;	//key
				count++;
			}

			infile.ignore(3,'\n');	//ignore the "---"

			//data
			double val;
			Matrix A(count,count);

			unsigned long i,j;
			for(i = 0; i < count; i++)
			{
				for(j = 0; j < count; j++)
				{
					infile >> val;
					A.input(i,j,val);
				}
			}

			//indentity matrix
			Matrix I(count,count);
			I.Identity();
			
			infile.ignore(1,'\n');	//go down one line
			infile.ignore(3,'\n');	//ignore the "---"
			
			//dependancies
			Matrix D(count,1);

			for (i = 0; i < count; i++)
			{
				for(j = 0; j < 1; j++)
				{
					infile >> val;
					D.input(i,j,val);
				}
			}

			//calculations
			Matrix X1 = I-A;
			Matrix X_ = X1.Inverse();
			Matrix X = X_*D;

			//puts names in array
			std::string *products = new std::string[count];
			for(int k = 0; k < count; k++)
				products[k] = prod_nm.Dequeue_();

			//nice format
			for(int k = 0; k < count; k++)
				products[k] += ":";	//big brain			IQ++

			//print
			std::cout << std::setprecision(2) << std::fixed << std::showpoint;
			std::cout << "\nAmount of each product needed: \n";
			for(int k = 0; k < count; k++)
			{
				std::cout << std::left << std::setw(15) 
									<< products[k] << std::right << X.arr[k][0] << " units\n";
			}

			delete [] products;

			infile.ignore(1,'\n');	//go down one line
			infile.ignore(3,'\n');	//ignore the "---"
		}

		infile.close();
	}
	else
	{
		std::cout << RED << "ERROR: " << RESET 
							<< " file is empty or non existent!\n";
	}

	std::cout << "\n\n";



	/////////////////////////////////////////////////////////////////////////////timings
	std::cout << "Timings\n";
	std::cout << "press [enter] to continue...";
	std::cin.ignore();
	std::cout << "\n";

	std::cout << std::setprecision(3) << std::fixed << std::showpoint;

	//addition
	unsigned long op_count = 2;
	for(unsigned long s = 100; s <= 25600; s*=2)
	{
		Matrix A(s,s);
		A.fillrandom();
		Matrix B(s,s);
		B.fillrandom();

		auto start = std::chrono::system_clock::now();
		Matrix C = A+B;
		auto end = std::chrono::system_clock::now();
	  std::chrono::duration<double> elapsed_seconds = end-start;

	  op_count *= (s*s); //estimated number of operations

	  std::cout << BLUE << "Matrix addition " << s << "x" << s << RESET << std::endl;
	  std::cout << "# of operation: " << op_count << std::endl;
	  std::cout << "elapsed time: " << YEL << elapsed_seconds.count() << "s\n\n" << RESET;
	  op_count = 2; //reset
	}
	
	std::cout << "\n\n";

	//subtraction
	op_count = 2;
	for(unsigned long s = 100; s <= 25600; s*=2)
	{
		Matrix A(s,s);
		A.fillrandom();
		Matrix B(s,s);
		B.fillrandom();

		auto start = std::chrono::system_clock::now();
		Matrix C = A-B;
		auto end = std::chrono::system_clock::now();
	  std::chrono::duration<double> elapsed_seconds = end-start;

	  op_count *= (s*s);	//estimated number of operations

	  std::cout << RED << "Matrix subtraction " << s << "x" << s << RESET << std::endl;
	  std::cout << "# of operation: " << op_count << std::endl;
	  std::cout << "elapsed time: " << YEL << elapsed_seconds.count() << "s\n\n" << RESET;
	  op_count = 2;	//reset
	}

	std::cout << "\n\n";

	//multiplication
	op_count = 3;
	for(unsigned long s = 50; s <= 1600; s*=2)
	{
		Matrix A(s,s);
		A.fillrandom();
		Matrix B(s,s);
		B.fillrandom();

		auto start = std::chrono::system_clock::now();
		Matrix C = A*B;
		auto end = std::chrono::system_clock::now();
	  std::chrono::duration<double> elapsed_seconds = end-start;

	  op_count *= (s*s*s);	//estimated number of operations

	  std::cout << MAG << "Matrix multiplication " << s << "x" << s << RESET << std::endl;
	  std::cout << "# of operations: " << op_count << std::endl;
	  std::cout << "elapsed time: " << YEL << elapsed_seconds.count() << "s\n\n" << RESET;
	  op_count = 3;	//reset
	}

	std::cout << "\n\n";

	//inverse
	for(unsigned long s = 25; s <= 800; s*=2)
	{
		Matrix A(s,s);
		A.fillrandom();

		auto start = std::chrono::system_clock::now();
		Matrix A_ = A.Inverse();
		auto end = std::chrono::system_clock::now();
	  std::chrono::duration<double> elapsed_seconds = end-start;

	  std::cout << CY << "Matrix inverse " << s << "x" << s << RESET << std::endl;
	  std::cout << "elapsed time: " << YEL << elapsed_seconds.count() << "s\n\n" << RESET;
	}


	return 0;
}