#ifndef TEXTBOOK_H
#define TEXTBOOK_H
#include "book.h"
#include <string>

class TextBook: public Book
{
	private:
		std :: string subjectMatter;

	public:
		TextBook(bookCover bc = HardCover, int pg = 0, std :: string subject = "n/a");
		virtual void describe();	//display pageLength & and cover type


};

#endif