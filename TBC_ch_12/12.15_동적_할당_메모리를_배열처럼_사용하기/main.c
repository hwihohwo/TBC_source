#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*
		One variable
	*/

	//int* ptr = NULL;

	//ptr = (int*)malloc(sizeof(int) * 1);
	//if (ptr == NULL) exit(1);

	//*ptr = 1024 * 3;
	//printf("%d\n", *ptr);

	//free(ptr);
	//ptr = NULL;

	/*
		1D array
	*/

	//int n = 3;
	//int* ptr = (int*)malloc(sizeof(int) * n);;
	//if (ptr == NULL) exit(1);

	//ptr[0] = 123;
	//*(ptr + 1) = 456;
	//*(ptr + 2) = 789;

	//free(ptr);
	//ptr = NULL;

	/*
		2D array
	*/

	//int row = 3, col = 2;
	//int(*ptr2d)[2] = (int(*)[2])malloc(sizeof(int) * row * col);
	////int(*ptr2d)[col] = (int(*)[col])malloc(sizeof(int) * row * col);// VLA
	//if (!ptr2d) exit(1);

	//for (int r = 0; r < row; r++)
	//	for (int c = 0; c < col; c++)
	//		ptr2d[r][c] = c + col * r;

	//for (int r = 0; r < row; r++)
	//{
	//	for (int c = 0; c < col; c++)
	//		printf("%d ", ptr2d[r][c]);
	//	printf("\n");
	//}

	//int row = 3, col = 2;
	//int* ptr = (int*)malloc(row * col * sizeof(int));
	//if (!ptr) exit(1);

	//for (int r = 0; r < row; r++)
	//	for (int c = 0; c < col; c++)
	//		ptr[c + col * r] = c + col * r;

	//for (int r = 0; r < row; r++)
	//{
	//	for (int c = 0; c < col; c++)
	//		printf("%d ", *(ptr + c + col * r));
	//	printf("\n");
	//}

	/*
		3D
	*/

	int row = 3, col = 2, depth = 2;
	int* ptr = (int*)malloc(row * col * depth * sizeof(int));
	if (ptr == NULL) exit(1);

	for (int d = 0; d < depth; ++d)
		for (int r = 0; r < row; ++r)
			for (int c = 0; c < col; ++c)
				ptr[c + col * r + (col * row) * d] = c + col * r + (col * row) * d;

	for (int i = 0; i < row * col * depth; ++i)
		printf("%d ", ptr[i]);

	return 0;
}