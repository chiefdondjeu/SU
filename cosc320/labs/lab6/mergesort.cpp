/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Lab 6
 *mergesort.cpp
 *Mar 7, 2020
 */

#include "mergesort.h"


template <typename T>
void merge(T* A, T* B, int m, int mid, int n)
{
	int i, j, k;
	i = m;
	k = m;
	j = mid+1;

	while(i <= mid && j <= n)
	{
		if(A[i] < A[j])
		{
			B[k] = A[i];
			i++;
		}
		else
		{
			B[k] = A[j];
			j++;
		}
		k++;
	}
	while(i <= mid)
	{
		B[k] = A[i];
		k++;
		i++;
	}
	while(j <= n)
	{
		B[k] = A[j];
		k++;
		j++;
	}

	//copy elements back in
	for(i = m; i < k; i++)
		A[i] = B[i];

}

template <typename T>
void mergesort(T* A, T* B, int m, int n) //exclusive, n-1 in main
{
	int mid;
	if(m < n)
	{
		mid = (m+n)/2;
		mergesort(A, B, m, mid);	//sort the left half
		mergesort(A, B, mid+1, n);	//sort the right half
		merge(A, B, m, mid, n);
	}
}

template <typename T>
double timeSortMerge(void(*sort) (T*, T*, int, int), T *A, T *B, int m, int n)
{
	auto start = std::chrono::system_clock::now();
	sort(A, B, m, n);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	return elapsed_seconds.count();
}