/* C implementation QuickSort */
#include<stdio.h>
#include<omp.h>
#include<math.h>
#include <stdlib.h>
#include<iostream>

#define ARRAY_MAX_SIZE 500000

using namespace std;
int arr[ARRAY_MAX_SIZE];


void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element
	for (int j = low; j <= high- 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

        //As I capture each task,  its going to look at the value of  arr , low, pi at that point and
        // it will create a private values for that variables and its going to initialize it the current values.
        //So each task will be execute its own copy.





		#pragma omp task firstprivate(arr,low,pi)
		{
			quickSort(arr,low, pi - 1);

		}

		//#pragma omp task firstprivate(arr, high,pi)
		{
			quickSort(arr, pi + 1, high);

		}


	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int counter=0;
	int i;
	for (i=0; i < size; i++)
    {
       printf("%d ", arr[i]);
       counter++;
       if(counter==20)
       {
           cout << endl;
           counter=0;
       }
    }



}

// Driver program to test above functions
int main()
{



	int n = 500000;
	for( int i = 0; i < n; i++ )
    {
       arr[i] = rand() % 1000 +1;
      // printf("%d\n", arr[i]);

    }



double start_time = omp_get_wtime();
omp_set_num_threads(8);
#pragma omp parallel
 {

    int id = omp_get_thread_num();
    int nthrds = omp_get_num_threads();
//printf("Thread is %d\n",id);
#pragma omp single nowait


	 quickSort(arr, 0, n-1);
}
    double time = omp_get_wtime() - start_time;
    cout << n << " " << "Random Numbers Quick Sort" << endl;
    cout << "Range :" << " 1 - 1000" << endl;
    cout << endl;
    cout<<"QS TIME = " << time<<endl;
    return 0;
}
