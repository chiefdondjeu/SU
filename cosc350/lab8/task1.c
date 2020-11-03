/*
	Florent Dondjeu Tschoufack
	Nov 3, 2020
	lab 8
	task1.c
 */

/*
	Compile:
	gcc -c source.c
	gcc -pthread -o source source.o
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

//convert string to int function
int convertToInt(char *str, int n);

//summation function
void* sumUp(void *val);

//factorial function
void* factorial(void *val);


int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Need to pass in one argument\n");
		exit(1);
	}

	int size = strlen(argv[1]);
	int n = convertToInt(argv[1],size);

	if(n == -1)
	{
		printf("Integer needs to be positive\n");
		exit(1);
	}

	pthread_t threads[2];
	int t1, t2;
	
	/* 1st thread */
	t1 = pthread_create(&threads[0], NULL, sumUp, (void *)n);
	if(t1 != 0)
	{
		printf("Error; return code from pthread_create() is 0\n");
		exit(1);
	}

	/* 2nd thread */
	t2 = pthread_create(&threads[1], NULL, factorial, (void *)n);
	if(t2 != 0)
	{
		printf("Error; return code from pthread_create() is 1\n");
		exit(1);
	}

	pthread_exit(NULL);
	exit(0);
}

int convertToInt(char *str, int n)
{
	if(str[0] == '-')
		return -1;

	int numb = 0;
	for (int i = 0; i < n; i++)
		numb = numb * 10 + str[i] - '0';

	return numb;
}

void* sumUp(void *val)
{
	int n = (int)val;
	int i = 1 , sum;

	while(i <= n)
	{
		sum += i;
		i++;
	}

	printf("%d sum = %d\n",n ,sum);
	pthread_exit(NULL);
}

void* factorial(void *val)
{
	int n = (int)val;
	int i = 1, fact = 1;

	while(i <= n)
	{
		fact *= i;
		i++;
	}

	printf("%d fact = %d\n", n, fact);
	pthread_exit(NULL);
}
