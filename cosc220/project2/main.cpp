/*
 * main.cpp
 * main fucntion
 * Author: Florent Dondjeu Tschoufack
 * created: November 2, 2019
 * current: November 5, 2019
 */
#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>

#include "timerAux.h"
#include "mySorts.h"

enum Order {RANDOM, ASCENDING, DESCENDING};

//fillArray
//fills the array with integers
//parameter: array to be filled, array size, order of elements int array
//returns: none
//precondtion: none
//postcondtion: array is filled with integers with desired order
void fillArray(int*, const int, Order);

int main()
{
	int choice;
	bool STOP = false;	//end the progam when true
	
	std :: cout << "Welcome!\n" << std :: endl;
	while(STOP != true)
	{
		std :: cout << "(1)Bubble sort\t  (2)Selection sort\t(3)Insertion sort\t";
		std :: cout << "(4)Double-ended sort\t(5)Exchange sort" << std :: endl;
		std :: cout << "Which sorting algorithm would you like to try (#): ";
		std :: cin >> choice;

		Timer stpw; //stopwatch
		int size, power, type_int, x = 2;
		bool steps = true; //prints steps if size <= 2^4
		int choice2; //to continue or end program
		Order type; //array order

		if(choice == 1) //bubble sort
		{
			steps = true;
			std :: cout << "\nBUBBLE SORT" << std :: endl;
			
			std :: cout << "Size of the array: 2^";
			std :: cin >> power;
			size = pow(x, power);
			
			if(size > 16)
				steps = false;
			
			std :: cout << "\n(1)RANDOM\t(2)ASCENDING\t(3)DESCENDING\nOrder (#): ";
			std :: cin >> type_int;
			if(type_int == 1)
				type = RANDOM;
			if(type_int == 2)
				type = ASCENDING;
			if(type_int == 3)
				type = DESCENDING;

			int ProjArray[size];
			fillArray(ProjArray, size, type);

			if(steps == true) //prints out elements in array before being sorted
			{
				std :: cout << "\nOriginal: ";
				print(ProjArray, size);
			}
			
			stpw.startTime(); //start timer
			bubbleSort(ProjArray, size, steps);
			stpw.endTime(); //end timer

			if(steps == true)
			{
				std :: cout << "\nSorted: ";
				print(ProjArray, size);
			}
			else std :: cout << "Array has been sorted." << std :: endl;

			std :: cout << "\nPress (1)continue or (2)end (#): ";
			std :: cin >> choice2;
			std :: cout << std :: endl;

			if(choice2 == 2)
				STOP = true;

		}

		if(choice == 2)	//selection sort
		{	
			steps = true;
			std :: cout << "\nSELECTION SORT" << std :: endl;
			
			std :: cout << "Size of the array: 2^";
			std :: cin >> power;
			size = pow(x, power);
			
			if(size > 16)
				steps = false;
			
			std :: cout << "\n(1)RANDOM\t(2)ASCENDING\t(3)DESCENDING\nOrder (#): ";
			std :: cin >> type_int;
			if(type_int == 1)
				type = RANDOM;
			if(type_int == 2)
				type = ASCENDING;
			if(type_int == 3)
				type = DESCENDING;

			int ProjArray[size];
			fillArray(ProjArray, size, type);

			if(steps == true)
			{
				std :: cout << "\nOriginal: ";
				print(ProjArray, size);
			}
			
			stpw.startTime();
			selectionSort(ProjArray, size, steps);
			stpw.endTime();

			if(steps == true)
			{
				std :: cout << "\nSorted: ";
				print(ProjArray, size);
			}
			else std :: cout << "Array has been sorted." << std :: endl;

			std :: cout << "\nPress (1)continue or (2)end (#): ";
			std :: cin >> choice2;
			std :: cout << std :: endl;

			if(choice2 == 2)
				STOP = true;

		}

		if(choice == 3)	//insertion sort
		{
			steps = true;
			std :: cout << "\nINSERTION SORT" << std :: endl;
			
			std :: cout << "Size of the array: 2^";
			std :: cin >> power;
			size = pow(x, power);
			
			if(size > 16)
				steps = false;
			
			std :: cout << "\n(1)RANDOM\t(2)ASCENDING\t(3)DESCENDING\nOrder (#): ";
			std :: cin >> type_int;
			if(type_int == 1)
				type = RANDOM;
			if(type_int == 2)
				type = ASCENDING;
			if(type_int == 3)
				type = DESCENDING;

			int ProjArray[size];
			fillArray(ProjArray, size, type);

			if(steps == true)
			{
				std :: cout << "\nOriginal: ";
				print(ProjArray, size);
			}
			
			stpw.startTime();
			insertionSort(ProjArray, size, steps);
			stpw.endTime();

			if(steps == true)
			{
				std :: cout << "\nSorted: ";
				print(ProjArray, size);
			}
			else std :: cout << "Array has been sorted." << std :: endl;

			std :: cout << "\nPress (1)continue or (2)end (#): ";
			std :: cin >> choice2;
			std :: cout << std :: endl;

			if(choice2 == 2)
				STOP = true;

		}

		if(choice == 4)	//double-ended sort
		{
			steps = true;
			std :: cout << "\nDOUBLE-ENDED SORT" << std :: endl;
			
			std :: cout << "Size of the array: 2^";
			std :: cin >> power;
			size = pow(x, power);
			
			if(size > 16)
				steps = false;
			
			std :: cout << "\n(1)RANDOM\t(2)ASCENDING\t(3)DESCENDING\nOrder (#): ";
			std :: cin >> type_int;
			if(type_int == 1)
				type = RANDOM;
			if(type_int == 2)
				type = ASCENDING;
			if(type_int == 3)
				type = DESCENDING;

			int ProjArray[size];
			fillArray(ProjArray, size, type);

			if(steps == true)
			{
				std :: cout << "\nOriginal: ";
				print(ProjArray, size);
			}
			
			stpw.startTime();
			doubleEndedSort(ProjArray, size, steps);
			stpw.endTime();

			if(steps == true)
			{
				std :: cout << "\nSorted: ";
				print(ProjArray, size);
			}
			else std :: cout << "Array has been sorted." << std :: endl;

			std :: cout << "\nPress (1)continue or (2)end (#): ";
			std :: cin >> choice2;
			std :: cout << std :: endl;

			if(choice2 == 2)
				STOP = true;

		}

		if(choice == 5)	//exchange sort
		{
			steps = true;
			std :: cout << "\nEXCHANGE SORT" << std :: endl;
			
			std :: cout << "Size of the array: 2^";
			std :: cin >> power;
			size = pow(x, power);
			
			if(size > 16)
				steps = false;
			
			std :: cout << "\n(1)RANDOM\t(2)ASCENDING\t(3)DESCENDING\nOrder (#): ";
			std :: cin >> type_int;
			if(type_int == 1)
				type = RANDOM;
			if(type_int == 2)
				type = ASCENDING;
			if(type_int == 3)
				type = DESCENDING;

			int ProjArray[size];
			fillArray(ProjArray, size, type);

			if(steps == true)
			{
				std :: cout << "\nOriginal: ";
				print(ProjArray, size);
			}
			
			stpw.startTime();
			exchangeSort(ProjArray, size, steps);
			stpw.endTime();

			if(steps == true)
			{
				std :: cout << "\nSorted: ";
				print(ProjArray, size);
			}
			else std :: cout << "Array has been sorted." << std :: endl;

			std :: cout << "\nPress (1)continue or (2)end (#): ";
			std :: cin >> choice2;
			std :: cout << std :: endl;

			if(choice2 == 2)
				STOP = true;

		}

	}

	std :: cout << "\nThank you for your time!" << std :: endl;

	return 0;
}


void fillArray(int arr[], const int n, Order ch)
{
	int i,j;

	if(ch == RANDOM)
	{
		for(i = 0; i < n; i++)
		{
			arr[i] = i+1;
		}
		std::srand (unsigned(std::time(0)));
		//makes it so we get a different shuffle partern everytime
		std::random_shuffle (&arr[0], &arr[n]);
		//suffles the array so it becomes random
	}

	if(ch == ASCENDING)
	{
		for(i = 0; i < n; i++)
		{
			arr[i] = i+1;
		}
	}

	if(ch == DESCENDING)
	{
		j = n;
		for(int i = 0; i < n; i++)
		{
			arr[i] = j;
			j--;
		}
	}

}