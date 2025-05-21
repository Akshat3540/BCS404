// Design and implement C/C++ program to sort a given set of n integer elements using
// selection sort method and compute its time complexity. Run the program for varied values of
// n > 5000 and record the time taken to sort. Plot a graph of the time taken versus n. The
// elements can be read from a file or can be generated using the random number generator.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int n, i;
    clock_t start, end;
    double cpu_time_used;
    int sizes[] = {5000, 10000, 15000, 20000, 25000};
    for (i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++)
    {
        n = sizes[i];
        int arr[n];
        srand(time(NULL));
        for (int j = 0; j < n; j++)
        {
            arr[j] = rand();
        }
        start = clock();
        selectionSort(arr, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nTime taken to sort array of size %d: %f seconds\n", n, cpu_time_used);
    }
    return 0;
}

// Output:
// Time taken to sort array of size 5000: 0.046000 seconds 
// Time taken to sort array of size 10000: 0.141000 seconds 
// Time taken to sort array of size 15000: 0.328000 seconds 
// Time taken to sort array of size 20000: 0.547000 seconds 
// Time taken to sort array of size 25000: 0.890000 seconds