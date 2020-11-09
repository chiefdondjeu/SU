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

int main()
{
	sigset_t setI, setQ, set;
	
	sigemptyset(&setI);
	sigemptyset(&setQ);

	sigaddset(&setI, SIGINT);
	sigaddset(&setQ, SIGQUIT);

	sigprocmask(SIG_BLOCK, &setI, &set);
	sigprocmask(SIG_BLOCK, &setQ, &set);
	//signals are blocked

	for(int i = 1; i <= 5; i++)
	{
		printf("%d\n", i);
		sleep(1);
	}

	sigprocmask(SIG_UNBLOCK, &setQ, &set);
	//SIGQUIT unblocked

	for(int i = 1; i <= 5; i++)
	{
		printf("%d\n", i);
		sleep(1);
	}

	exit(0);
}
