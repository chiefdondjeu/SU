/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Lab 6
 *quicksort.h
 *Mar 7, 2020
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H


template <typename T>
void swap(T*,T*);	//definition in main

template <typename T>
int partition(T*, int m, int n);

template <typename T>
void quicksort(T*, int m, int n); //exclusive, n-1 in main

template <typename T>
void randquicksort(T*, int m, int n); //exclusive, n-1 in main

template <typename T>
double timeSortQuick(void(*sort) (T*, int, int), T* A, int m, int n);


#include "quicksort.cpp"
#endif