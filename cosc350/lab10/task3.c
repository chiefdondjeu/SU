/*
 	Florent Dondjeu Tschoufack
	Nov 28, 2020
	lab 10
	task3.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#include <pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define N 10
typedef int semaphore;
semaphore mutex = 1;
semaphore empty = 2; //When N invalid argument error
semaphore full = 0;

int buffer[N];
int semid;
union semun arg;
//int count = 0; //index

void display(char ch, char ch2)
{
	printf("%c [ ", ch);
	for(int i = 0; i < N; i++)
		printf("%d ", buffer[i]);
	printf("] %c\n", ch2);
}

int produce_item()
{
	int val = semctl(semid, full, GETVAL, arg);
	//printf("\nitem at %d produced\n", val);
	return 1;
}

void insert_item(int item)
{
	int val = semctl(semid, full, GETVAL, arg);
	if (val < 10) {
		buffer[val] = item;
		//display('P');
	} else printf("BUFFER FULL\n");
}

int remove_item()
{
	int val = semctl(semid, full, GETVAL, arg);
	if (val > 0) {
		int item = buffer[val-1];
		buffer[val-1] = 0;
		//display('C');
		return item;
	}

	printf("BUFFER EMPTY\n");
	return -1;
}

void consume_item(int item)
{
	if (item == -1 || item == 0)
		printf("NO ITEM CONSUMED\n");
	//else printf("item consumed at %d\n\n", count);
}

void up(int val)
{
	struct sembuf sb = {val, 1, 0};
	if (semop(semid, &sb, 1) == -1) {
		perror("semop up error");
		exit(1);
	}
}

void down(int val)
{
	struct sembuf sb = {val, -1, 0};
	if (semop(semid, &sb, 1) == -1) {
		perror("semop down error");
		exit(1);
	}
}

void* producer()
{
	int item;
	while(1) {
		item = produce_item();
		
		down(empty);
		down(mutex);

		insert_item(item);
		display('P', ' ');
		sleep(1); //

		up(mutex);
		up(full);
	}
	pthread_exit(NULL);
}

void* consumer()
{
	int item;
	while(1) {		
		down(full);
		down(mutex);
		
		item = remove_item();
		display(' ', 'C');
		sleep(1); //
		
		up(mutex);
		up(empty);
		
		consume_item(item);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t T[2];
	int data;
	key_t key;
	//union semun arg;

	if ((key = ftok("task3.c", 'J')) == -1) {
		perror("ftok error");
		exit(1);
	}
	//create semaphore set
	if ((semid = semget(key, 3, 0666 | IPC_CREAT)) == -1) {
		perror("semget error");
		exit(1);
	}

	//set semaphore value
	arg.val = 1;
	if (semctl(semid, mutex, SETVAL, arg) == -1) {
		perror("semctl mutex error");
		exit(1);
	}
	arg.val = N;
	if (semctl(semid, empty, SETVAL, arg) == -1) {
		perror("semctl empty error");
		exit(1);
	}
	arg.val = 0;
	if (semctl(semid, full, SETVAL, arg) == -1) {
		perror("semctl full error");
		exit(1);
	}

	for(int i = 0; i < N; i++)
		buffer[i] = 0;

	//create threads
	data = pthread_create(&T[0], NULL, producer, NULL);
	data = pthread_create(&T[1], NULL, consumer, NULL);

	pthread_join(T[0], NULL);
	pthread_join(T[1], NULL);

	//remove semaphore set
	if (semctl(semid, 0, IPC_RMID, arg) == -1) {
		perror("semctl error");
	}

	exit(0);
}
