#include <iostream>
#include <list>
#include<ctime>
#include<cstdlib>

int main()
{
	std :: list<int> intList;
	std :: list<int>::iterator iter;

	int val, numb;
	bool greater = false;

	std :: cout << "Enter a number 1-100: ";
	std :: cin >> numb;

	srand(time(0));
	for(int i = 0; i <= 10; i++)
	{
		val = (rand()%100) + 1;
		intList.push_back(val);
	}

	for(iter = intList.begin(); iter != intList.end(); iter++)
	{
		if(*iter > numb)
		{
			greater = true;
			break;
		}
	}

	if(greater == true)
		std :: cout << "Number(s) in intList greater than " << numb << std :: endl;
	else
	{
		std :: cout << "There are no numbers in intList greater than " << numb << std :: endl;
		exit(0);
	}

	for(iter = intList.begin(); iter != intList.end(); iter++)
	{
		if(*iter > val)
			std :: cout << *iter << " ";
	}
	std :: cout << std :: endl;
	
	return 0;
}