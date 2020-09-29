//Florent Dondjeu Tschoufack
//Sept 29, 2020
//lab4
//task1.c

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//convert string to integer
int convertToInt(char *str, int n);

//convert integer to string
int convertToStr(char* str, int x);

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Need to pass in one argument!\n");
        exit(1);
    }
    
    int fd; //file descriptor

    //open given file for read only
    if( (fd = open(argv[1], O_RDONLY)) < 0)
    {
        printf("Open %s file error\n", argv[1]);
        exit(2);
    }

	//get size of line in the file
	int size = lseek(fd,0,SEEK_END);
	//reset cursor position
	lseek(fd,0,SEEK_SET);

	char buf, str[size];
	int i = 0;

	//printf("Size: %d\n",size);

    while( (read(fd,&buf,1)) == 1)
    {
		//if character read ranges 0-9 add to str
		if(buf >= '0' && buf <= '9')
		{
			//printf("buffer: %c\n",buf);
			str[i] = buf;
			i++;
		}
    }
	close(fd);

	//printf("new Size: %d\n", i);

	//numbers of char in str[]
	int newSize = i;
	char str2[newSize];

	//convert to int
	int x = convertToInt(str,newSize);

	//printf("\nx: %d\n",x);

	//add 10
	x += 10;

	//convert to string
	convertToStr(str2,x);
	
	//write to console
	write(1,str2,i);
	printf("\n");

    return 0;
}

int convertToInt(char* str, int n)
{
	/*
    	int offset, sign;

		//check if number is negative
		if(str[0] == '-')
			offset = sign = 1;
		else
			offset = sign = 0;
	*/

    int numb = 0;

    //convert
    for(int i = 0; i < n;i++)
        numb = numb * 10 + str[i] - '0';

	/*
    	//turn negative if originaly negative
    	if(sign == 1)
        	numb = -numb;
	*/

    return numb;
}

int convertToStr(char* str, int x)
{
    sprintf(str, "%d", x);
	return (strlen(str));
}
