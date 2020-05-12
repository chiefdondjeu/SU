/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Lab 3
 *heapsort.h
 *Feb 13, 2019
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

template <typename T>
void swap(T* , T*);

template <typename T>
void printMaxHeap(Heap<T>*,int,int);

int left(int);

int right(int);

/////////////////////////////////extra

template <typename T>
void fillAscending(Heap<T>*);

template <typename T>
void fillDescending(Heap<T>*);

template <typename T>
void fillRandom(Heap<T>*);

template <typename T>
void display(Heap<T>*);

template<typename T>
void isSorted(Heap<T>*);

template <typename T>
void timeSort(void(*sort) (Heap<T>*), Heap<T> *A);

#include "heapsort.cpp"
#endif