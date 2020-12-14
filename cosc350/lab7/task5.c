/*
    Florent Dondjeu Tschoufack
    Nov 2, 2020
    lab 7
    task5.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void hd1(int sig)
{
	signal(SIGQUIT,SIG_DFL);
}

int main()
{
	sigset_t setI, setQ;
	
	sigemptyset(&setI);
	sigemptyset(&setQ);

	sigaddset(&setI, SIGINT);
	sigaddset(&setQ, SIGQUIT);

	sigprocmask(SIG_BLOCK, &setI, NULL);
	sigprocmask(SIG_BLOCK, &setQ, NULL);
	//signals are blocked

	for(int i = 1; i <= 5; i++)
	{
		printf("%d\n", i);
		sleep(1);
	}

  	signal(SIGQUIT, hd1);
	sigprocmask(SIG_UNBLOCK, &setQ, NULL);
	//SIGQUIT unblocked

	sigemptyset(&setQ);
	//clear signal set

	for(int i = 1; i <= 5; i++)
	{
		printf("%d\n", i);
		sleep(1);
	}

	exit(0);
}
