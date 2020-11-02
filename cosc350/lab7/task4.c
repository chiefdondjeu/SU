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
#include <sys/wait.h>

void response(int sig)
{
	if(sig == 30)
		printf("Hi Honey! Anything wrong?\n");
	if(sig == 31)
		printf("Do you make trouble again?\n");
}

int main()
{
	struct sigaction act;
	act.sa_handler = response;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	pid_t pid, pid2;
	int status, end;
	
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
			end = waitpid(pid,&status,WUNTRACED);	//waits for other child to end
			kill(getppid(),SIGUSR2);
			exit(0);
		}
		else /* parent process */
		{
			sigaction(SIGUSR1, &act, 0);
			pause();

			sigaction(SIGUSR2, &act, 0);
			pause();
			exit(0);
		}
	}
}