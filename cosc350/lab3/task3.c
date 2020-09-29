//Florent Dondjeu Tschoufack
//Sept 24, 2020
//lab 3
//task3.c

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    int fd[2]; //file descriptors
    char buffer[32]; //buffer size 32 bytes
    int nread;

    //open foo for rw only
    if( (fd[0] = open("foo", O_RDWR)) < 0)
		printf("Open foo file error\n");

    //reset permission for file
    umask(0);

    //open clone2 for rw only, create rwxrwx---
    if( (fd[1] = open("clone2", O_RDWR | O_CREAT, 0770)) < 0)
		printf("Open create clone2 file error\n");

    if(fd[0] > 0 && fd[1] > 0)
    {
        //read foo file
        while( (nread = read(fd[0],buffer,sizeof(buffer))) > 0 )
            write(fd[1],buffer,nread); //write foo to clone2
    }
    else
        printf("Error while reading foo file!");

    close(fd[0]);
    close(fd[1]);

    return 0;
}
