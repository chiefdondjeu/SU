/*
 	Florent Dondjeu Tschoufack
	Nov 28, 2020
	lab 10
	task2.c
*/

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#define N 10
int count = 0;
int* buffer;

pthread_t T[2];

void display(char ch)
{
	printf("%c [ ", ch);
	for(int i = 0; i < N; i++)
		printf("%d ", buffer[i]);
	printf("]\n");
}

void end(int sig)
{
	pthread_cancel(T[0]);
	pthread_cancel(T[1]);
	printf("\nThreads terminated\n");
}

int produce_item()
{
	int item = 1;
	printf("\nitem at %d produced\n", count);
	return item;
}

void insert_item(int item)
{
	if (count < 10) {
		buffer[count] = item;
		count++;
		display('P');
	} else printf("BUFFER FULL\n");
}

int remove_item()
{
	if (count > 0) {
		int item = buffer[count-1];
		buffer[count-1] = 0;
		count--;
		display('C');
		return item;
	}

	printf("BUFFER EMPTY\n");
	return -1;
}

void consume_item(int item)
{
	if (item == -1 || item == 0)
		printf("NO ITEM CONSUMED\n");
	else printf("item consumed at %d\n\n", count);
}

void* producer()
{
	int item;
	while(1) {
		item = produce_item();
		if (count == N) {
			printf("producer sleep...\n\n");
			sleep(3);
			printf("Producer wake...\n\n");
		}
		insert_item(item);
	}
	pthread_exit(NULL);
}

void* consumer()
{
	int item;
	while(1) {
		if (count == 0) {
			printf("consumer sleep...\n\n");
			sleep(3);
			printf("consumer wake...\n\n");
		}
		item = remove_item();
		consume_item(item);
	}
	pthread_exit(NULL);
}

int main()
{
	//pthread_t T[2];
	int data;

	buffer = malloc(N*sizeof(int));
	for(int i = 0; i <= N; i++) buffer[i] = 0;
	(void) signal(SIGQUIT,end); // ^\ to end program

	data = pthread_create(&T[0], NULL, producer, NULL);
	data = pthread_create(&T[1], NULL, consumer, NULL);

	pthread_join(T[0], NULL);
	pthread_join(T[1], NULL);

	free(buffer);
	printf("program exit\n\n");

	exit(0);
}
