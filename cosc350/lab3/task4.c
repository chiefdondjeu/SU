//Florent Dondjeu Tschoufack
//Sept 24, 2020
//lab3
//task4.c

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    int fd[3]; //file descriptors
    char c;
    int nr;
    
    //open foo and foo1 for rw only
    fd[0] = open("foo", O_RDWR);
    fd[1] = open("foo1", O_RDWR);

    //reset permission for file
    umask(0);

    //open foo12 for rw only, create rwxrw----
    fd[2] = open("foo12", O_RDWR | O_CREAT, 0760);

    if(fd[0] != -1 && fd[1] != -1)
    {
        //start at beginninf of foo12
        lseek(fd[2],0,SEEK_SET);
        
        //read foo file and write to foo12
        while((nr = read(fd[0],&c,1)) > 0)
            write(fd[2],&c,nr);

        //start at end of foo12
        lseek(fd[2],1,SEEK_END);

        //read foo1 and write to foo12
        while((nr = read(fd[1],&c,1)) > 0)
            write(fd[2],&c,nr);
    }
    else
        printf("Error while reading foo and foo1 files!");

    for(int i = 0; i < sizeof(fd); i++)
        close(fd[i]);

    return 0;
}
