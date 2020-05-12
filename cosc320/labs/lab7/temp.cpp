#include <iostream>
#include <string>

int main()
{
	std::string wrd = "This is a sentence";
	char space = ' ';

	std::string newWrd;
	char ch;
	for(int i = 0; i < wrd.length(); i++)
	{
		ch = wrd[i];
		if(ch == space)
		{
			std::cout << newWrd << std::endl;
			newWrd = "";
			i++;
		}

		newWrd += wrd[i];
	}
	std::cout << newWrd << std::endl;

	return 0;
}