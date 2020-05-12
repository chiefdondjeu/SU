/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *lab4
 *matrix.h
 *Feb 26, 2020
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix
{
	public:
		long unsigned row;
		long unsigned column;
		int **arr;

		Matrix();
			//default constructor
		Matrix(long unsigned, long unsigned);
			//creates an empty dynamic matrix
		Matrix(const Matrix&);
			//copy constructor
		~Matrix();
			//dealocates memory
		void fillMatrix();
			//fills matrix with 0s
		void fillRandom();
			//fills matrix with random numbers ranging 1~10
		void fillDiagonal();
			//all entries off the main diagonal are 0
		void fillTriangleDown();
			//lower bound matrix
		void fillTriangleUp();
			//upper bound matrix
		void fillIdentity();
			//matrix identity
		void operator= (const Matrix&);
			//for copy
		friend Matrix operator+ (const Matrix&, const Matrix&);
			//matrix addition
		friend Matrix operator- (const Matrix&, const Matrix&);
			//matrix substraction
		friend Matrix operator* (const Matrix&, const Matrix&);
			//matrix multiplication
		friend Matrix operator* (int, const Matrix&);
			//matrix scalar multiplication
		void display();
			//outputs elements of the matrix

};

#endif