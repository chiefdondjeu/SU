/*
	FLorent Dondjeu Tschoufack
	Nov 2, 2020
	lab 7
	task4.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void response(int sig)
{
	if(sig == 30)
		printf("Hi Honey! Anything wrong?\n");
	if(sig == 31)
		printf("Do you make trouble again?\n");
}

int main()
{
	pid_t pid, pid2;
	
	pid = fork();

	if(pid == 0) /* 1st child process */
	{
		kill(getppid(),SIGUSR1);
		exit(0);
	}
	else
	{
		pid2 = fork();
		if(pid2 == 0) /* 2nd child process */
		{
			kill(getppid(),SIGUSR2);
			exit(0);
		}
		else /* parent process */
		{
			(void) signal(SIGUSR1,response);
			pause();

			(void) signal(SIGUSR2,response);
			pause();
			exit(0);
		}
	}
}