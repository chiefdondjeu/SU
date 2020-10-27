//Florent Dondjeu Tschoufack
//Oct 26, 2020
//lab 6
//task5.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
	if(argc !=2 )
	{
		printf("Need to pass in file name as argument.\n");
		exit(1);
	}

	int fd;
	if( (fd=open(argv[1],O_RDONLY)) < 0)
	{
		printf("Open input file error!\n");
		exit(1);
	}

	int fdp,fdc;	//fdp - file descriptor for parent 
					//fdc - file descriptor for child
	pid_t pid;
	char buf;
	int nr;

	pid = fork();

	switch(pid)
	{
		case -1:
			perror("fork failed");
			exit(1);

		case 0: //child
			umask(0);
			if( (fdc=open("child.txt", O_RDWR | O_CREAT, 0600)) < 0)
			{
				printf("Open|create child.txt error!\n");
				break;
			}

			lseek(fd, 0, SEEK_SET);
			while( (nr = read(fd,&buf,1)) > 0)
			{
				if(buf > '9') //excluding digits
					write(fdc,&buf,nr);
			}
			close(fdc);
			break;

		default: //parent
			umask(0);
			if( (fdp=open("parent.txt", O_RDWR | O_CREAT, 0600)) < 0)
			{
				printf("Open|create parent.txt error!\n");
				break;
			}

			lseek(fd, 0, SEEK_SET);
			while( (nr = read(fd,&buf,1)) > 0)
			{
				if(buf >= '0' && buf <= '9') //digits only
					write(fdp,&buf,nr);
			}
			close(fdp);
			break;
	}

	close(fd);

	return 0;
}
