/*
 * mySort.h
 * declaration of sort functions
 * Author: Florent Dondjeu Tschoufack
 * created: November 2, 2019
 * current: November 5, 2019
 */
#ifndef SORTS_H
#define SORTS_H

//print
//prints out every element in the array
//parameter: array and array size
//returns: none
//Precondtion: none
//postcondition: every element in the array is printed out
template <typename T>
void print(const T*, const int);

//swap
//swaps two element
//parameter: address of element1 and address of element 2
//returns: none
//precondition: none
//postcondtion: element 1 contains elements 2 data virse versa
template <typename T>
void swap(T*, T*);

//bubbleSort
//sorts element in array in ascending order
//paramter: array to be sorted, array size, and steps to be shown
//returns: none
//precondtion: array is filled with elements
//postcondtion: array is sorted in ascending order and steps are shown if array size is <= 2^4
template <typename T>
void bubbleSort(T*, int, bool);

//selectionSort
//sorts element in array in ascending order
//paramter: array to be sorted, array size, and steps to be shown
//returns: none
//precondtion: array is filled with elements
//postcondtion: array is sorted in ascending order and steps are shown if array size is <= 2^4
template <typename T>
void selectionSort(T*, int, bool);

//insertionSort
//sorts element in array in ascending order
//paramter: array to be sorted, array size, and steps to be shown
//returns: none
//precondtion: array is filled with elements
//postcondtion: array is sorted in ascending order and steps are shown if array size is <= 2^4
template <typename T>
void insertionSort(T*, int, bool);

//doubleEndedSort
//sorts element in array in ascending order
//paramter: array to be sorted, array size, and steps to be shown
//returns: none
//precondtion: array is filled with elements
//postcondtion: array is sorted in ascending order and steps are shown if array size is <= 2^4
template <typename T>
void doubleEndedSort(T*, int, bool);

//exchangeSort
//sorts element in array in ascending order
//paramter: array to be sorted, array size, and steps to be shown
//returns: none
//precondtion: array is filled with elements
//postcondtion: array is sorted in ascending order and steps are shown if array size is <= 2^4
template <typename T>
void exchangeSort(T*, int, bool);

#include "mySorts.cpp"

#endif