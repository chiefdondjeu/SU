#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define RESET "\033[00m"
#define RED "\033[31m"
#define GREEN "\033[32m"

//integer hashing function
size_t hash(size_t);

//string hashing function
//converts string to a numerical value
size_t hashV1(std::string);

//string hash function v2
//converts string to a numerical value
size_t hashV2(std::string);

//returns the hash value in hexa
void hashInt(size_t);

//splits the string into words and hash individualy,
//then sum the hash and prints in hexa
void hashStringV1(std::string);

//same thing has hashStringV1 instead
//it uses hashv2 to hash strings
void hashStringV2(std::string);

int main()
{
	srand(time(0));

	size_t randnumb;
	for(int i = 0; i < 10; i++)
	{
		randnumb = (rand()%1000000)+1;	//1~1,000,000
		std::cout << "Input: " << GREEN << randnumb << std::endl << RESET;
		hashInt(randnumb);

		std::cout << std::endl;
	}

	std::string wrd;

	wrd = "I love apples";
	std::cout << "Input: " << GREEN << wrd << std::endl << RESET;
	hashStringV1(wrd);
	hashStringV2(wrd);
	std::cout << std::endl;

	wrd = "I love apple";
	std::cout << "Input: " << GREEN << wrd << std::endl << RESET;
	hashStringV1(wrd);
	hashStringV2(wrd);
	std::cout << std::endl;

	wrd = "The sky is blue and the sun is yellow.";
	std::cout << "Input: " << GREEN << wrd << std::endl << RESET;
	hashStringV1(wrd);
	hashStringV2(wrd);
	std::cout << std::endl;

	wrd = "I have been coding for almost 2 years now, and it can be very difficult at times";
	std::cout << "Input: " << GREEN << wrd << std::endl << RESET;
	hashStringV1(wrd);
	hashStringV2(wrd);
	std::cout << std::endl;

	wrd = "I am a random string :)";
	std::cout << "Input: " << GREEN << wrd << std::endl << RESET;
	hashStringV1(wrd);
	hashStringV2(wrd);
	std::cout << std::endl;

	wrd = "ASCII stands for American Standard Code for Information Interchange. Computers can only understand numbers, so an ASCII code is the numerical representation of a character such as 'a' or '@' or an action of some sort. ASCII was developed a long time ago and now the non-printing characters are rarely used for their original purpose. Below is the ASCII character table and this includes descriptions of the first 32 non-printing characters.";
	std::cout << "Input: " << GREEN << wrd << std::endl << RESET;
	hashStringV1(wrd);
	hashStringV2(wrd);
	std::cout << std::endl;

	wrd = "[deleted sentence]. Computers can only understand numbers, so an ASCII code is the numerical representation of a character such as 'a' or '@' or an action of some sort. ASCII was developed a long time ago and now the non-printing characters are rarely used for their original purpose. Below is the ASCII character table and this includes descriptions of the first 32 non-printing characters.";
	std::cout << "Input: " << GREEN << wrd << std::endl << RESET;
	hashStringV1(wrd);
	hashStringV2(wrd);

	return 0;
}

//hashes integer values
size_t hash(size_t x)
{
	size_t w = 32;	//only works for 32
	size_t p = 30;	//has to  be less than w
	size_t a = 9999999929;	//10 digit prime number

	size_t ax = a*x;
	size_t W = (size_t)1<<w;	//2^w
	size_t axmodW = ax & (W-(size_t)1);

	size_t hash = axmodW>>(w-p);
	return hash;
}

//sum all the values of each characters
//then hashes that value using the integer hashing function
size_t hashV1(std::string wrd)
{
	size_t sum = 0;
	size_t temp;
	for(int i = 0; i < wrd.length();i++)
	{
		temp = wrd[i];
		sum += temp;
	}

	return hash(sum);
}

//similar to the previous hash function for string
//but this time, we multiply the ascii value with the
//position of the character then add to the sum
size_t hashV2(std::string wrd)
{
	size_t sum = 0;
	size_t temp;
	for(size_t i = 0; i < wrd.length(); i++)
	{
		temp = ((size_t)wrd[i])*i;
		sum += temp;
	}

	return hash(sum);
}

void hashInt(size_t x)
{
	std::cout << "Hash value: " << RED << std::hex << hash(x) << std::dec << std::endl << RESET;
}

void hashStringV1(std::string wrd)
{
	size_t sumHash = 0;	//will hold the total hash value of each words
	
	std::string newWrd;	//take a whole word without space from wrd
	char space = ' ';	//what we are looking for
	char ch;	//for comparison

	for(int i = 0; i < wrd.length(); i++)
	{
		ch = wrd[i];
		if(ch == space)
		{
			//std::cout << newWrd << std::endl;
			sumHash += hashV1(newWrd);
			i++;	//increment to skip space
			newWrd = "";	//reset
		}
		newWrd += wrd[i];

		//for last word
		if(i == (wrd.length()-1))
			sumHash += hashV1(newWrd);
	}
	//std::cout << newWrd << std::endl;

	std::cout << "Hash(v1) value: " << RED << std::hex << sumHash << std::dec << std::endl << RESET;
}

void hashStringV2(std::string wrd)
{
	size_t sumHash = 0;	//will hold the total hash value of each words
	
	std::string newWrd;	//take a whole word without space from wrd
	char space = ' ';	//what we are looking for
	char ch;	//for comparison

	for(int i = 0; i < wrd.length(); i++)
	{
		ch = wrd[i];
		if(ch == space)
		{
			sumHash += hashV2(newWrd);
			i++;	//increment to skip space
			newWrd = "";	//reset
		}
		newWrd += wrd[i];

		//for last word
		if(i == (wrd.length()-1))
			sumHash += hashV2(newWrd);
	}

	std::cout << "Hash(v2) value: " << RED << std::hex << sumHash << std::dec << std::endl << RESET;
}