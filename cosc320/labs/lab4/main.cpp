/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *lab4
 *main.cpp
 *Feb 26, 2020
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <time.h>

#include "matrix.h"

#define RESET "\033[0m"
#define RED "\033[31m"

void MatrixAdd(Matrix&, Matrix&, Matrix&);
	//function to be timed
void MatrixSub(Matrix&, Matrix&, Matrix&);
	//function to be timed
void MatrixMult(Matrix&, Matrix&, Matrix&);
	//function to be timed
void timeMatrix(void(*mult) (Matrix&, Matrix&, Matrix&), 
								Matrix& X, Matrix& Y, Matrix& Z);
	//time function

int size_tracker = 0;
long unsigned size[7] = {100, 250, 500, 750, 1000, 1250, 1500};
	//testing sizes

int main()
{
	srand(time(0));	
	//makes it so we get diffent random numbers generated for our
	//fill<order_type>() functions.

	char choice;
	std::cout << "\nShow demo (y/n): ";
	std::cin >> choice;

	if(choice == 'y' || choice == 'Y')
	{
		try{

		long unsigned s = 10;

		//mult
		Matrix A(s,s);
		Matrix B(s,s);
		A.fillRandom();
		B.fillRandom();	

		//add
		Matrix C(s,s);
		Matrix D(s,s);
		C.fillRandom();
		D.fillRandom();

		//sub
		Matrix E(s,s);
		Matrix F(s,s);
		E.fillRandom();
		F.fillRandom();

		//scalar
		Matrix G(s,s);
		G.fillRandom();

		//diagonal
		Matrix H(s,s);
		H.fillDiagonal();

		//triangle
		Matrix I(s,s);
		Matrix J(s,s);
		I.fillTriangleDown();
		J.fillTriangleUp();

		//identity
		Matrix Identity(s,s);
		Matrix L(s,s);
		Identity.fillIdentity();
		L.fillRandom();

		Matrix result;

		//std::cout << std::endl;
		std::cout << "=========================================================" << std::endl;
		std::cout << "Demo: 10x10 Matrix multiplication." << std::endl;
		result = A*B;

		std::cout << "Matrix A: " << std::endl;
		A.display();
		std::cout << "\nMatrix B: " << std::endl;
		B.display();
		std::cout << "\nProduct: A*B" << std::endl;
		result.display();
		
		std::cout << "\n=========================================================" << std::endl;
		std::cout << "Demo: 10x10 Matrix addition." << std::endl;
		result = C+D;

		std::cout << "Matrix C: " << std::endl;
		C.display();
		std::cout << "\nMatrix D: " << std::endl;
		D.display();
		std::cout << "\nSum: C+D" << std::endl;
		result.display();
		
		std::cout << "\n=========================================================" << std::endl;
		std::cout << "Demo: 10x10 Matrix substraction." << std::endl;
		result = E-F;

		std::cout << "Matrix E: " << std::endl;
		E.display();
		std::cout << "\nMatrix F: " << std::endl;
		F.display();
		std::cout << "\nDifference: E-F" << std::endl;
		result.display();
		
		std::cout << "\n=========================================================" << std::endl;
		std::cout << "Demo: Matrix scalar multiplication (x5)." << std::endl;
		result = 5*G;

		std::cout << "Matrix G: " << std::endl;
		G.display();
		std::cout << "\nProduct: 5*G" << std::endl;
		result.display();

		std::cout << "\n=========================================================" << std::endl;
		std::cout << "Demo: Diagonal Matrix." << std::endl;
		H.display();

		std::cout << "\n=========================================================" << std::endl;
		std::cout << "Demo: Triangular Matrix." << std::endl;
		I.display();
		std::cout << std::endl;
		J.display();

		std::cout << "\n=========================================================" << std::endl;
		std::cout << "Demo: Identity Matrix." << std::endl;
		result = Identity*L;

		std::cout << "Identity" << std::endl;
		Identity.display();
		std::cout << "\nMatrix L: " << std::endl;
		L.display();
		std::cout << "\nProduct: Identity*L" << std::endl;
		result.display();

		//std::cout << std::endl;

		}catch(std::string& caught)
		{
			std::cout << caught << std::endl;
		}
		
	}//end if for demo

	long unsigned s = size[size_tracker];

	std::cout << "\n===========================================================" << std::endl;
	std::cout << "MATRIX ADDITION DATA" << std::endl;
	std::cout << "size: 100~1500\n" << std::endl;

	size_tracker = 0;
	s = size[size_tracker];
	Matrix result;

	{//start add
		Matrix A(s,s);
		Matrix B(s,s);
		A.fillRandom();
		B.fillRandom();
		timeMatrix(MatrixAdd,A,B,result);

		s = size[size_tracker];
		Matrix C(s,s);
		Matrix D(s,s);
		timeMatrix(MatrixAdd,C,D,result);

		s = size[size_tracker];
		Matrix E(s,s);
		Matrix F(s,s);
		timeMatrix(MatrixAdd,E,F,result);

		s = size[size_tracker];
		Matrix G(s,s);
		Matrix H(s,s);
		timeMatrix(MatrixAdd,G,H,result);

		s = size[size_tracker];
		Matrix I(s,s);
		Matrix J(s,s);
		timeMatrix(MatrixAdd,I,J,result);

		s = size[size_tracker];
		Matrix K(s,s);
		Matrix L(s,s);
		timeMatrix(MatrixAdd,K,L,result);

		s = size[size_tracker];
		Matrix M(s,s);
		Matrix N(s,s);
		timeMatrix(MatrixAdd,M,N,result);
	}//end add

	std::cout << "\n===========================================================" << std::endl;
	std::cout << "MATRIX SUBSTRACTION DATA" << std::endl;
	std::cout << "size: 100~1500\n" << std::endl;

	size_tracker = 0;
	s = size[size_tracker];

	{//start sub
		Matrix A(s,s);
		Matrix B(s,s);
		A.fillRandom();
		B.fillRandom();
		timeMatrix(MatrixSub,A,B,result);

		s = size[size_tracker];
		Matrix C(s,s);
		Matrix D(s,s);
		timeMatrix(MatrixSub,C,D,result);

		s = size[size_tracker];
		Matrix E(s,s);
		Matrix F(s,s);
		timeMatrix(MatrixSub,E,F,result);

		s = size[size_tracker];
		Matrix G(s,s);
		Matrix H(s,s);
		timeMatrix(MatrixSub,G,H,result);

		s = size[size_tracker];
		Matrix I(s,s);
		Matrix J(s,s);
		timeMatrix(MatrixSub,I,J,result);

		s = size[size_tracker];
		Matrix K(s,s);
		Matrix L(s,s);
		timeMatrix(MatrixSub,K,L,result);

		s = size[size_tracker];
		Matrix M(s,s);
		Matrix N(s,s);
		timeMatrix(MatrixSub,M,N,result);
	}//end sub

	std::cout << "\n===========================================================" << std::endl;
	std::cout << "MATRIX MULTIPLICATION DATA" << std::endl;
	std::cout << "size: 100~1500\n" << std::endl;

	size_tracker = 0;
	s = size[size_tracker];

	{//start mult
		Matrix A(s,s);
		Matrix B(s,s);
		A.fillRandom();
		B.fillRandom();
		timeMatrix(MatrixMult,A,B,result);

		s = size[size_tracker];
		Matrix C(s,s);
		Matrix D(s,s);
		timeMatrix(MatrixMult,C,D,result);

		s = size[size_tracker];
		Matrix E(s,s);
		Matrix F(s,s);
		timeMatrix(MatrixMult,E,F,result);

		s = size[size_tracker];
		Matrix G(s,s);
		Matrix H(s,s);
		timeMatrix(MatrixMult,G,H,result);

		s = size[size_tracker];
		Matrix I(s,s);
		Matrix J(s,s);
		timeMatrix(MatrixMult,I,J,result);

		s = size[size_tracker];
		Matrix K(s,s);
		Matrix L(s,s);
		timeMatrix(MatrixMult,K,L,result);

		s = size[size_tracker];
		Matrix M(s,s);
		Matrix N(s,s);
		timeMatrix(MatrixMult,M,N,result);
	}//end mult


	return 0;
}

void MatrixAdd(Matrix& X, Matrix& Y, Matrix& Z)
{
	Z = X+Y;
}

void MatrixSub(Matrix& X, Matrix& Y, Matrix& Z)
{
	Z = X-Y;
}

void MatrixMult(Matrix& X, Matrix& Y, Matrix& Z)
{
	Z = X*Y; 
}

void timeMatrix(void(*mult) (Matrix&, Matrix&, Matrix&), 
												Matrix& X, Matrix& Y, Matrix& Z)
{
	clock_t t;
	t = clock();
	mult(X,Y,Z);
	t = clock()-t;
	std::cout << size[size_tracker] << "x" << size[size_tracker] 
						<< " Matrix" << std::endl;
	std::cout << "elasped time: " << RED << ((float)t)/CLOCKS_PER_SEC
							<< "s\n"  << RESET << std :: endl;
	size_tracker++;
	t = 0;
}

