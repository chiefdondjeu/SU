/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Lab 6
 *mergesort.h
 *Mar 7, 2020
 */

#ifndef MERGESORT_H
#define MERGESORT_H


template <typename T>
void merge(T*, T*, int m, int mid, int n);

template <typename T>
void mergesort(T*, T*, int m, int n); //exclusive, n-1 in main

template <typename T>
double timeSortMerge(void(*sort) (T*, T*, int, int), T *A, T *B, int m, int n);


#include "mergesort.cpp"
#endif