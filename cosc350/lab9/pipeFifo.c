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

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_NAME "/tmp/task4_fifo"

int main()
{
	if( (access(FIFO_NAME,F_OK)) == -1) {
		printf("%s does not exit\n", FIFO_NAME);
		exit(EXIT_FAILURE);
	}

	int fildes, data_processed;
	const char some_data[] = "123";
	int n = sizeof(some_data);
	char* buffer = (char*)calloc(n,sizeof(char));

	if( (fildes = open(FIFO_NAME,O_RDWR)) != -1) {
		data_processed = write(fildes,some_data,strlen(some_data));
		printf("Wrote %d bytes\n", data_processed);
		data_processed = read(fildes,buffer,n);
		printf("Read %d bytes: %s\n", data_processed, buffer);
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	free(buffer);
	exit(EXIT_FAILURE);
}

/*
	mkfifo /tmp/task4_fifo
	chmod a+w /tmp/task4_fifo
	ls -lF /tmp/task4_fifo
 */