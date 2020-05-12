#include <iostream>
#include "book.h"
#include "textbook.h"

void identify(Book b);
void identify(Book *b);
void identify(TextBook b);
void identify(TextBook *b);

int main()
{
/*	TextBook courseBook(HardCover, 950, "Computer Science");
	Book myDictionary(SoftCover, 625);

	courseBook.describe();
	std :: cout << "\n";
	myDictionary.describe();
*/
	Book cookBook(HardCover, 150);
	Book *p;
	TextBook poetry(SoftCover, 500, "English");
	TextBook *q;

	p = &cookBook;				
    identify(cookBook);
    identify(p);
    
	q = &poetry;
    identify(q);
    identify(poetry);

	p = &poetry;
	identify(p);

	std :: cout << "\n";
	return 0;
}

void identify(Book b)
{
	b.describe();
}

void identify(Book *b)
{
	b->describe();
}

void identify(TextBook b)
{
	b.describe();
}

void identify(TextBook *b)
{
	b->describe();
}
