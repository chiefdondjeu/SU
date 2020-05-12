#include "hanoiAux.h"
#include <iostream>

void hanoi(int n, char A, char B, char C)
{				//start		mid 	end
	if(n == 1)
	{
		std :: cout << "move: " << A << " to " << C << std :: endl;
		return;
	}
	hanoi(n-1, A, C, B);
	std :: cout << "move: " << A << " to " << C << std :: endl;
	hanoi(n-1,B, A, C);
}