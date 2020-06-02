#include <stdio.h>

void print_array(int arr[], int n)
{
	int i;
	printf("Elements are -> ");
	for (i = 0; i < n; i++)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

void heapify(int arr[], int n, int i)
{
/*2. Populate the root(largest), left(2*root_index + 1) and right child (2*root_index + 2)*/
	int largest, l, r;
	largest = i;
	l = 2*i + 1;
	r = 2*i + 2;

/*3. Check if root is less than the left or right child then update the index of root and also
*	check if left child is exist in the array or not	
*/
	if (l < n && arr[largest] < arr[l])	
		largest = l;
	
	if (r < n && arr[largest] < arr[r])
		largest = r;

/*4. if index of root is changes then swap the elements and also call the heapify with the updated root index*/
	if (largest != i)
	{
		// Swap the arr[i] with the arr[largest]
		arr[largest] += arr[i];
		arr[i] = arr[largest] - arr[i];
		arr[largest] = arr[largest] - arr[i];
		heapify(arr, n, largest);
	}
}

void heap_sort(int arr[], int n)
{
	int i;
/*1. Build heap by using formula i=n/2-1*/
	for (i = n/2-1; i >= 0; i--)
		heapify(arr, n, i);

/*5. Extract the one by one element from the heap and put that element to end in the array
* call the heapify with the reduced size
*/
	for (i = n-1; i > 0; i--)	
	{
		// Swap the arr[i] with the arr[0]
		arr[i] += arr[0];
		arr[0] = arr[i] - arr[0];
		arr[i] = arr[i] - arr[0];	
		
		heapify(arr, i, 0);			
	}
}

int main()
{
	int arr[] = {45, 23, 10, 54, 9};
	int size;
	size = sizeof(arr)/sizeof(int);
	print_array(arr, size);
	heap_sort(arr, size);
	printf("\t\tAfter sort\n");
	print_array(arr, size);
	return 0;
}
