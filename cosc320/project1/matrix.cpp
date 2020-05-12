/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Project 1
 *matrix.cpp
 *Feb 26, 2020
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cmath>

#include "matrix.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"


/*
 *fills matrix with 0s
 */
void Matrix::fillMatrix()	//private function
{
	unsigned long i, j;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			arr[i][j] = 0;
		}
	}
}


/*
 *default constructor
 */
Matrix::Matrix()
{
	row = 1;
	column = 1;

	//1x1 matrix
	arr = new double*[1];
	arr[0] = new double[1];

	fillMatrix();//fill with zeros
}


/*
 *creates an empty dynamic matrix with specified dimesion
 */
Matrix::Matrix(unsigned long n, unsigned long m)
{
	if((n*m) == 0)
		throw std::string("ERROR: Invalid matrix size.");

	row = n;
	column = m;

	//allocate memory
	arr = new double*[n];
	for(unsigned long i = 0; i < n; i++)
		arr[i] = new double[m];
	
	fillMatrix();//fill with zeros
}


/*
 *copy constructor
 */
Matrix::Matrix(const Matrix& A)
{
	this->row = A.row;
	this->column = A.column;

	//allocate memory
	arr = new double*[row];
	unsigned long i, j;
	for(i = 0; i < row; i++)
		arr[i] = new double[column];

	//copy
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
			arr[i][j] = A.arr[i][j];
	}

}


/*
 *make a dynamic copy of a matrix
 */
void Matrix::operator= (const Matrix& A)
{
	//delete previous data
	if((row*column) != 0)
		this->Matrix::~Matrix();

	this->row = A.row;
	this->column = A.column;

	//allocate memory for new data
	arr = new double*[row];	
	unsigned long i, j;
	for(i = 0; i < row; i++)
		arr[i] = new double[column];

	//copy
	for(i = 0 ; i < row; i++)
	{
		for(j = 0; j < column; j++)
			arr[i][j] = A.arr[i][j];
	}

}


/*
 *deallocate memory and delete matrix
 */
Matrix::~Matrix()
{
	//delete columns
	for(unsigned long i = 0; i < row; i++)
		delete[] arr[i];

	//delete row
	delete[] arr;
}


/*
 *takes in user input and fill matrix
 */
void Matrix::input(unsigned long i, unsigned long j, double x)
{
	arr[i][j] = x;
}


/*
 *flips matrix over its diagonal
 */
Matrix Matrix::Transpose()
{
	//matrix to be returned
	Matrix A(column,row);

	//basically, we copy a row and set it has our column vice versa
	unsigned long i, j;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
			A.arr[j][i] = arr[i][j];
	}

	//return a transpose
	return A;
}


/*
 *computes the inverse of a matrix
 */
Matrix Matrix::Inverse()
{
	//not nxn
	if(row != column)
		throw std::string("Error!\nNot a Square matrix.");

	//matrix 1x1
	if(row*column == 1)
	{
		Matrix A;	//my default matrix is 1x1

		if(arr[0][0] != 0)
		{
			//reciprocal
			A.arr[0][0] = 1.0/(arr[0][0]);
			return A;
		}
		A.arr[0][0] = 0;
		return A;
	}

	/*FOR OTHER CASES*/

	//matrix to be returned
	Matrix AA = *this;

	bool needsPadding = false, needsSymmetry = false;

	//for padding
	unsigned long extra = 0;
	if(!this->isPowerOfTwo(row))
	{
		needsPadding = true;

		//get a power of two
		while(!isPowerOfTwo(row+extra))
			extra++;

		AA = AA.pad(extra);
	}

	//tranpose to undo symmetry later
	Matrix AAt = AA.Transpose();

	//check for symmetry
	if(!this->isSymmetric()) //not true
	{
		needsSymmetry = true;
		AA = AAt*AA;	//make symmetric
	}

	//	¯\_(ツ)_/¯
	Matrix B(AA.row/2,AA.column/2), Ct(AA.row/2,AA.column/2);
	Matrix C(AA.row/2,AA.column/2), D(AA.row/2,AA.column/2);

	//fill matrices
	unsigned long i,j;
	for(i = 0; i < AA.row; i++)
	{
		for(j = 0; j < AA.column; j++)
		{
			//top left corner
			if(i < AA.row/2 && j < AA.column/2)
				B.arr[i][j] = AA.arr[i][j];

			//top rigth corner
			if(i < AA.row/2 && j >= AA.column/2)
				Ct.arr[i][j- AA.column/2] = AA.arr[i][j];

			//bottom left corner
			if(i >= AA.row/2 && j < AA.column/2)
				C.arr[i- AA.row/2][j] = AA.arr[i][j];

			//bottom right corner
			if(i >= AA.row/2 && j >= AA.column/2)
				D.arr[i- AA.row/2][j- AA.column/2] = AA.arr[i][j];
		}
	}

	//2
	Matrix B_ = B.Inverse();	//underscore denotes inverse

	//3
	Matrix W = C*B_;
	Matrix Wt = B_*Ct;
	
	//4
	Matrix X = W*Ct;
	
	//5
	Matrix S = D-X;
	
	//6
	Matrix V = S.Inverse();
	
	//7
	Matrix Y = V*W;
	Matrix Yt = Y.Transpose();

	//8
	Matrix T = -1*Yt;
	Matrix U = -1*Y;

	//9
	Matrix Z = Wt*Y;
	Matrix R = B_+Z;

	//assemble
	for(i = 0; i < AA.row; i++)
	{
		for(j = 0; j < AA.column; j++)
		{
			//top left
			if(i < AA.row/2 && j < AA.column/2)
				AA.arr[i][j] = R.arr[i][j];

			//top right
			if(i < AA.row/2 && j >= AA.column/2)
				AA.arr[i][j] = T.arr[i][j- AA.column/2];

			//bottom left
			if(i >= AA.row/2 && j < AA.column/2)
				AA.arr[i][j] = U.arr[i- AA.row/2][j];

			//bottom right
			if(i >= AA.row/2 && j >= AA.column/2)
				AA.arr[i][j] = V.arr[i- AA.row/2][j- AA.column/2];
		}
	}

	//undo the symmetry
	if(needsSymmetry)
		AA = AA*AAt;

	//remove added rows if any
	if(needsPadding)
		AA = AA.unpad(extra);


	return AA;
}


