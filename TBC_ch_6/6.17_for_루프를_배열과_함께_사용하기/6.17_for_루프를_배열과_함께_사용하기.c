#include <stdio.h>

#define SIZE 5
#define Input_number 5

int main()
{
	//int my_arr[SIZE];

	//// prepare for array data
	//for (int i = 0; i < SIZE; ++i)
	//	my_arr[i] = i;

	//// print array data
	//for (int i = 0; i < SIZE; ++i)
	//	printf("%d ", my_arr[i]);

	int sum = 0;
	int avg = 0;
	int numbers[Input_number];


	printf("Enter %d numbers : ", Input_number);

	for (int i = 0; i < Input_number; ++i)
		scanf("%d", &numbers[i]);

	for (int i = 0; i < Input_number; ++i)
		sum += numbers[i];
	//for loop를 여러개 쓰는방식으로 쪼개는것이 조금 더 효율적일 수 있다.
	avg = sum / Input_number;

	printf("Sum = %d\n", sum);
	printf("Average = %d\n", avg);

	return 0;
}