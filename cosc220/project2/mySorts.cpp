/*
 * mySorts.cpp
 * implementation of sort functions
 * Author: Florent Dondjeu Tschoufack
 * created: November 2, 2019
 * current: November 5, 2019
 */
#include <iostream>
#include "mySorts.h"

template <typename T>
void print(const T arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		std :: cout << arr[i] << " ";
	}
	std :: cout << std :: endl;
}

template <typename T>
void swap(T *a, T *b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <typename T>
void bubbleSort(T arr[], int n, bool show)
{
	if(show == true)
		std :: cout << "\nSteps: " << std :: endl;

	int i,j;
	for(i = 0; i < n-1; i++)
	{
		for(j = 0; j < n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}

		if(show == true)
			print(arr, n);
	}

}

template <typename T>
void selectionSort(T arr[], int n, bool show)
{
	if(show == true)
		std :: cout << "\nSteps: " << std :: endl;

	int i, j, k;

	for(i = 0; i < n-1; i++)
	{
		k = i;
		for(j = i+1; j < n; j++)
			if(arr[j] < arr[k])
				k = j;

			swap(&arr[k], &arr[i]);

			if(show == true)
				print(arr, n);
	}

}

template <typename T>
void insertionSort(T arr[], int n, bool show)
{
	if(show == true)
		std :: cout << "\nSteps: " << std :: endl;

	int i, j;
	T temp;

	for(i = 1; i < n; i++)
	{
		temp = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > temp)
		{
			arr[j+1] = arr[j];
			j = j - 1;
		}
		arr[j+1] = temp;

		if(show == true)
				print(arr, n);
	}

}

template <typename T>
void doubleEndedSort(T arr[], int n, bool show)
{
	if(show == true)
		std :: cout << "\nSteps: " << std :: endl;

	for(int i = 0, j = n-1; i < j; i++, j--)
	{
		T first = arr[i], last = arr[i];
		int low = i, high = j;

		for(int k = i; k <= j; k++)
		{
			if(arr[k] > last)
			{
				last = arr[k];
				high = k;
			}
			else if(arr[k] < first)
			{
				first = arr[k];
				low = k;
			}
		}

		swap(&arr[i], &arr[low]);

		if(arr[low] == last)
			swap(&arr[j], &arr[low]);

		else swap(&arr[j], &arr[high]);

		if(show == true)
			print(arr, n);
	}

}

template <typename T>
void exchangeSort(T arr[], int n, bool show)
{
	if(show == true)
		std :: cout << "\nSteps: " << std :: endl;

	int i, j;

	for(i = 0; i < n-1; i++)
	{
		for(j = i+1; j < n; j++)
		{
			if(arr[i] > arr[j])
			{
				swap(&arr[i], &arr[j]);

				//if(show == true)
					//print(arr, n);
			}
		}
		if(show == true)
			print(arr, n);
	}

}
