#ifndef BOOK_H
#define BOOK_H
#include <string>

enum bookCover {HardCover, SoftCover};

class Book
{
	protected:
		bookCover cover;	//hard cover or soft cover
		int pageLength;
	public:
		Book(bookCover bc = HardCover, int pg = 0);
		virtual void describe();	//display pageLength & and cover type
};

#endif
