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
	sigset_t mask2, mask3, orig_mask;
	
	sigemptyset(&mask2);
	sigemptyset(&mask3);

	sigaddset(&mask2, 2);
	sigaddset(&mask3, 3);

	sigprocmask(SIG_BLOCK, &mask2, &orig_mask);
	sigprocmask(SIG_BLOCK, &mask3, &orig_mask);
	//signals are blocked

	for(int i = 1; i <= 5; i++)
	{
		printf("%d\n", i);
		sleep(1);
	}

	sigprocmask(SIG_UNBLOCK, &mask3, &orig_mask);
	//SIGQUIT unblocked

	for(int i = 1; i <= 5; i++)
	{
		printf("%d\n", i);
		sleep(1);
	}

	exit(0);
}
