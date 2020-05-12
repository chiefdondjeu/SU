/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Lab 6
 *quicksort.cpp
 *Mar 7, 2020
 */

#include "quicksort.h"


/*
 *swap function is defined in the main
 */

template <typename T>
int partition(T* A, int m, int n)
{
	T pivot = A[n];
	int i = m-1;
	for(int j = m; j <= n-1; j++)
	{
		if(A[j] < pivot)
		{
			i++;
			swap(&A[i], &A[j]);
		}
	}
	i++;
	swap(&A[i], &A[n]);
	return i;
}

template <typename T>
void quicksort(T* A, int m, int n) //exclusive, n-1 in main
{
	int pivot;
	if(m < n)
	{
		pivot = partition(A, m, n);
		quicksort(A, m, pivot-1);
		quicksort(A, pivot+1, n);
	}

}

template <typename T>
void randquicksort(T* A, int m, int n) //exclusive, n-1 in main
{
	int pivot;
	if(m < n)
	{
		int i = rand()%(n+1);
		swap(&A[i], &A[n]);	//randomize

		pivot = partition(A, m, n);
		quicksort(A, m, pivot-1);
		quicksort(A, pivot+1, n);
	}
}

template <typename T>
double timeSortQuick(void(*sort) (T*, int, int), T* A, int m, int n)
{	
	auto start = std::chrono::system_clock::now();
	sort(A, m, n);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	return elapsed_seconds.count();
}