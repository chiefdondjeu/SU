//Florent Dondjeu Tschoufack
//Sept 28, 2020
//lab3
//task8.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Need to pass in two argument!\n");
		exit(1);
	}

	int fd1, fd2; //file desciptors
	int nr;
	char c;

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
		//pipe output file to console
		dup2(fd2,1);
		
		//read input file
		while( (nr = read(fd1,&c,1)) > 0)
		{
			//convert read char to int
			nr = (int)c;
			//print to console
			printf("%d ",nr);
		}
	}
	else 
		printf("Reading %s file error\n", argv[1]);

	close(fd1);
	close(fd2);

	return 0;
}
