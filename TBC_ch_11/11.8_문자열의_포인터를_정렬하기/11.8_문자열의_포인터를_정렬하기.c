#include <stdio.h>
#include <string.h> // strcmp()

void swap(char** xp, char** yp);	//Note: Optional
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main()
{
	char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" };
	int n = sizeof(arr) / sizeof(arr[0]);

	printStringArray(arr, n);

	selectionSort(arr, n);

	printStringArray(arr, n);

	return 0;
}

void swap(char** xp, char** yp)
{
	char *copy;

	copy = *xp;
	*xp = *yp;
	*yp = copy;
}

void printStringArray(char* arr[], int size)
{
	for (int i = 0; i < size; ++i)
		puts(arr[i]);
	putchar('\n');
}

void selectionSort(char* arr[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int min_index = i;

		for (int j = i + 1; j < n; ++j)
		{
			if (strcmp(arr[min_index], arr[j]) > 0)
				min_index = j;
		}
		swap(&arr[min_index], &arr[i]);
	}
}