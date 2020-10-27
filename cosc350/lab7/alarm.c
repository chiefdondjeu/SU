//Florent Dondjeu Tschoufack
//Oct 27 2020
//lab7
//alarm.c

#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int alarm_fired = 0;

void ding(int sig)
{
	alarm_fired = 1;
}

int main()
{
	pid_t pid;
	printf("alarm application starting\n");
	pid = fork();

	struct sigaction act;
	act.sa_handler = ding;
	sigemptyset(&act.sa_mask); //clear signal set
	act.sa_flags = 0;

	switch(pid)
	{
		case -1:
			/* Failure */
			perror("fork failed");
			exit(1);
		case 0:
			/* child */
			sleep(5);
			kill(getppid(), SIGALRM);
			exit(0);
	}

	/* if we get here we are the parent process */
	printf("waiting for alarm to go off\n");
	//(void) signal(SIGALRM, ding);
	
	if(sigaction(SIGALRM, &act, 0))
	{
		perror("sigaction");
		return 1;
	}
	
	pause();
	if (alarm_fired)
		printf("Ding!\n");
	
	printf("done\n");
	exit(0);
}