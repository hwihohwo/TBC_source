#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 10;

	int* ptr = NULL;

	//ptr = (int*)malloc(sizeof(int) * n);
	ptr = (int*)calloc(n, sizeof(int));// contiguous allocation	calloc는 배정된 메모리를 초기화해줌.
	if (!ptr)
		exit(1);

	for (int i = 0; i < n; ++i)
		printf("%d ", ptr[i]);
	printf("\n");

	/*
		realloc() KNK p. 422
		- doesn't initialize the bytes added
		- returns NULL if can't enlarge the memory block
		- If first argument is NULL, it behaves like malloc()
		- if second argument is 0, it frees the memory block.
	*/

	for (int i = 0; i < n; ++i)
		ptr[i] = i + 1;

	n = 20;

	int* ptr2 = NULL;
	ptr2 = (int*)realloc(ptr, n * sizeof(int)); //이미 할당받은 메모리의 포인터를 넣음.
	//ptr = (int*)realloc(ptr, n * sizeof(int));

	printf("%p %p\n", ptr, ptr2);

	printf("%d\n", ptr[0]);

	if (!ptr2)
		exit(1);
	else
		ptr = NULL;

	for (int i = 0; i < n; ++i)
		printf("%d ", ptr2[i]);		// copies data
	printf("\n");

	free(ptr2);

	return 0;
}