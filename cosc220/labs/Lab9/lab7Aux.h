#ifndef LAB7AUX_H
#define LAB7AUX_H

#include <vector>

template <typename T>
void removeDup(std::vector<T> & v);
	//removes duplicates from vector using a stable, in-place algorithm

template <typename T>
void removeDup2(std::vector<T> & v);
	//removes duplicates from vector using seqSearchVect

template <typename T>
void removeDup3(std::vector<T> & v);
	//removes duplicates from v using a non-stable algorithm that is not in-place

template <typename T>
unsigned seqVectSearch(const std::vector<T> & v, unsigned first, unsigned last, const T& target);
	//performs a sequential search in a vector

template <typename T>
void writeVector(const std::vector<T> & v);
	//displays every element in vector

#include "lab7Aux.cpp"

#endif