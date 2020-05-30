#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}

int partition(int arr[], int low, int high)
{
	int pivot, i, j;
	pivot = arr[low];
	i = low;
	j = high+1;
	
	if (i < j)
	{
		do
		{
			i++;
		}while(arr[i] <= pivot);

		do 
		{
			j--;
		}while(arr[j] > pivot);

		if (i < j)
			swap(&arr[i], &arr[j]);	
	}
	
	swap(&arr[low], &arr[j]);
	return j;
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi;
		pi = partition(arr, low, high);
		quickSort(arr, low, pi);
		quickSort(arr, pi+1, high);
	}
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = {10,16,8,12,15,6,3,9,5};
	int size;
	size = sizeof(arr)/sizeof(arr[0]);
	printf("Size of array:[%d]\n", size);
	quickSort(arr, 0, size-1);
	printArray(arr,size-1);
	return 0;
}
