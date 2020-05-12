/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Project 1
 *heapQ.h
 *Mar 7, 2020
 */

#ifndef HEAPQ_H
#define HEAPQ_H

#include <iostream>

template <class T>
struct HeapObj
{
	T data;
	int key;
};

template <class T> 
class HeapQ
{
	private:
		HeapObj<T>* arr;
		int heap_size;
		int length;	//array size

		//Increases the priority of the item at location i in the heap && maxheapify
		void increase_key(int, int);

	public:
		//default construstor
		HeapQ();

		//deconstructor
		~HeapQ();

		//removes item with highest priority
		void Dequeue();	//extract-Max

		//modified version of Dequeue
		T Dequeue_();

		//to insert a new item into the heap
		void Insert(const T& val, int);	//enqueue

		//put array into a heap
		void buildMaxHeap();

		//does the heap
		void maxHeapify(int);

		//swap
		void swap(HeapObj<T>*, HeapObj<T>*);

		//find parent index
		int parent(int);

		//find left child index
		int left(int);

		//find right child index
		int right(int);

		//see what data is the current top of the queue
		void peek();

		//display the current contents of the queue
		void print();

		//array size
		int getSize(){return length;}
};

#include "heapQ.cpp"
#endif