/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Lab 6
 *main.cpp
 *Mar 7, 2020
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <string>

#include "heapQ.h"

//sorts
#include "quicksort.h"
#include "mergesort.h"
#include "heapsort.h"

//colors
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YEL "\033[33m"
#define BLUE "\033[34m"

//func()
template <typename T>
void swap(T*,T*);

namespace swapcount
{
	unsigned long swaps = 0;
	unsigned long total = 0;
}

template <typename T>
void print(T*,int);

template <typename T>
void isSorted(T*,int);

//returned array with suffle index using swap
int* suffle2a(int);

//returned array with suffle index using priority Queue
int* suffle2b(int);

//return a copy of array passed in
int* arrayCopy(int[],int);

//stats keep
namespace Assistant
{
	int rank = 0;
	unsigned long replaced = 0;
	unsigned long avg = 0; //total avg
	int avg_run = 0;	//avg for each size

	//testing cases
	int index = 0;
	int worker[10] = {1000,2000,3000,4000,5000,6000,7000,8000,9000,10000};
}

//hire assistant with highest rank
void Hire_Assistant(int*, int);

//function pointer
double playHire(void(*play)(int*,int), int*A, int n);


int main()
{
	srand(time(0));

	char choice; //user input

	//////////////////////////////HIRING ALGORITHM///////////////////////////////

	do //input check
	{
		std::cout << "Play hiring algorithm (y/n)\n\t-->";
		std::cin >> choice;

		//no error
		if(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
		{
			std::cin.ignore(); 
			break;
		}
		//miss match input
		if(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N')
		{
			std::cout << "\nIncorrect input! Please try again.\n";
			std::cin.ignore(); 
		}

	}while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');

	//start hiring
	if(choice == 'y' || choice == 'Y')
	{
		std::cout << BLUE <<"\nHiring Algorithm\n" << RESET;
		std::cout << std::setprecision(6) << std::fixed << std::showpoint;

		int size = Assistant::worker[Assistant::index];
		int *arr;
		int runs = 0;	//number of overall trials
		double t = 0; //time

		//size100
		for(int k = 0; k < 10; k++)
		{
			arr = suffle2b(size);
			t += playHire(Hire_Assistant,arr,size);
			delete [] arr;
			runs++;
		}
		std::cout << "\n# of applicants: " << RED << size << RESET
							<< "\naverage hiring: " << (Assistant::avg_run)/10 << std::endl;
		std::cout << "avg time: " << YEL << t/10.0 << "s\n" << RESET;

		//size200
		Assistant::avg_run = 0;
		t = 0;
		size = Assistant::worker[++(Assistant::index)];
		for(int k = 0; k < 10; k++)
		{
			arr = suffle2b(size);
			t += playHire(Hire_Assistant,arr,size);
			delete [] arr;
			runs++;
		}
		std::cout << "\n# of applicants: " << RED << size << RESET
							<< "\naverage hiring: " << (Assistant::avg_run)/10 << std::endl;
		std::cout << "avg time: " << YEL << t/10.0 << "s\n" << RESET;

		//size300
		Assistant::avg_run = 0;	//reset
		t = 0;
		size = Assistant::worker[++(Assistant::index)];
		for(int k = 0; k < 10; k++)
		{
			arr = suffle2b(size);
			t += playHire(Hire_Assistant,arr,size);
			delete [] arr;
			runs++;
		}
		std::cout << "\n# of applicants: " << RED << size << RESET 
							<< "\naverage hiring: " << (Assistant::avg_run)/10 << std::endl;
		std::cout << "avg time: " << YEL << t/10.0 << "s\n" << RESET;

		//size400
		Assistant::avg_run = 0;
		t = 0;
		size = Assistant::worker[++(Assistant::index)];
		for(int k = 0; k < 10; k++)
		{
			arr = suffle2b(size);
			t += playHire(Hire_Assistant,arr,size);
			delete [] arr;
			runs++;
		}
		std::cout << "\n# of applicants: " << RED << size << RESET 
							<< "\naverage hiring: " << (Assistant::avg_run)/10 << std::endl;
		std::cout << "avg time: " << YEL << t/10.0 << "s\n" << RESET;

		//size500
		Assistant::avg_run = 0;
		t = 0;
		size = Assistant::worker[++(Assistant::index)];
		for(int k = 0; k < 10; k++)
		{
			arr = suffle2b(size);
			t += playHire(Hire_Assistant,arr,size);
			delete [] arr;
			runs++;
		}
		std::cout << "\n# of applicants: " << RED << size << RESET 
							<< "\naverage hiring: " << (Assistant::avg_run)/10 << std::endl;
		std::cout << "avg time: " << YEL << t/10.0 << "s\n" << RESET;

		//size600
		Assistant::avg_run = 0;
		t = 0;
		size = Assistant::worker[++(Assistant::index)];
		for(int k = 0; k < 10; k++)
		{
			arr = suffle2b(size);
			t += playHire(Hire_Assistant,arr,size);
			delete [] arr;
			runs++;
		}
		std::cout << "\n# of applicants: " << RED << size << RESET 
							<< "\naverage hiring: " << (Assistant::avg_run)/10 << std::endl;
		std::cout << "avg time: " << YEL << t/10.0 << "s\n" << RESET;

		//size700
		Assistant::avg_run = 0;
		t = 0;
		size = Assistant::worker[++(Assistant::index)];
		for(int k = 0; k < 10; k++)
		{
			arr = suffle2b(size);
			t += playHire(Hire_Assistant,arr,size);
			delete [] arr;
			runs++;
		}
		std::cout << "\n# of applicants: " << RED << size << RESET 
							<< "\naverage hiring: " << (Assistant::avg_run)/10 << std::endl;
		std::cout << "avg time: " << YEL << t/10.0 << "s\n" << RESET;

		//size800
		Assistant::avg_run = 0;
		t = 0;
		size = Assistant::worker[++(Assistant::index)];
		for(int k = 0; k < 10; k++)
		{
			arr = suffle2b(size);
			t += playHire(Hire_Assistant,arr,size);
			delete [] arr;
			runs++;
		}
		std::cout << "\n# of applicants: " << RED << size << RESET 
							<< "\naverage hiring: " << (Assistant::avg_run)/10 << std::endl;
		std::cout << "avg time: " << YEL << t/10.0 << "s\n" << RESET;

		//size900
		Assistant::avg_run = 0;
		t = 0;
		size = Assistant::worker[++(Assistant::index)];
		for(int k = 0; k < 10; k++)
		{
			arr = suffle2b(size);
			t += playHire(Hire_Assistant,arr,size);
			delete [] arr;
			runs++;
		}
		std::cout << "\n# of applicants: " << RED << size << RESET 
							<< "\naverage hiring: " << (Assistant::avg_run)/10 << std::endl;
		std::cout << "avg time: " << YEL << t/10.0 << "s\n" << RESET;

		//size1000
		Assistant::avg_run = 0;
		t = 0;
		size = Assistant::worker[++(Assistant::index)];
		for(int k = 0; k < 10; k++)
		{
			arr = suffle2b(size);
			t += playHire(Hire_Assistant,arr,size);
			delete [] arr;
			runs++;
		}
		std::cout << "\n# of applicants: " << RED << size << RESET 
							<< "\naverage hiring: " << (Assistant::avg_run)/10 << std::endl;
		std::cout << "avg time: " << YEL << t/10.0 << "s\n" << RESET;


		std::cout << "\nTotal average hiring: " 
							<< GREEN << (Assistant::avg)/runs << RESET << "\n\n";


	}//end hiring algorithm


	//////////////////////////////SORTING ALGORITHM//////////////////////////////

	std::cout << std::endl;
	do //input check
	{
		std::cout << "Play sorting algorithms (y/n)\n\t-->";
		std::cin >> choice;

		//no error
		if(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
		{
			std::cin.ignore(); 
			break;
		}
		//miss match input
		if(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N')
		{
			std::cout << "\nIncorrect input! Please try again.\n";
			std::cin.ignore();  
		}

	}while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N');

	//start sorts
	if(choice == 'y' || choice == 'Y')
	{
		std::cout << BLUE << "\nSorting Algorithm\n" << RESET;
		std::cout << std::setprecision(6) << std::fixed << std::showpoint;

		int *arr, *arr_m; //arr_m for mergesort
		unsigned int size;
		int k;
		Heap<int>* myheap = new Heap<int>;

		//times, keep total time for each sorts
		double timeQ = 0.0, timeRQ = 0.0, timeM = 0.0, timeH = 0.0;

		swapcount::swaps = 0;
		swapcount::total = 0;

		//size 10,000~1,000,000
		for(size = 10000; size <= 1000000; size+= 50000)
		{
			//quicksort
			std::cout << GREEN << "\nQuicksort" << RESET << std::endl;
			std::cout << "size: " << RED << size << RESET << std::endl;
			for(k = 1; k <= 20; k++)
			{
				arr = suffle2a(size);
				timeQ += timeSortQuick(quicksort,arr,0,size-1);
				try{

					isSorted(arr,size);

				}catch(std::string& caught)
				{
					std::cout << RED << "Trial: " << k << caught << RESET << std::endl;
				}
				swapcount::swaps = 0;
				delete [] arr;
			}
			std:: cout << "average time: " << YEL << timeQ/(double)k << RESET << "s\n";
			std::cout << "avg swaps: " << (swapcount::total)/k << std::endl;
			swapcount::total = 0;

			//random quicksort
			std::cout << GREEN << "\nRandomized Quicksort" << RESET << std::endl;
			std::cout << "size: " << RED << size << RESET << std::endl;
			for(k = 1; k <= 20; k++)
			{
				arr = suffle2a(size);
				timeRQ += timeSortQuick(randquicksort,arr,0,size-1);
				try{

					isSorted(arr,size);

				}catch(std::string& caught)
				{
					std::cout << RED << "Trial: " << k << caught << RESET << std::endl;
				}
				swapcount::swaps = 0;
				delete [] arr;
			}
			std::cout << "average time: " << YEL << timeRQ/(double)k << RESET << "s\n";
			std::cout << "avg swaps: " << (swapcount::total)/k << std::endl;
			swapcount::total = 0;

			//mergesort
			std::cout << GREEN << "\nMergeSort" << RESET << std::endl;
			std::cout << "size: " << RED << size << RESET << std::endl;
			for(k = 1; k <= 20; k++)
			{
				arr_m = new int[size];
				arr = suffle2a(size);
				timeM += timeSortMerge(mergesort,arr,arr_m,0,size-1);
				try{

					isSorted(arr,size);

				}catch(std::string& caught)
				{
					std::cout << RED << "Trial: " << k << caught << RESET << std::endl;
				}
				//swapcount::swaps = 0;
				delete [] arr;
				delete [] arr_m;
			}
			std::cout << "average time: " << YEL << timeM/(double)k << RESET << "s\n";

			//heap
			std::cout << GREEN << "\nHeapSort" << RESET << std::endl;
			std::cout << "size: " << RED << size << RESET << std::endl;
			myheap->length = size;
			for(k = 1; k <= 20; k++)
			{
				myheap->arr = new int[size];
				arr = suffle2a(size);
				//copy
				for(int l = 0; l < size; l++)
					myheap->arr[l] = arr[l];
				delete [] arr;

				timeH += timeSortHeap(Heapsort, myheap);

				try{

					isSorted(myheap);

				}catch(std::string& caught)
				{
					std::cout << RED << "Trial: " << k << caught << RESET << std::endl;
				}
				swapcount::swaps = 0;
				delete [] myheap->arr;
			}
			std::cout << "average time: " << YEL << timeH/(double)k << RESET << "s\n";
			std::cout << "avg swaps: " << (swapcount::total)/k << std::endl;
			swapcount::total = 0;

			//reset timer
			timeQ = 0.0, timeRQ = 0.0, timeM = 0.0, timeH = 0.0;

			//nicer increment
			if(size == 10000)
				size = 0;

			//formarting
			std::cout << "\n\n\n";


		}//end big for loop


		delete myheap;

	}//end sorting algorithm


	std::cout << "\n\nexiting program...\n";
	return 0;
}


///////////////////////////////////definitions/////////////////////////////////

template <typename T>
void swap(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;

	swapcount::swaps++;
	swapcount::total += swapcount::swaps;
}

template <typename T>
void print(T* A, int n)
{
	std::cout << "arr: ";
	for(int i = 0; i < n; i++)
		std::cout << A[i] << " ";
	std::cout << std::endl;
}

template <typename T>
void isSorted(T* A,int n)
{
	for(int i = 0; i < n-1; i++)
	{
		if(A[i] > A[i+1])
		{
			throw std::string(" Arr is not sorted!!!");
		}
	}
	//std::cout << " Arr is sorted\n";
}

int* suffle2a(int n)
{
	//array to be returned
	int *A = new int[n];

	//fill
	for(int i = 0; i < n; i++)
		A[i] = i+1;

	//suffle
	unsigned long x,y;
	for(int i = 0; i < n; i++)
	{
		x = rand()%n;
		y = rand()%n;
		swap(&A[y],&A[x]);
	}

	return A;
}

int* suffle2b(int n)
{
	//array to be returned
	int *A = new int[n]; 

	//push 1,2,3...,n with random priority range 1~n^3
	HeapQ<int> Qn;
	int randkey, range = pow(n,3);
	for(int i = 0; i < n; i++)
	{
		randkey = (rand()%range)+1;
		Qn.Insert(i+1,randkey);
	}

	//push item from queue into array
	for(int i = 0; i < n; i++)
		A[i] = Qn.Dequeue_();

	return A;
}

int* arrayCopy(int A[], int n)
{
	//array to be returned
	int*B = new int[n];
	for(int i = 0; i < n; i++)
	{
		B[i] = A[i];
	}

	return B;
}


//////////////////////////////HIRING ALGORITHM/////////////////////////////////

void Hire_Assistant(int* A, int n)
{
	Assistant::rank = A[0];

	int current = A[0];
	for(int i = 1; i < n; i++)
	{
		if(current < A[i])
		{
			current = A[i];
			Assistant::rank = A[i];
			Assistant::replaced++;
		}
	}

}

double playHire(void(*play) (int*, int), int*A, int n)
{
	auto start = std::chrono::system_clock::now();
	play(A,n);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	Assistant::avg += Assistant::replaced;
	Assistant::avg_run += Assistant::replaced; //reset in main
	Assistant::replaced = 0;

	return elapsed_seconds.count();
}