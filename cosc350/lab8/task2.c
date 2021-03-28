/*
	Florent Dondjeu Tschoufack
	Nov 8, 2020
	lab 8
	task2.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_SCORES 9
int* scores;

//Thread #1: get test scores from keyboard up 
//to 20 and save into the array.
void* thrd_f1();

//Thread #2: Calculate an average score and 
//Medium value and display.
void* thrd_f2();

//Thread #3: get the minimum and the maximum 
//score and display.
void* thrd_f3();

//Thread #4: clear buffer and set to 0 and 
//display after Thread #2, Thread #3 finishes its job.
void* thrd_f4();

//swap two variables
void swap(int*,int*);

//bubblesort array in ascending order
void sort();

//print content of array
void display();


int main()
{
	pthread_t threads[4];
    scores = malloc(NUM_SCORES*sizeof(int));
	int rc;

	if( (rc =pthread_create(&threads[0], NULL, thrd_f1, NULL)) != 0)
	{
		printf("Error; return code from pthread_create() is %d", rc);
		exit(1);
	}
	
	pthread_join(threads[0],NULL);	//wait

	if( (rc = pthread_create(&threads[1], NULL, thrd_f2, NULL)) != 0)
	{
		printf("Error; return code from pthread_create() is %d", rc);
		exit(1);
	}
	if( (rc = pthread_create(&threads[2], NULL, thrd_f3, NULL)) != 0)
	{
		printf("Error; return code from pthread_create() is %d", rc);
		exit(1);
	}

	pthread_join(threads[1],NULL);	//wait
	pthread_join(threads[2],NULL);	//wait

	if( (rc = pthread_create(&threads[3], NULL, thrd_f4, NULL)) != 0)
	{
		printf("Error; return code from pthread_create() is %d", rc);
		exit(1);
	}	

	pthread_join(threads[3],NULL);	//wait

    free(scores);
	pthread_exit(NULL);
	exit(0);
}

/* Thread 1 */
void* thrd_f1()
{
	printf("Thread 1:\n");
	int input, i;
	for(i = 0; i < NUM_SCORES; i++)
	{
		printf("\tEnter score %d: ", i+1);
		scanf("%d", &input);
		scores[i] = input;
	}

	sort();	//sort array
	display();
	pthread_exit(NULL);
}

/* Thread 2 */
void* thrd_f2()
{
	int median, mean;
	if(NUM_SCORES%2 == 0)
	{
		int index = NUM_SCORES/2;
		median = (scores[index-1] + scores[index])/2;
	}
	else
	{
		median = scores[NUM_SCORES/2];
	}

	int sum = 0;
	for(int i = 0; i < NUM_SCORES; i++)
	{
		sum += scores[i];
	}
	mean = sum/NUM_SCORES;

	printf("Thread 2:\n\tmean %d\n\tmedian %d\n",mean, median);
	pthread_exit(NULL);
}

/* Thread 3 */
void* thrd_f3()
{
	int min = scores[0];
	int max = scores[0];

	for(int i = 1; i < NUM_SCORES; i++)
	{
		if(min > scores[i])
			min = scores[i];
		if(max < scores[i])
			max = scores[i];
	}

	printf("Thread 3:\n\tminimun %d\n\tmaximum %d\n", min, max);
	pthread_exit(NULL);
}

/* Thread 4 */
void* thrd_f4()
{
    fflush(stdout);
	printf("Thread 4:\n");

	for(int i = 0; i < NUM_SCORES; i++)
		scores[i] = 0;
	display();
	
	pthread_exit(NULL);
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort()
{
	int SWAP, i;

	do
	{
		SWAP = 0;
		for(i = 0; i < NUM_SCORES-1; i++)
		{
			if(scores[i] > scores[i+1])
			{
				SWAP = 1;
				swap(&scores[i],&scores[i+1]);
			}
		}
	}while(SWAP == 1);
}

void display()
{
	printf("\t[ ");
	for(int i = 0; i < NUM_SCORES; i++)
		printf("%d ", scores[i]);
	printf("]\n");
}