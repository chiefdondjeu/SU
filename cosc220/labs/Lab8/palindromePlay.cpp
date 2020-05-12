#include <iostream>
#include "palindromeAux.h"

int main()
{
	std :: string s;
	std :: cout << "Enter a word: ";
	std :: cin >> s;

	if(isPal(s,0,s.size()-1) == true)
	{
		std :: cout << s << " is a palindrome.\n";
	}
	
	else std :: cout << s << " is not a palindrome.\n";

	return 0;
}
