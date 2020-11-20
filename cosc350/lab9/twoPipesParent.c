/*
	Florent Dondjeu Tschoufack
	Nov 19, 2020
	lab 9
	twoPipesParent.c
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int data_processed;
	int file_pipes[2], file_pipes_2[2];
	const char some_data[] = "Hi there, Kiddo";
	char buffer[BUFSIZ + 1];
	pid_t fork_result;

	int wstatus;

	memset(buffer, '\0', sizeof(buffer));

	if(pipe(file_pipes) == 0 && pipe(file_pipes_2) == 0) {
		fork_result = fork();
		if (fork_result == (pid_t)-1) {
			fprintf(stderr, "Fork failure");
			exit(EXIT_FAILURE);
		}
		if (fork_result == 0) {
			close(file_pipes[1]);
			close(file_pipes_2[0]);

			dup2(file_pipes_2[1],STDIN_FILENO);

			sprintf(buffer, "%d", file_pipes[0]);
			(void)execl("twoPipesChild", "twoPipesChild", buffer, &file_pipes_2, (char *)0);
			exit(EXIT_FAILURE);
		}
		else {
			close(file_pipes[0]);
			close(file_pipes_2[1]);

			data_processed = write(file_pipes[1], some_data, strlen(some_data));
			printf("%d - wrote %d bytes\n", getpid(), data_processed);
			close(file_pipes[1]);

			wait(&wstatus);

			data_processed = read(file_pipes_2[0], buffer, BUFSIZ);
			printf("%d - read %d bytes: %s\n", getpid(), data_processed, buffer);
		}
	}
	exit(EXIT_SUCCESS);
}