//Florent Dondjeu Tschoufack
//Sept 22, 2020
//lab3
//task2.c

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
	int fd[2];	//file descriptors

	//open foo for rw only
    if( (fd[0] = open("foo",O_RDWR)) < 0)
        printf("Open foo file error\n");

	//reset permision of file
    umask(0);
	
	//open clone1 for rw only, create rw-rw-rw
    if( (fd[1] = open("clone1", O_RDWR | O_CREAT, 0666)) < 0)
        printf("Open create clone1 file error\n");

	char c;
	int nread;

	if (fd[0] > 0 && fd[1] > 0)
	{
		//read foo file
		while( (nread = read(fd[0],&c,1)) > 0)
			write(fd[1],&c,nread);	//write foo to clone1
	}
	else
		printf("Reading foo file error!\n");

    close(fd[0]);
    close(fd[1]);

	return 0;
}
