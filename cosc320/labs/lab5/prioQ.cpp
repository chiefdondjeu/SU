/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *lab 5
 *HeapQ.cpp
 *Mar 3, 2020
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

#include "prioQ.h"

/*
 *default construstor
 */
template <class T>
HeapQ<T>::HeapQ(): length(0), heap_size(0), arr(NULL)
{}

/*
 *deconstructor
 */
template <class T>
HeapQ<T>::~HeapQ()
{
	//deallocate memory
	delete [] arr;
	arr = NULL;
}

/*
 *Increases the priority of the item at location i in the heap && maxheapify
 */
template <class T>
void HeapQ<T>::increase_key(int i, int k)
{
	if(k < arr[i].key)
	{
		throw std::string("New key smaller than old key!");
		return;
	}

	arr[i].key = k;
	while(i > 1 && arr[parent(i)].key <= arr[i].key)
	{
		swap(&arr[i], &arr[parent(i)]);
		i = parent(i);
	}

	//puts .key in maxheap
	buildMaxHeap();
}

/*
 *removes item with highest priority
 */
template <class T>
void HeapQ<T>::Dequeue()	//extra-Max
{
	//when queue is empty
	if(length == 0)
	{
		throw std::string("Queue is empty!");
		return;
	}

	//copy
	HeapObj<T> temp[length];
	for(int i = 0; i < length; i++)
	{
		temp[i].data = arr[i].data;
		temp[i].key = arr[i].key;
	}

	//delete old queue
	this->HeapQ<T>::~HeapQ<T>();

	//decrease size
	length -= 1;
	heap_size = length-1;
	arr = new HeapObj<T>[length];

	//copy back && remove item with highest priority
	for(int i = 0; i <= heap_size; i++ )
	{
		arr[i].data = temp[i+1].data;
		arr[i].key = temp[i+1].key;
	}

	//puts key in maxheap
	buildMaxHeap();
}

/*
 *to insert a new item into the heap
 */
template <class T>
void HeapQ<T>::Insert(const T& val, int k)	//enqueue
{
	//when queue is empty
	if(length == 0)
	{
		length = 1;
		heap_size = length-1;
		arr = new HeapObj<T>[length];
	}

	//when queue is not empty
	else
	{
		//copy queue
		HeapObj<T> temp[length];
		for(int i = 0; i < length; i++)
		{
			temp[i].data = arr[i].data;
			temp[i].key = arr[i].key;
		}

		//delete old queue
		this->HeapQ<T>::~HeapQ<T>();

		//increase size
		length += 1;
		heap_size = length-1;//current index
		arr = new HeapObj<T>[length];

		//copy back
		for(int i = 0; i < heap_size; i++ )
		{
			arr[i].data = temp[i].data;
			arr[i].key = temp[i].key;
		}
	}//end else

	arr[heap_size].data = val;
	arr[heap_size].key = -99999;

	increase_key(heap_size,k);
}

/*
 *puts array into a heap
 */
template <class T>
void HeapQ<T>::buildMaxHeap()
{
	heap_size = length-1;
	for(int i = length/2; i >= 0; i--)
		maxHeapify(i);
}

/*
 *does the heap
 */
template <class T>
void HeapQ<T>::maxHeapify(int i)
{
	int largest;

	if(left(i) <= heap_size && arr[left(i)].key > arr[i].key)
		largest = left(i);
	else
		largest = i;

	if(right(i) <= heap_size && arr[right(i)].key > arr[largest].key)
		largest = right(i);

	if(largest != i)
	{
		swap(&arr[i], &arr[largest]);
		maxHeapify(largest);
	}
}

template <class T>
void HeapQ<T>::swap(HeapObj<T> *a, HeapObj<T> *b)
{
	HeapObj<T> temp = *a;
	*a = *b;
	*b = temp;
}

template <class T>
int HeapQ<T>::parent(int i)
{
	if(i == 1 && i == 2)
		return 0;

	return (i/2)-1;
}

template <class T>
int HeapQ<T>::left(int i)
{
	if(i<1)
		return 1;

	else
		return (i*2)+1;
}

template <class T>
int HeapQ<T>::right(int i)
{
	return left(i)+1;
}

/*
 *see what data is the current top of the queue
 */
template <class T>
void HeapQ<T>::peek()
{
	if(length ==0)
		throw std::string("Queue is empty!");

	std::cout << "Current top of queue: " << arr[0].data
						<< "(" << arr[0].key << ")" << std::endl;
}

/*
 *display the current contents of the queue
 */
template <class T>
void HeapQ<T>::print()
{
	//when queue empty
	if(length == 0)
		throw std::string("Queue is empty!");

	//when queue is not empty
	std::cout << "Data: ";
	for(int i = 0; i <= heap_size; i++)
		std::cout << std::left << std::setw(12) << arr[i].data << " ";
	std::cout << std::endl;

	std::cout << "Key:  ";
	for(int i = 0; i <= heap_size; i++)
		std::cout << std::left << std::setw(12) << arr[i].key << " ";
	std::cout << std::endl;
}