/*
 *checks if matrix is symmetric
 */
bool Matrix::isSymmetric()
{
	//transpose matrix
	Matrix At = this->Transpose();

	//check
	unsigned long i,j;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			if(At.arr[i][j] != arr[i][j])
				return false;
		}
	}
	return true;
}


/*
 *returns false if not power of two
 */
bool Matrix::isPowerOfTwo(unsigned long x)
{
  return (x != 0) && ((x & (x - 1)) == 0);
}


/*
 *add an extra row of 0s if matrix is not a power of 2
 */
Matrix Matrix::pad(unsigned long x)
{
	//matrix to be returned
	Matrix A(row+x,column+x);

	//copy
	unsigned long i, j;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
			A.arr[i][j] = arr[i][j];
	}

	//add zeros
	for(i = row; i < row+x; i++)
	{
		for(j = column; j < column+x; j++)
			A.arr[i][j] = 0;
	}

	return A;
}


/*
 *removes extra row and column
 */
Matrix Matrix::unpad(unsigned long x)
{
	//exclude added row & column
	Matrix A(row-x, column-x);

	unsigned long i,j;
	for(i = 0; i < row-x; i++)
	{
		for(j = 0; j < column-x; j++)
		{
			A.arr[i][j] = arr[i][j];
		}
	}

	//unpadded matrix
	return A;
}


/*
 *matrix addition
 */
Matrix operator+ (const Matrix& A, const Matrix& B)
{
	if(A.row != B.row && A.column != B.column)
		throw std::string("ERROR: Matrices dimensions do not match.");
	
	//matrix to be returned
	Matrix C(A.row, A.column);
	
	double sum;
	unsigned long i, j;
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


/*
 *matrix subtraction
 */
Matrix operator- (const Matrix& A, const Matrix& B)
{
	if(A.row != B.row && A.column != B.column)
		throw std::string("ERROR: Matrices dimensions do not match.");

	//matrix to be returned
	Matrix C(A.row, A.column);
	
	double sum;
	unsigned long i, j;
	for(i = 0; i < C.row; i++)
	{
		for(j = 0; j < C.column; j++)
		{
			sum = A.arr[i][j] - B.arr[i][j];
			C.arr[i][j] = sum;
		}
	}

	return C;
}


/*
 *matrix multiplication
 */
Matrix operator* (const Matrix& A, const Matrix& B)
{
	if(A.column != B.row)
		throw std::string("ERROR: Matrices cannot be multiplied.");

	//matrix to be returned
	Matrix C(B.row,B.column);

	double sum;
	unsigned long i, j, l;
	for(i = 0; i < A.row; i++)
	{
		for(j = 0; j < B.column; j++)
		{
			sum = 0;
			for(l = 0; l < B.row; l++)
			{
				sum += A.arr[i][l]*B.arr[l][j];
				C.arr[i][j] = sum;
			}
		}
	}

	return C;
}


/*
 *matrix scalar multiplication
 */
Matrix operator*(double x, const Matrix& A)
{
	if(A.row == 0 && A.column == 0)
		throw std::string("Error: Matrix size is non existent.");

	//matrix to be returned
	Matrix B(A.row, A.column);

	unsigned long i, j;
	for(i = 0; i < A.row; i++)
	{
		for(j = 0; j < A.column; j++)
			B.arr[i][j] = x*(A.arr[i][j]);

	}

	return B;
}


/*
 *outputs elements of the matrix
 */
void Matrix::print()
{
	unsigned long i,j;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			if(arr[i][j] == 0)
				std::cout << std::right << std::setw(6) << arr[i][j] << " ";
			else if(arr[i][j] > 0)
				std::cout << GREEN << std::right << std::setw(6) << arr[i][j] << " " << RESET;
			else
				std::cout << RED << std::right << std::setw(6) << arr[i][j] << " " << RESET;
		}
		std::cout << std::endl;
	}
}


/*
 *fill matrix with random numbers
 */
void Matrix::fillrandom()
{
	double randnumb;
	for(long unsigned i = 0; i < row; i++)
	{
		for(long unsigned j = 0; j < column; j++)
		{
			randnumb = (rand()%10)+1;
			arr[i][j] = randnumb;
		}
	}
}


/*
 *fill the matrix as an identity matrix
 */
void Matrix::Identity()
{
	unsigned long i, j, r = 0, c = 0;
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


/*
 *used to make output nicer when computing for identity matrix
 */
void Matrix::round()
{
	unsigned long i,j;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			if(arr[i][j] < 0.5)
				arr[i][j] = 0;
		}
	}
}