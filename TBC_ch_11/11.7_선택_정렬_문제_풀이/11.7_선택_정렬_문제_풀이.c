#include <stdio.h>

void swap(int* xp, int* yp);
void printArray(int arr[], int size);
void selectionSort(int arr[], int n);

int main()
{
	int arr[] = { 64, 25, 12, 22, 11, 44, 23, 16, 65, 2, 33, 67, 98};
	int n = sizeof(arr) / sizeof(arr[0]);

	selectionSort(arr, n);

	printArray(arr, n);

	return 0;
}

void swap(int* xp, int* yp)
{
	int copy = 0;
	
	copy = *xp;
	*xp = *yp;
	*yp = copy;
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
}

void selectionSort(int arr[], int n)
{

	for (int i = 0; i < n - 1 ; ++i)
	{
		int min_index = i;

		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < arr[min_index])
				min_index = j;
		}
		swap(&arr[min_index], &arr[i]);
	}
}