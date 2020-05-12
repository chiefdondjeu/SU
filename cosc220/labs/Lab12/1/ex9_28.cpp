#include <iostream>
#include <ctime>
#include <cstdlib>

#include "d_node.h"
#include "d_nodeList.h"

int main()
{
	Node<int> *myList = NULL;

	srand(time(0));
	int val, search, search2;

	std :: cout << "STEP 2" << std :: endl;
	for(int i = 0; i < 5; i++)
	{
		val = (rand()% 20)+1;
		myList = new Node<int>(val, myList);
	}
	std :: cout << "List : ";
	display(myList);
	std :: cout << "Element count: " << numbElement(myList) << std :: endl;

	std :: cout << "\nSTEP 3" << std :: endl;
	push_back(myList,2);
	push_back(myList,1);
	push_back(myList,3);
	push_back(myList,5);
	push_back(myList,4);
	std :: cout << "List : ";
	display(myList);
	std :: cout << "Element count: " << numbElement(myList) << std :: endl;

	std :: cout << "\nSTEP 4" << std :: endl;
	myList = push_front(myList,2);
	myList = push_front(myList,1);
	myList = push_front(myList,3);
	myList = push_front(myList,5);
	myList = push_front(myList,4);
	std :: cout << "List : ";
	display(myList);
	std :: cout << "Element count: " << numbElement(myList) << std :: endl;
	
	std :: cout << "\nSTEP 5" << std :: endl;
	std :: cout << "Enter a numb to be deleted: ";
	std :: cin >> search;
	myList = erase(myList,search);
	std :: cout << "List : ";
	display(myList);
	std :: cout << "Element count: " << numbElement(myList) << std :: endl;

	std :: cout << "\nSTEP 6" << std :: endl;
	std :: cout << "number search: ";
	std :: cin >> search2;
	if(isIn(myList, search2) == true)
		std :: cout << "Number is in list\n\n";
	else
		std :: cout << "Number is not in list\n\n";


	return 0;
}