#include <iostream>
#include "hanoiAux.h"

int main()
{
	int n;
	std :: cout << "Enter number of discs: ";
	std :: cin >> n;
	hanoi(n,'a','b','c');
	
	return 0;
}
