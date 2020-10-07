//Florent Dondjeu Tschoufack
//Oct 7, 2020
//lab4
//task2.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

//I changed task8 from lab3 to print spaces between each ascii number, 
//so input file should look like 21 8 104 23 ...

//convert string to integer
int convertToInt(char *str, int n)
{
	int numb = 0;
	for (int i = 0; i < n; i++)
		numb = numb * 10 + str[i] - '0';

	return numb;
}

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Need to pass in two argument!\nName of input and output file.\n");
		exit(1);
	}

	int fd1, fd2; //file descriptors
	int nr, size;
	char buf;

	//open input file for read only
	if( (fd1 = open(argv[1], O_RDONLY)) < 0)
		printf("Open %s file error\n", argv[1]);

	//reset permission for file
	umask(0);

	//open output file, create rw-rw-rw
	if( (fd2 = open(argv[2], O_RDWR | O_CREAT, 0666)) < 0)
		printf("Open create %s file error\n", argv[2]);
	
	if(fd1 > 0 && fd2 > 0)
	{	
		char str[3];
		int i = 0;	//index

		//read char until reach space
		//converts read char before space into integer
		//convert integer into char
		//write converted char to output file
		while( (read(fd1,&buf,1)) == 1)
		{	
			if(buf != ' ')
			{
				str[i] = buf;
				i++;
			}
			else if(buf >= (char)0 && buf <= (char)127)
			{
				//printf("%s ", str);
				int val = convertToInt(str,i);
				//printf("%d\n", val);
				char ch = (char)val;
				write(fd2,&ch,1);
				i = 0;	//reset 
			}

		}

	}
	else
		printf("Reading %s file error\n", argv[1]);

	close(fd1);
	close(fd2);

	return 0;
}