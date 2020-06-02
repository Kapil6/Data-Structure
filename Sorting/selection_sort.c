#include <stdio.h>

void print_array(int arr[], int n)
{
	int i;
	printf("Elements are ->  ");
	for (i = 0; i < n; i++)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void selection_sort(int arr[], int n)
{
	int i, j, min_index;
	for (i = 0; i < n-1; i++)
	{
		min_index = i;
		for (j = i+1; j < n; j++)
		{
			if (arr[j] < arr[min_index])
				min_index = j; // Update the min_index
		}
/*Swap the found minimum element in the array*/
		swap(&arr[min_index], &arr[i]);
	}
}

int main()
{
	int arr[] = {64, 25, 12, 22, 11};
	int size = sizeof(arr)/sizeof(int);
	print_array(arr, size);
	selection_sort(arr, size);
	printf("\t\tAfter sort\n");
	print_array(arr, size);	
	return 0;
}
