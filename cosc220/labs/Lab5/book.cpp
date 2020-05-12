#include <iostream>
#include "book.h"

Book :: Book(bookCover bc, int pg): cover(bc), pageLength(pg)
{

}

void Book :: describe()
{
	std :: cout << "\n" << pageLength << " pages";
	if(cover == 0)
	{
		std :: cout << "\nHard Cover" << std :: endl;
	}
	else std :: cout << "\nSoft Cover" << std :: endl;
}