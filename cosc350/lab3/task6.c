//Florent Dondjeu Tschoufack
//Sept 28, 2020
//lab3
//task6.c

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
	int fd[2]; //file descriptors
	char c;
	int offset;

	//open foo for rw only
	if( (fd[0] = open("foo", O_RDWR)) < 0)
		printf("Open foo file error\n");

	//reset permission for file
	umask(0);

	//open foo12 for rw only, create rwxrw----
	if( (fd[1] = open("foorev", O_RDWR | O_CREAT, 0760)) < 0)
		printf("Open create foorev file error\n");

	if(fd[0] > 0 && fd[1] > 0)
	{
		offset = 0;

		//read foo file to figure out offset
		while( (read(fd[0],&c,1)) == 1)
			offset++;
		
		//write to foorev
		while(offset > 0)
		{
			pread(fd[0],&c,1,offset-1);
			write(fd[1],&c,1);
			offset--;
		}
		
	}
	else
		printf("Reading foo file error\n");

	close(fd[0]);
	close(fd[1]);

	return 0;
}