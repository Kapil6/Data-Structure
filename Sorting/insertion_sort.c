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

void insertion_sort(int arr[], int n)
{
	int i, j, key;
/*1. Divide the Array into two parts. sorted array and unsorted array below is the loop for unsorted array*/	
	for (i = 1; i < n; i++)
	{
/*2. Store the first element of the unsorted array into key*/
		key = arr[i];

/*3. initialise the j with the last index of sorted array for example i is 
* for unsorted array so before this i index i.e. i-1 is the last index of sorted array 
*/
		j = i-1;

/*4. Run the loop untill the key is place where it should be */				
		while (j >= 0 && key < arr[j])
		{
			arr[j+1] = arr[j];
			j = j - 1;
		}	
		arr[j+1] = key;
	}
}	

int main()
{
	int arr[] = {64, 25, 12, 22, 11};
	int size = sizeof(arr)/sizeof(int);
	print_array(arr, size);
	insertion_sort(arr, size);
	printf("\t\tAfter sort\n");
	print_array(arr, size);	
	return 0;
}
