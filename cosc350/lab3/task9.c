//Florent Dondjeu Tschoufack
//Sept 28, 2020
//lab3
//task9.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

//checks if a file contains a plindrome
int palind(int fd1, int fd2);

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Need to pass in one argument only\n");
		exit(1);
	}

	int fd1, fd2;	//file descriptors
	int result;

	//open argument file for read only
	if( (fd1 = open(argv[1],O_RDONLY)) < 0)
	{
		printf("Open %s file error", argv[1]);
		exit(2);
	}

	//make duplicate
	fd2 = dup(fd1);

	//check for palindrome
	result = palind(fd1,fd2);

	if(result == 0)
		printf("%s file contains a palindrome\n",argv[1]);
	else
		printf("%s file does not contain a palindrome\n",argv[1]);

	close(fd1);
	close(fd2);

	return 0;
}

int palind(int fd1, int fd2)
{
	char c1, c2;
	int size = lseek(fd2,1,SEEK_END);

	for(int i = 0; i < size; i++)
	{	
		//read from the begining of the file
		lseek(fd1,i,SEEK_SET);
		read(fd1,&c1,1);

		//read from end of the file
		lseek(fd2,-1-i,SEEK_END);
		read(fd2,&c2,1);

		//printf("%d: %c = %c\n",i,c1,c2);

		//if the buffers are not eqaul then file does not have a palindrome
		if(c1 != c2)
			return 1;	//false
	}

	return 0;	//true
}