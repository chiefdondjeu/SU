/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Lab 3
 *main.cpp
 *Feb 13, 2019
 */

#include <iostream>
#include "heapsort.h"

int main()
{
	Heap<int>* myheap = new Heap<int>;

	std :: cout << "Enter number of elements: ";
	std :: cin >> myheap->length;

	myheap->arr = new int[myheap->length]; 

	std :: cout << "\n\tHEAP SORT\n" << std :: endl;
	
	fillAscending(myheap);
	timeSort(Heapsort, myheap);
	std :: cout << "\tgoodArr ";
	isSorted(myheap);

	fillRandom(myheap);
	timeSort(Heapsort, myheap);
	std :: cout << "\trandArr ";
	isSorted(myheap);

	fillDescending(myheap);
	timeSort(Heapsort, myheap);
	std :: cout << "\tbadArr ";
	isSorted(myheap);

	delete [] myheap->arr;
	delete myheap;

	return 0;
}