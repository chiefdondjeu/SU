/*
	Florent Dondjeu Tschoufack
	Nov 19, 2020
	lab 9
	pipe1.c
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int READ_END = 0;
const int WRITE_END = 1;

int main()
{
	int data_processed;
	int file_pipes[2];
	const char some_data[] = "123";
	int n = sizeof(some_data);
	char* buffer = (char*)calloc(n,sizeof(char));

	memset(buffer, '\0', n);

	if(pipe(file_pipes) == 0) {
		data_processed = write(file_pipes[WRITE_END], some_data, strlen(some_data));
		printf("Wrote %d bytes\n", data_processed);
		data_processed = read(file_pipes[READ_END], buffer, n);
		printf("Read %d bytes: %s\n", data_processed, buffer);
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	free(buffer);
	exit(EXIT_FAILURE);
}

/*
	D. file_pipes[0] is waiting for information to read.
 */