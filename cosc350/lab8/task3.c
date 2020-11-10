/*
	Florent Dondjeu Tschoufack
	Nov 9, 2020
	lab 8
	task3.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXLINE 256

void error_sys(char* msg)
{
	printf("%s\n", msg);
	exit(1);
}

int main(int argc, char* argv[])
{
	int nr, int1, int2, fd[2], size;
	pid_t pid;
	char sline[MAXLINE], rline[MAXLINE];

	if( (pipe(fd)) < 0)
		error_sys("error; pipe failed!");

	if( (pid = fork()) < 0)
		error_sys("error; fork failed!");

	if(pid > 0) /* Parent Process */
	{
		close(fd[0]);
		write(1, "Enter two integers: ", 20);
		while( (size = read(STDIN_FILENO, sline, MAXLINE)) > 0)
			write(fd[1], sline, size);
	}
	else	/* Child Process */
	{
		close(fd[1]);
		while( (nr = read(fd[0], rline, MAXLINE)) > 0)
		{
			if(sscanf(rline, "%d%d",&int1, &int2) == 2)
			{
				sprintf(rline, "Sum %d\n", int1 + int2);
				nr = strlen(rline);
				if(write(STDOUT_FILENO, rline, nr) != nr)
					error_sys("error; write failed!");
			}
			else
			{
				if(write(STDOUT_FILENO, "Invalid args\n",13) != 13)
					error_sys("error; write failed!");
			}
		}
	}
	
	exit(0);
}