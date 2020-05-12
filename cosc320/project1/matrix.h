/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Project 1
 *matrix.h
 *Feb 26, 2020
 */

#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
	private:
		
		//fillMatrix
		//fills matrix with 0s
		//parameter: none
		//retun: none
		//precondition: none
		//postcondition: matrix is filled with zeros
		void fillMatrix();

	public:

		//dimensions
		unsigned long row;
		unsigned long column;

		//matrix
		double **arr;

		//Matrix
		//default constructor
		//parameter: none
		//return: none
		//precondition: none
		//postcondition: none
		Matrix();

		//Matrix
		//creates an empty dynamic matrix with specified dimesion
		//parameter: value for row, value for column
		//returns: none
		//precondition: row and column cannot equal zero
		//postcondition: empty matrix filled with zeros
		Matrix(unsigned long, unsigned long);

		//Matrix
		//make a dynamic copy of a matrix
		//parameter: matrix with data to be copied
		//return: none
		//precondition: none
		//post condition: matrix data is successfully copied
		Matrix(const Matrix&);

		//operator=
		//make a dynamic copy of a matrix
		//parameter: matrix with data to be copied
		//return: none
		//precondition:
		//post condition: matrix data is successfully copied
		void operator= (const Matrix&);

		//~Matrix
		//deallocate memory and delete matrix
		//parameter: none
		//return: none
		//precondition: none
		//postcondition: memory is freed and matrix is deleted
		~Matrix();

		//input
		//takes in user input and fill matrix
		//parameter: specified row and column, and value to be stored
		//return: none
		//precondition: none
		//postcondition: value has been stored in matrix
		void input(unsigned long,unsigned long,double);

		//Transpose
		//flips matrix over its diagonal
		//paramter: none
		//return: return transpose of curr matrix
		//precondition: square matrix only
		//postcondition: transpose matrix
		Matrix Transpose();

		//Inverse
		//turn a matrix into its inverse
		//paramter:none
		//retun: the inverse of a matrix
		//precondition: matrix must be a sqaure matrix
		//postcondition: inverse of matrix
		Matrix Inverse();

		//isSymmetric
		//determines if a matrix is symmetric or not
		//parameter: none
		//return: true if matrix is symmetric
		//precondition: none
		//postcondition: none
		bool isSymmetric();

		//isPowerOfTwo
		//check if matrix is a power of two, might need padding
		//parameter: val to be determined if power of 2
		//return: true
		//precondition:
		//postcondition: none
		bool isPowerOfTwo(unsigned long);

		//padd
		//add an extra row of 0s if matrix is not a power of 2
		//paramter: none
		//return: a padded matrix if needed padding
		//preconditon: none
		//postcondition: matrix is padded to be a power of 2
		Matrix pad(unsigned long);

		//unpadd
		//removes extra row and column
		//paramter: number of row and column to be removed
		//return: an unpadded matrix
		//preconditon: none
		//postcondition: matrix is reverted to original dimension
		Matrix unpad(unsigned long);
		
		//operator+
		//matrix addition
		//parameter: two matrices
		//return: matrices sum
		//precondition: matrices must have same dimension
		//postcondition: sum of the matrices is returned
		friend Matrix operator+ (const Matrix&, const Matrix&);

		//operator-
		//matrix subtraction
		//parameter: two matrices
		//return: matrices difference
		//precondition: matrices must have same dimension
		//postcondition: difference of matrices is returned
		friend Matrix operator- (const Matrix&, const Matrix&);

		//operator*
		//matrix multiplication
		//parameter: two matrices
		//return: a matrix
		//precondition: matrix A column == matrix b row
		//postcondition: product of the matrices is returned
		friend Matrix operator* (const Matrix&, const Matrix&);

		//operator*
		//matrix scalar multiplication
		//paramter: scalar value and a matrix
		//return: matrix product of scalar and matrix
		//precondition: matrix dimension does not equall zero
		//postcondition: 
		friend Matrix operator* (double, const Matrix&);

		//print
		//outputs elements of the matrix
		//parameter: none
		//return: none
		//precondition: none
		//postcondition: every element in the matrix is outputed to the console
		void print();

		//fillrandom
		//fill matrix with random numbers
		//parameter: none
		//return: none
		//precondition: none
		//postcondition: matrix is filled with random numbers
		void fillrandom();

		//Identity
		//fill the matrix as an identity matrix
		//parameter: none
		//return: none
		//precondition: none
		//postcondition: only 1s on the diagonal
		void Identity();


		//used to make output nicer when computing for identity matrix
		void round();
};

#endif