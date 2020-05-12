/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *lab4
 *matrix.cpp
 *Feb 26, 2020
 */

#include "matrix.h"

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

#define RESET "\033[0m"
#define GREEN "\033[32m"

Matrix::Matrix()
{
	row = 0;
	column = 0;
	arr = NULL;
}

Matrix::Matrix(long unsigned n, long unsigned m)
{
	if((n*m) == 0)
		throw std::string("ERROR.\nInvalid matrix size.");

	row = n;
	column = m;

	arr = new int*[n];
	for(long unsigned i = 0; i < n; i++)
		arr[i] = new int[m];
	
	fillMatrix();
}

Matrix::Matrix(const Matrix& A) //copy constructor
{
	this->row = A.row;
	this->column = A.column;

	//allocate memory
	arr = new int*[row];
	for(long unsigned i = 0; i < row; i++)
		arr[i] = new int[column];

	//copy
	for(long unsigned i = 0; i < row; i++)
	{
		for(long unsigned j = 0; j < column; j++)
			arr[i][j] = A.arr[i][j];
	}

}

Matrix::~Matrix()
{
	//delete columns
	for(long unsigned i = 0; i < row; i++)
		delete[] arr[i];

	//delete rows
	delete[] arr;
}

void Matrix::fillMatrix()
{
	for(long unsigned i = 0; i < row; i++)
	{
		for(long unsigned j = 0; j < column; j++)
		{
			arr[i][j] = 0;
		}
	}
}

void Matrix::fillRandom()
{
	int randnumb;
	for(long unsigned i = 0; i < row; i++)
	{
		for(long unsigned j = 0; j < column; j++)
		{
			randnumb = (rand()%10)+1;
			arr[i][j] = randnumb;
		}
	}
}

void Matrix::fillDiagonal()
{
	int randnumb;
	long unsigned i, j, r = 0, c = 0;
		//r and c keeps track of the row and column
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			if(r == i && c == j)
			{
				randnumb = (rand()%10)+1;
				arr[i][j] = randnumb;
				r++;
				c++;
			}
		}
	}
}

void Matrix::fillTriangleDown()
{
	int randnumb;
	long unsigned i, j, r = 0, limit = 1;
		//limit keeps track of
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			if(r < limit)
			{
				randnumb = (rand()%10)+1;
				arr[i][j] = randnumb;
				r++;
			}
		}
		r = 0;
		limit++;
	}
	
}

void Matrix::fillTriangleUp()
{
	int randnumb;
	long unsigned i, j, r = 0, limit = 0;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			if(r >= limit)
			{
				randnumb = (rand()%10)+1;
				arr[i][j] = randnumb;
			}
			else r++;
		}
		r = 0;
		limit++;
	}
}

void Matrix::fillIdentity()
{
	long unsigned i, j, r = 0, c = 0;
		//r and c keeps track of the row and column
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			if(r == i && c == j)
			{
				arr[i][j] = 1;
				r++;
				c++;
			}
		}
	}
}

void Matrix::operator= (const Matrix& A)
{
	//delete previous data
	if((row*column) != 0)
		this->Matrix::~Matrix();

	this->row = A.row;
	this->column = A.column;

	//allocate memory for new data
	arr = new int*[row];	
	for(int i = 0; i < row; i++)
		arr[i] = new int[column];

	//copy
	for(int i = 0 ; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			arr[i][j] = A.arr[i][j];
		}
	}
}

Matrix operator+ (const Matrix& A, const Matrix& B)
{
	if(A.row != B.row && A.column != B.column)
		throw std::string("Error.\nMatrices dimensions do not match.");
	

	//matrix to be returned
	Matrix C(A.row, A.column);
	
	int sum, i, j;
	for(i = 0; i < C.row; i++)
	{
		for(j = 0; j < C.column; j++)
		{
			sum = A.arr[i][j] + B.arr[i][j];
			C.arr[i][j] = sum;
		}
	}

	return C;
}

Matrix operator- (const Matrix& A, const Matrix& B)
{
	if(A.row != B.row && A.column != B.column)
		throw std::string("Error.\nMatrices dimensions do not match.");

	//matrix to be returned
	Matrix C(A.row, A.column);
	
	long unsigned sum, i, j;
	for(i = 0; i < C.row; i++)
	{
		for(j = 0; j < C.column; j++)
		{
			sum = A.arr[i][j] + (-1*(B.arr[i][j]));
			//distributing the neg sign by multiplying by -1
			C.arr[i][j] = sum;
		}
	}

	return C;
}

Matrix operator* (const Matrix& A, const Matrix& B)
{
	if(A.row != B.row && A.column != B.column)
		throw std::string("Error.\nMatrices dimensions do not match.");

	//matrix to be returned
	Matrix C(A.row, A.column);

	int sum, i, j, l;
	for(long unsigned i = 0; i < A.row; i++)
	{
		for(long unsigned j = 0; j < B.column; j++)
		{
			sum = 0;
			for(long unsigned l = 0; l < B.row; l++)
			{
				sum += A.arr[i][l]*B.arr[l][j];
				C.arr[i][j] = sum;
			}
		}
	}

	return C;
}

Matrix operator*(int x, const Matrix& A)
{
	if(A.row == 0 && A.column == 0)
		throw std::string("Error.\nMatrix size is non existent.");

	//matrix to be returned
	Matrix B(A.row, A.column);

	for(long unsigned i = 0; i < A.row; i++)
	{
		for(long unsigned j = 0; j < A.column; j++)
			B.arr[i][j] = x*(A.arr[i][j]);

	}

	return B;
}


void Matrix::display()
{
	for(long unsigned i = 0; i < row; i++)
	{
		for(long unsigned j = 0; j < column; j++)
		{
			if(arr[i][j] != 0)
				std::cout << GREEN << std::right << std::setw(5) << arr[i][j] << " " << RESET;
			else	
				std::cout << std::right << std::setw(5) << arr[i][j] << " ";
		}
		std::cout << "\n";
	}
}