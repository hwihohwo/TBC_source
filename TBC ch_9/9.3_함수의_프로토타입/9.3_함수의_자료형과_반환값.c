#include <stdio.h>

int int_min(int, int);

int main()
{
	int i1, i2;

	while (1)
	{
		printf("Input two integers : ");

		if (scanf("%d %d", &i1, &i2) != 2) break;

		int lesser = int_min(i1, i2);
		//int lesser = min;
		printf("The lesser of %d and %d is %d\n", i1, i2, lesser);

		//printf("The lesser of %d and %d is %d\n", i1, i2, int_min(i1, i2));
	}

	printf("End.\n");

	return 0;
}

//int int_min(int i, int j). //문법상 int형 반환 자료형은 생략가능.
int int_min(int i, int j)
{
	//int min;

	//if (i < j)
	//	min = i;
	//else
	//	min = j;

	//return min;

	 return (i < j) ? i : j;

	// return (float)min;

	//if (i < j)
	//	return i;
	//else
	//	return j;

	//pritnf("ERROR");	// return 만나면 함수가 끝나기 때문에 실행 될 수 없음.
	//exit(1);	//실행된다면 문제가 있다는 의미로 추가해 둘 수도 있음.

	//return; // return with no value
}