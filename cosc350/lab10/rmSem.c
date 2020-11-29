/* Program removes semaphore set created by task3.c */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
	key_t key;
	int semid;
	union semun arg;

	if ((key = ftok("task3.c", 'J')) == -1) {
		perror("ftok error");
		exit(1);
	}
	//get the semaphore
	if ((semid = semget(key, 3, 0)) == -1) {
		perror("semget error");
		exit(1);
	}

	//remove semaphore
	if (semctl(semid, 0, IPC_RMID, arg) == -1) {
		perror("semctl error");
	}

	return 0;
}
