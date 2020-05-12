/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Project 1
 *iomodel.cpp
 *Mar 9, 2020
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "matrix.h"
#include "heapQ.h"

#define RESET "\033[0m"
#define RED "\033[31m"

int main(int argc, char **argv)
{
	//more or less than 2 arguments
	if(argc != 2)
	{
		std::cout << RED << "ERROR: " << RESET 
							<< "Program can only take in 2 arguments, not " << argc << ".\n";
		exit(1);
	}

	std::ifstream infile;	//file reading
	infile.open(argv[1]);

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
			std::cout << "Amount of each product needed: \n";
			for(int k = 0; k < count; k++)
			{
				std::cout << std::left << std::setw(15) 
									<< products[k] << std::right << X.arr[k][0] << " units\n";
			}

			delete [] products;

			//	¯\_(ツ)_/¯
		}

		infile.close();
	}
	else
	{
		std::cout << RED << "ERROR: " << RESET 
							<< " file is empty or non existent!\n";
	}

	return 0;
}