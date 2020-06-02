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

void bubble_sort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < (n-i-1); j++)
		{
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
}

int main()
{
	int arr[] = {64, 25, 12, 22, 11};
	int size = sizeof(arr)/sizeof(int);
	print_array(arr, size);
	bubble_sort(arr, size);
	printf("\t\tAfter sort\n");
	print_array(arr, size);	
	return 0;
}
