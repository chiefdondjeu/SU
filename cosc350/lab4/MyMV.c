//Florent Dondjeu Tschoufack
//Oct 8, 2020
//lab4
//task4.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("Need to pass in two arguments!\n");
		exit(1);
	}

	//check if file exist
	if( (access(argv[1],F_OK)) == -1)
	{
		printf("%s does not exist!\n",argv[1]);
		exit(2);
	}

	//check if a directory
	struct stat buf;
	stat(argv[2], &buf);

	if(S_ISDIR(buf.st_mode)) //if a directory
	{
		char newpath[180];
		//combine argv[1] and argv[2] to make full path
		sprintf(newpath,"%s/%s",argv[2],argv[1]);

		link(argv[1],newpath);
		unlink(argv[1]);
	}
	else //if not a directory
	{
		link(argv[1],argv[2]);
		unlink(argv[1]);
	}

	return 0;
}