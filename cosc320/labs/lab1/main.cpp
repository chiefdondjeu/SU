/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Lab1 - Advanced Data Structures and Algorithm Analysis
 */

#include <iostream>
#include <time.h>	//for timer b/c chrono did not work :(
#include <ctime>	//used for random number
#include <cstdlib>	//for random number

void fillAscending(int *, int); //ascending order 12345
void fillDescending(int *, int); //descending order 54321
void fillRandom(int*, int);	//random order 45213

void swap(int *a, int *b);
double bubbleSort(int *, int);
double insertionSort(int *, int);
double selectionSort(int *, int);

void isSorted(int *, int);	//check if array is sorted
void timeSort(double(*sort) (int*, int), int* arr, int n);
	//function ptr

int main()
{
	int size;
	std :: cout << "Enter number of elements: ";
	std :: cin >> size;	//array size: 100~1,000,000
	std :: cout << std :: endl;	//formatting

	int *goodArr, *badArr, *randArr;
	goodArr = new int[size];	//best case
	badArr = new int[size];	//worst case
	randArr = new int[size];	//avg case

	fillAscending(goodArr, size);
	fillDescending(badArr, size);
	fillRandom(randArr, size);

	///////////////////////////////////////////////BUBBLE SORT
	std :: cout << "BUBBLE SORT";
	timeSort(bubbleSort, goodArr, size);
	std :: cout << "\tgoodArr ";
	isSorted(goodArr, size);

	timeSort(bubbleSort, randArr, size);
	std :: cout << "\trandArr ";
	isSorted(randArr, size);

	timeSort(insertionSort, badArr, size);
	std :: cout << "\tbadArr ";
	isSorted(badArr, size);
	std :: cout << std :: endl;

	//reset arrays
	fillDescending(badArr,size);
	fillRandom(randArr, size);

	///////////////////////////////////////////////INSERTION SORT
	std :: cout << "INSERTION SORT";
	timeSort(insertionSort, goodArr, size);
	std :: cout << "\tgoodArr ";
	isSorted(goodArr, size);

	timeSort(insertionSort, randArr, size);
	std :: cout << "\trandArr ";
	isSorted(randArr, size);

	timeSort(insertionSort, badArr, size);
	std :: cout << "\tbadArr ";
	isSorted(badArr, size);
	std :: cout << std :: endl;

	//reset arrays
	fillDescending(badArr, size);
	fillRandom(randArr, size);

	///////////////////////////////////////////////SELECTION SORT
	std :: cout << "SELECTION SORT";
	timeSort(selectionSort, goodArr, size);
	std :: cout << "\tgoodArr ";
	isSorted(goodArr, size);

	timeSort(selectionSort, randArr, size);
	std :: cout << "\trandArr ";
	isSorted(randArr, size);

	timeSort(selectionSort, badArr, size);
	std :: cout << "\tbadArr ";
	isSorted(badArr, size);

	delete [] goodArr;
	goodArr = NULL;

	delete [] badArr;
	badArr = NULL;

	delete [] randArr;
	randArr = NULL;

	return 0;
}


void print(int* arr, int n)
{
	for(int i = 0; i < n; i++)
		std :: cout << arr[i] << " ";
	std :: cout << std :: endl;
}

void fillAscending(int *arr, int n)
{
	for(int i = 0; i < n; i++)
	{
		arr[i] = i+1;
	}
}

void fillDescending(int *arr, int n)
{
	int j = n;
	for(int i = 0; i < n; i++)
	{
		arr[i] = j;
		j--;
	}
}

void fillRandom(int *arr, int n)
{
	srand(time(0));
	//allows us to get a different set of random numbers
	//each time the program is ran
	//**not everytime the function is called**

	int i, randnumb;
	for(i = 0; i < n; i++)
	{
		randnumb = (rand()%100)+1;
		arr[i] = randnumb;
	}
}


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

double bubbleSort(int *arr, int n)
{
	double count = 0;	//number of swaps

	bool SWAP;
	int i;
	do
	{
		SWAP = false;
		for(i = 0; i < n-1; i++)
		{
			if(arr[i] > arr[i+1])
			{
				SWAP = true;
				count++;
				swap(&arr[i], &arr[i+1]);
			}
		}

	}while(SWAP);	//true

	return count;
}

double insertionSort(int *arr, int n)
{
	double count = 0;	//number of swaps

	int i, j, temp;
	for(i = 1; i < n; i++)
	{
		temp = arr[i];
		j = i-1;
		while(j >= 0 && arr[j] > temp)
		{
			arr[j+1] = arr[j];
			j = j-1;
			count++;
		}
		arr[j+1] = temp;
	}

	return count;
}

double selectionSort(int *arr, int n)
{
	double count = 0;	//number of swaps

	int i, j, k;
	for(i = 0; i < n-1; i++)
	{
		k = i;
		for(j = i+1; j < n; j++)
			if(arr[j] < arr[k])
			{
				k = j;
				count++;
			}
			swap(&arr[k], &arr[i]);
	}

	return count;
}


void isSorted(int *arr, int n)
{
	int i;
	for(i = 1; i < n; i++)
	{
		if(arr[i-1] > arr[i])
		{
			std :: cout << "is not sorted!!!" << std :: endl;
			return;
		}
	}
	std :: cout << "is sorted!" << std :: endl;
}

void timeSort(double(*sort) (int*, int), int* arr, int n)
{	
	std :: cout << std :: endl;	//formatting

	clock_t t;	//t clock object
	t = clock();	//start timer
	std :: cout << "\t# of swaps: " << sort(arr, n) << std :: endl;
		//prints out number of swaps
	t = clock()-t;	//timer end
	std :: cout << "\telapsed time: " << ((float)t)/CLOCKS_PER_SEC 
							<< "s" << std :: endl;
	t = 0;	//timer reset
}
