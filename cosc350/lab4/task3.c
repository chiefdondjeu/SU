//Florent Dondjeu Tschoufack
//Oct 7, 2020
//lab4
//task3.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
	char* dir1 = "/Users/chiefdondjeu/Dir1";
	char* dir2 = "/Users/chiefdondjeu/Dir2";
	char* dir21 = "/Users/chiefdondjeu/Dir2/Dir21";

	//create directories
	umask(0);
	if( (mkdir(dir1,0700)) < 0)
		printf("mdkir Dir1 error!\n");

	umask(0);
	if( (mkdir(dir2,0700)) < 0)
		printf("mkdir Dir2 error!\n");

	umask(0);
	if( (mkdir(dir21,0700)) < 0)
		printf("mkdir Dir21 error!\n");

	int fd1,fd2;
	
	//copy and move hello to dir21
	if( (fd1=open("hello", O_RDONLY)) < 0)
		printf("Open hello file error!\n");
	
	//new hello path
	char* hello = "/Users/chiefdondjeu/Dir2/Dir21/hello";
	
	umask(0);
	if( (fd2=open(hello, O_RDWR | O_CREAT, 0777)) < 0)
		printf("Open ../Dir21/hello file error!\n");

	if(fd1 > 0 && fd2 > 0)
	{
		char buf;
		while( (read(fd1,&buf,1)) == 1)
			write(fd2,&buf,1);
	}
	else
	{	
		printf("read and write hello file error!\n");
		exit(1);
	}

	//create symbolic links

	char* todir21 = "/Users/chiefdondjeu/Dir1/toDir21";
	char* tohello = "/Users/chiefdondjeu/Dir1/toHello";


	if( (symlink(dir21,todir21)) < 0)
		printf("Symbolic link toDir21 creation error!\n");
	
	if( (symlink(hello,tohello)) < 0)
		printf("Symbolic link toHello creation error!\n");

	return 0;
}
