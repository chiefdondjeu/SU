//Florent Dondjeu Tschoufack
//Nov 1 2020
//lab7
//ctrlc2.c

/*
	D. I pressed "^Z" to pause the program, then I typed "ps" so I could get the
	PID of the executable, then I issued a kill command "Kill -Term PID", which
	ended the program.
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ouch(int sig)
{
	printf("OUCH! - I got signal %d\n", sig);
}

int main()
{
	struct sigaction act;
	act.sa_handler = ouch;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESETHAND;
	sigaction(SIGINT, &act, 0);

	while(1)
	{
		printf("Hello World!\n");
		sleep(1);
	}
}