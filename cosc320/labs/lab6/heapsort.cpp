/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Lab 6
 *heapsort.cpp
 *Mar 7, 2020
 */

#include <iostream>

#include "heapsort.h"


/*
 *swap function is defined in the main
 */

template <typename T>
void maxHeapify(Heap<T> *A, int i)
{

	int l, r, largest;
	l = left(i);
	r = right(i);

	if(l <= A->heap_size && A->arr[l] > A->arr[i])
		largest = l;

	else 
		largest = i;

	if(r <= A->heap_size && A->arr[r] > A->arr[largest])
		largest = r;

	if(largest != i)
	{
		swap(&A->arr[i], &A->arr[largest]);
		maxHeapify(A, largest);
	}
}

template <typename T>
void buildMaxHeap(Heap<T> *A)
{
	A->heap_size = (A->length) - 1;
	for(int i = (A->length)/2; i >= 0; i--)
	{
		maxHeapify(A, i);
	}

}

template <typename T>
void Heapsort(Heap<T> *A)
{
	buildMaxHeap(A);
	for(int i = (A->length); i > 0; i--)
	{
		swap(&A->arr[0], &A->arr[A->heap_size]);
		A->heap_size = A->heap_size - 1;
		maxHeapify(A,0);
	}

}

int left(int i)
{
	if(i < 1)
		return 1;
	else
		return (i*2)+1;
}

int right(int i)
{
	return left(i)+1;
}

template <typename T>
void display(Heap<T> *A)
{
	std::cout << "arr: ";
	for(int i = 0; i < A->length; i++)
		std :: cout << A->arr[i] << " ";
	std :: cout << std :: endl;
}

template <typename T>
void isSorted(Heap<T> *A)
{
	for(int i = 0; i < (A->length)-1; i++)
	{
		if(A->arr[i] > A->arr[i+1])
		{
			throw std::string(" Arr is not sorted!!!");
			return ;
		}
	}
	//std::cout << " Arr is sorted\n";
}

template <typename T>
double timeSortHeap(void(*sort) (Heap<T>*), Heap<T> *A)
{
	auto start = std::chrono::system_clock::now();
	sort(A);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	return elapsed_seconds.count();
}