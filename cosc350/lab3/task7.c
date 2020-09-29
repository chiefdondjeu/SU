//Florent Dondjeu Tschoufack
//Sept 28, 2020
//lab3
//task7.c

#include <stdio.h>
#include <stdlib.h>

//converts a string to an int
int convert(char str[]);

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		printf("Need to pass in at least one argument\n");
		exit(1);
	}

	int integers[argc];

	//store integers from argument
	for(int i = 1; i < argc; i++)
		integers[i] = convert(argv[i]);
	
	//add up all integers from the array
	int sum = 0;
	for(int i = 1; i < argc; i++)
		sum += integers[i];
	
	printf("Sum: %d\n", sum);

	return 0;
}

int convert(char str[])
{
	int offset, sign;

	//check if number is negative
	if(str[0] == '-')
		offset = sign = 1;
	else
		offset = sign = 0;
	
	int numb = 0;

	//convert
	for(int i = offset; str[i] != '\0' ; i++)
		numb = numb * 10 + str[i] - '0';
	
	//turn negative if orignaly negative
	if(sign == 1)
		numb = -numb;
	
	return numb;
}