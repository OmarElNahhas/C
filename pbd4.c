/*
Given an array of integers, find the first missing positive integer in linear time and constant space. In other words,
find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.

pseudo:
organiseer de array

negeer alle negatieve getallen

a[0] is kleinste getal, a[0] + 1 == a[1]
false, return a[0] + 1
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
    return arr;
}

void selection(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    {
        if(arr[i] >= 0)
        {
            if(arr[i] + 1 != arr[i+1])
            {
                printf("%i", arr[i]+1);
                return 0;
            }
        }
    }
}

// Driver program to test above functions
int main()
{
    int arr[] = {-3, -5, -8, -9, -1, 13, 14, 15, 17, 18};
    int n = sizeof(arr)/sizeof(arr[0]);
    int new_arr = selectionSort(arr, n);
    selection(new_arr, n);
}
