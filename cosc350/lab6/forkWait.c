//Florent Dondjeu Tschoufack
//Oct 26 2020
//lab 6
//forkWait.c

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int convertToInt(char *str, int n)
{
	int numb = 0;
	for (int i = 0; i < n; i++)
		numb = numb * 10 + str[i] - '0';

	return numb;
}

int main(int argc, char *argv[])
{
	if(argc != 5)
	{
		printf("Need to pass in 4 cmd-line arguments:\n");
		printf("\tNc - number of iterations for child process\n");
		printf("\tNp - number of iterations for parent process\n");
		printf("\tTc - sleep time for child process\n");
		printf("\tTp - sleep time for parent process\n");
		exit(1);
	}

	int nc = convertToInt(argv[1], strlen(argv[1]));
	int np = convertToInt(argv[2], strlen(argv[2]));
	int tc = convertToInt(argv[3], strlen(argv[3]));
	int tp = convertToInt(argv[4], strlen(argv[4]));

	pid_t pid;
	char *message;
	int n, sleep_time, exit_code;

	printf("fork program starting\n");
	pid = fork();
	switch (pid)
	{
		case -1:
			perror("fork failed");
			exit(1);
		case 0:
			message = "This is the child";
			n = nc;
			sleep_time = tc;
			exit_code = 37;
			break;
		default:
			message = "This is the parent";
			n = np;
			sleep_time = tp;
			exit_code = 0;
			break;
	}

	for(; n > 0; n--)
	{
		puts(message);
		sleep(sleep_time);
	}

	if(pid != 0)
	{
		int stat_val;
		pid_t child_pid;
		child_pid = wait(&stat_val);
		printf("Child has finished: PID = % d\n", child_pid);
		if(WIFEXITED(stat_val))
			printf("Child exited with code % d\n", WEXITSTATUS(stat_val));
		else
			printf("Child terminated abnormally\n");
	}
	
	exit(exit_code);
}
