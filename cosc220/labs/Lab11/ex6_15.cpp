#include <iostream>
#include <list>

#include "time24.h"

int main()
{
	std :: list<time24> tList;
	std :: list <time24>::iterator iter;

	tList.push_back(time24(8,30));
	tList.push_back(time24(13,45));
	tList.push_back(time24(7,25));
	tList.push_back(time24(11,15));
	tList.push_back(time24(18,20));
	tList.push_back(time24(21,50));

	std :: cout << "tList ";
	for(iter = tList.begin(); iter != tList.end(); iter++)
		std :: cout << *iter << " ";
	std :: cout << std :: endl;

	std :: list<time24> amList;
	std :: list<time24> pmList;

	for(iter = tList.begin(); iter != tList.end(); iter++)
	{
		if(*iter < time24(12,0))
			amList.push_back(*iter);
		else pmList.push_back(*iter);
	}

	std :: cout << "amList ";
	for(iter = amList.begin(); iter != amList.end(); iter++)
		std :: cout << *iter << " ";
	std :: cout << std :: endl;

	std :: cout << "pmList ";
	for(iter = pmList.begin(); iter != pmList.end(); iter++)
		std :: cout << *iter << " ";
	std :: cout << std :: endl;

	return 0;
}