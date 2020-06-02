#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
/*1. Copy the elements in to two temp arrays*/
	int n1, n2, i, j, k;
		n1 = m-l+1;
		n2 = r-m;

	int temp1[n1], temp2[n2];
	
	for (i = 0; i < n1; i++)
	{
		temp1[i] = arr[l+i];	
	}
	
	for (j = 0; j < n2; j++)
	{
		temp2[j] = arr[m+1+j];
	}
		

/*2. Run the loop for copying the elements according to their value from the temp array to actual array*/
	i = j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (temp1[i] <= temp2[j])
		{
			arr[k] = temp1[i];
			i++;
		}
		else
		{
			arr[k] = temp2[j];
			j++;
		}
		k++;
	}

/*3. Copy the remaining elements from the temp array into actual array if left anything*/	
	while (i < n1)
	{
		arr[k] = temp1[i];
		i++;
		k++;
	}
	
	while (j < n2)
	{
		arr[k] = temp2[j];
		j++;
		k++;
	}
}

void merge_sort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l+(r-l)/2;
		merge_sort(arr, l, m);
		merge_sort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

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

int main()
{
	int arr[] = {33, 22, 11, 44, 9};
	int size;
	size = sizeof(arr)/sizeof(int);
	print_array(arr, size);
	merge_sort(arr, 0, size-1);
	printf("\t\tAfter sort\n");
	print_array(arr, size);
	return 0;
}
