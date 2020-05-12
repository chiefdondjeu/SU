/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Lab 6
 *heapsort.h
 *Mar 7, 2020
 */

#ifndef HEAPSORTT_H
#define HEAPSORTT_H


template <typename T>
struct Heap
{
	T *arr;
	int length;
	int heap_size;

};

template <typename T>
void maxHeapify(Heap<T>*,int);

template <typename T>
void buildMaxHeap(Heap<T>*);

template <typename T>
void Heapsort(Heap<T>*);

int left(int);
int right(int);

template <typename T>
void swap(T*,T*);	//definition in main

template <typename T>
void display(Heap<T>*);

template<typename T>
void isSorted(Heap<T>*);

template <typename T>
double timeSortHeap(void(*sort) (Heap<T>*), Heap<T> *A);


#include "heapsort.cpp"
#endif