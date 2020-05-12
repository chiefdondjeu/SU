#include "palindromeAux.h"
#include <iostream>
#include <string>

bool isPal(const std :: string& str, int startIndex, int endIndex)
{
	if(str[startIndex] != str[endIndex])
	{
		return false;
	}

	if(startIndex >= endIndex-1)
	{
		return true;
	}

	isPal(str, startIndex+1, endIndex-1);

	return true;
}