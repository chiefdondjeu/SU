#include <iostream>

#include "d_dnode.h"
#include "d_dnodeList.h"

int main()
{
	dNode<int> *myList = new dNode<int>;
	//makes the first node value 0. I don't know why

	int val,i;
	std :: cout << "Enter 10 numbers from 0-99: ";

	for(i = 0; i < 10; i++)
	{
		std :: cin >> val;
		add(myList,val);
	}
	std :: cout << "\nlist: ";
	display(myList);

	removeOdd(myList);
	std :: cout << "modified list: ";
	display(myList);

	return 0;
}