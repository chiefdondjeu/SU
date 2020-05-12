/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *Lab 2 - Advanced Data Structure and Algorithm Analysis
 *Feb 6, 2019
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>

int partition(int*, int, int);
void quicksort(int*, int, int);

void merge(int*, int [], int, int, int);
void mergesort(int*, int [], int, int);

void swap(int*, int*);
void isSorted(int*, int);

void fillAscending(int *, int);
void filldescending(int*, int);
void fillRandom(int*, int);

void timeSortQuick(void(*sort) (int*, int, int), int* arr, int m, int n);
void timeSortMerge(void(*sort) (int*, int [], int, int), int *arr, int c[], 
									 int m, int n);

int main()
{
	int size;
	std :: cout << "Enter number of elements: ";
	std :: cin >> size;

	int *goodArr, *badArr, *randArr;
	goodArr = new int[size];
	badArr = new int[size];
	randArr = new int[size];

	fillAscending(goodArr, size);
	filldescending(badArr, size);
	fillRandom(randArr, size);

	////////////////////////////////////////////////////QUICK
	std :: cout << "\nQUICK SORT" << std :: endl;
	timeSortQuick(quicksort, goodArr, 0, size-1);
	std :: cout << "\tgoodArr ";
	isSorted(goodArr, size);

	timeSortQuick(quicksort, randArr, 0, size-1);
	std :: cout << "\trandArr ";
	isSorted(randArr, size);

	timeSortQuick(quicksort, badArr, 0, size-1);
	std :: cout << "\t badArr ";
	isSorted(badArr, size);

	filldescending(badArr, size);
	fillRandom(randArr, size);

	/////////////////////////////////////////////////////MERGE
	int temp[size]; //array for mergesort
	std :: cout << "\nMERGE SORT" << std :: endl;
	timeSortMerge(mergesort, goodArr, temp, 0, size-1);
	std :: cout << "\tgoodArr ";
	isSorted(goodArr, size);
	std :: cout << std :: endl;

	timeSortMerge(mergesort, randArr, temp, 0, size-1);
	std :: cout << "\trandArr ";
	isSorted(randArr, size);
	std :: cout << std :: endl;

	timeSortMerge(mergesort, badArr, temp, 0, size-1);
	std :: cout << "\tbadArr ";
	isSorted(badArr, size);
	std :: cout << std :: endl;

	//quicksort(randArr, 0, size-1);
	//mergesort(randArr, temp, 0, size-1);
	//print(randArr, size);
	//isSorted(randArr, size);

	delete [] goodArr;
	delete [] badArr;
	delete [] randArr;

	return 0;
}


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//m first index of array,  n last index of array
int partition(int *arr, int m, int n)
{
	int pivot = arr[n];
	int i = m-1;
	for(int j = m; j <= n-1; j++)
	{
		if(arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	i++;
	swap(&arr[i], &arr[n]);
	return i;
}

void quicksort(int *arr, int m, int n)
{
	int pivot;
	if(m < n)
	{
		pivot = partition(arr, m, n);
		quicksort(arr, m, pivot-1);
		quicksort(arr, pivot+1, n);
	}

}

void merge(int *arr, int c[], int m, int mid, int n)
{
	int i, j, k;
	i = m;
	k = m;
	j = mid+1;

	while(i <= mid && j <= n)
	{
		if(arr[i] < arr[j])
		{
			c[k] = arr[i];
			i++;
		}
		else
		{
			c[k] = arr[j];
			j++;
		}
		k++;
	}
	while(i <= mid)
	{
		c[k] = arr[i];
		k++;
		i++;
	}
	while(j <= n)
	{
		c[k] = arr[j];
		k++;
		j++;
	}
	for(i = m; i < k; i++)
		arr[i] = c[i];

}

void mergesort(int *arr, int c[], int m, int n)
{
	int mid;
	if(m < n)
	{
		mid = (m+n)/2;
		mergesort(arr, c, m, mid);	//merge the left half
		mergesort(arr, c, mid+1, n);	//merge the right half
		merge(arr, c, m, mid, n);
	}
}

void isSorted(int *arr, int n)
{
	for(int i = 0; i < n-1; i++)
	{
		if(arr[i] > arr[i+1])
		{
			std :: cout << "is not sorted!!!" << std :: endl;
			return;
		}
	}
	std :: cout << "is sorted!" << std :: endl;
}

void fillAscending(int *arr, int n)
{
	for(int i = 0; i < n; i++)
	{
		arr[i] = i+1;
	}
}

void filldescending(int *arr, int n)
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
		randnumb = (rand()%1000)+1;
		arr[i] = randnumb;
	}
}

void timeSortQuick(void(*sort) (int*, int, int), int* arr, int m, int n)
{	
	std :: cout << std :: endl;	//formatting

	clock_t t;	//t clock object
	t = clock();	//start timer
	sort(arr, m, n);
		//prints out number of swaps
	t = clock()-t;	//timer end
	std :: cout << "\telapsed time: " << ((float)t)/CLOCKS_PER_SEC 
							<< "s" << std :: endl;
	t = 0;	//timer reset
}

void timeSortMerge(void(*sort) (int*, int [], int, int), int *arr, int c[],
									 int m, int n)
{
	clock_t t2;	//t clock object
	t2 = clock();	//start timer
	sort(arr, c, m, n);
		//prints out number of swaps
	t2 = clock()-t2;	//timer end
	std :: cout << "\telapsed time: " << ((float)t2)/CLOCKS_PER_SEC 
							<< "s" << std :: endl;
	t2 = 0;	//timer reset
}
