#include <iostream>
#include "textbook.h"

TextBook :: TextBook(bookCover bc, int pg, std :: string subject)
{
	cover = bc;
	pageLength = pg;
	subjectMatter = subject;
}

void TextBook :: describe()
{
	//"\nSubject: " << subjectMatter << 
	std :: cout << "\n" << pageLength << " pages";
	if(cover == 0)
	{
		std :: cout << "\nHard Cover" << std :: endl;
	}
	else std :: cout << "\nSoft Cover" << std :: endl;
}
