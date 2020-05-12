#include <iostream>
#include <string>
#include "ex28Aux.h"

int main()
{	
	/*
	int intListA[5] = {1, 9, 3, 9, 5}, intListB[5];
	int m;

	f(intListA, 5, intListB, m, 9);
	std :: cout << "intListB = ";

	for(int i = 0; i < m; i++)
	{
		std :: cout << intListB[i] << ", ";
	}
	std :: cout << "\nm = " << m << "\n" ;
	*/

	std :: string strListA[7] = {"cat", "rat", "bird", "dog", "rat", "fish", "rat"};
	std :: string strListB[7];
	int m;

	f(strListA, 7, strListB, m, std :: string("rat"));
	std :: cout << "strListB = ";

	for(int i = 0; i < m; i++)
	{
		std :: cout << strListB[i] << ", ";
	}
	std :: cout << "\nm = " << m << "\n" ;

	return 0;	
}