#include <stdio.h>


/*	Binary search always works on the sorted list. 
* 	First sort using quick sorting - time complexity O(n^2)
* 	Then search element(10) using binary search - time complexity O(logn)
*/

/*Binary search algorithm*/
int binarySearch(int arr[], int low, int high, int X)
{
	if (low <= high)
	{
		int mid;
		mid = low + (high-low)/2;
		/*if element present at the mid return the index*/
		if (arr[mid] == X)
			return mid;
		
		if (arr[mid] > X)
			return binarySearch(arr, low, mid-1, X);	
		
		return binarySearch(arr, mid+1, high, X);
	}
	return -1;
}

/*Swapping the elements*/
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}	

/*Partitioning of the array and get the pivot element*/
int partition(int arr[], int low, int high)
{
	int pivot, i, j;
	
	pivot = arr[low];
	i = low;
	j = high + 1;
	
	while (i < j)
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

/*Quick sort algorithm*/
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

/*print the array*/
void  printArray(int arr[], int n)
{
	int i;
	for (i = 0;i < n; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}	

/*Program driver*/
int main()
{
	int arr[] = {15, 20, 4, 3, 10, 25, 2, 17, 1, 49};
	int size,x, index;
	size = sizeof(arr)/sizeof(arr[0]);
	printf("Before Sorting array elements: ");
	printArray(arr, size-1);
	printf("Enter the element to search\n");
	scanf("%d", &x);
	/*Sorting using Quick sort*/
	quickSort(arr, 0, size-1);
	printf("After Sorting array elements: ");
	printArray(arr, size-1);
	/*Search the element X using binary search*/
	index = binarySearch(arr, 0, size-1, x);
	(index == -1) ? printf("Element not present in the list\n") : printf("Element is present at index:[%d]\n", index);
	return 0;	
}
