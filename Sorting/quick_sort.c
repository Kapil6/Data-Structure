#include <stdio.h>

/*This function swaps the element*/
void swap(int *a, int *b)
{
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}

/*This function returns the pivot position it means this position has its expected element*/
int partition(int arr[], int low, int high)
{
	int pivot, i, j;
	pivot = arr[low];
	i = low;
	j = high+1;
	
	if (i < j)
	{
		/*increament the i index untill pivot is greater and equal than the i indexed element*/
		do
		{
			i++;
		}while(arr[i] <= pivot);

		/*decreament the j index untill pivot is less than the j indexed element*/
		do 
		{
			j--;
		}while(arr[j] > pivot);
	
		/*swap the element i and j*/	
		if (i < j)
			swap(&arr[i], &arr[j]);	
	}
	/*swap the element with low*/
	swap(&arr[low], &arr[j]);
	return j;
}

/*This is the quick sort algorithm*/
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi;
		pi = partition(arr, low, high);// Get the pivot position
		quickSort(arr, low, pi);
		quickSort(arr, pi+1, high);
	}
}

/*This function print the array elements*/
void printArray(int arr[], int n)
{
	int i;
	printf("Elements are -> ");
	for (i = 0; i < n; i++)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = {10,16,8,12,15,6,3,9,5};
	int size;
	size = sizeof(arr)/sizeof(arr[0]);
	printArray(arr,size);
	quickSort(arr, 0, size-1);
	printf("\t\tAfter sort\n");
	printArray(arr,size);
	return 0;
}
