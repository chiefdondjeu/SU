/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Lab 3
 *heapsort.cpp
 *Feb 13, 2019
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h> //for timing

#include <cmath>

#include "heapsort.h"

namespace swapcount
{
	long counter = 0;
}

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
	//display(A);
	//std :: cout << std :: endl;
	//printMaxHeap(A,2,3);

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

template <typename T>
void swap(T *x, T *y)
{
	T temp = *x;
	*x = *y;
	*y = temp;

	swapcount :: counter++;
}

/*
 *Unfortunately my printMaxHeap() can print from the "root" and all of its 
 *children, and the left child and all of its children, but it cannot print 
 *the right child's children :(
 */

template <typename T>
void printMaxHeap(Heap<T> *A, int i, int d)
{
	int l = 1;	//for max numb of nodes
	int m = 0; //tracks numb of nodes
	int n = m;

	std :: cout << A->arr[i] << std :: endl;

	bool first = true;
	bool skip = true;
	bool stop = false;

	for(int k = i; k < A->heap_size; k++)
	{
		if(i != 0)
		{
			if(first == true)
			{
				k+= (pow(2,l)-2);
				first = false;
			}
			else if(skip == true)
			{
				k++; //k++ so the right twin children's are not printed
				skip = false;
			}
		}

		if(left(k) >= A->length)
		{
			std :: cout << "* " << std :: endl;
			break; //stop printing when index is out of bounds
		}
		else
		{
			std :: cout << A->arr[left(k)] << " ";
			m++; //count number of node at a certain height
		} 

		if(right(k) >= A->length)
		{
			std :: cout << "* " << std :: endl;
			break; //stop printing when index is out of bounds
		}
		else
		{
			std :: cout << A->arr[right(k)] << " ";
			m++; //count number of node at a certain height
		}

		if(m == pow(2,l)) //2^l is the total number of nodes at a given height l
		{
			std :: cout << "\n";
			n = m;
			m = 0; //resets the node count before going down the "tree"
			l++;
			skip = true;
		}

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

//////////////////////////////////////////////////

template <typename T>
void fillAscending(Heap<T> *A)
{
	for(int i = 0; i < A->length; i++)
		A->arr[i] = i+1;
}

template <typename T>
void fillDescending(Heap<T> *A)
{
	int j = A->length;
	for(int i = 0; i < A->length; i++)
	{
		A->arr[i] = j;
		j--;
	}
}

template <typename T>
void fillRandom(Heap<T> *A)
{
	srand(time(0));
	int randnumb;
	for(int i = 0; i < A->length; i++)
	{
		randnumb = (rand()%100)+1;
		A->arr[i] = randnumb;
	}
}

template <typename T>
void display(Heap<T> *A)
{
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
			std :: cout << "is not sorted!!!\n" << std :: endl;
			return ;
		}
	}
	std :: cout << "is sorted!\n" << std :: endl;
}

template <typename T>
void timeSort(void(*sort) (Heap<T>*), Heap<T> *A)
{
	clock_t t;
	t = clock();
	sort(A);
	t = clock()-t;
	std :: cout << "\telasped time: " << ((float)t)/CLOCKS_PER_SEC
							<< "s" << std :: endl;
	std :: cout << "\t# swap: " << swapcount::counter << std :: endl;
	swapcount::counter = 0;
	t = 0;
}