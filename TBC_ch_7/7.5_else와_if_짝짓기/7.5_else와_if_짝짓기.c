#include <stdio.h>

int main()
{
	int number;
	scanf("%d", &number);

	//if (number == 1)
	//	printf("One");

	//else
	//	if (number == 2)
	//		printf("Two");

	//	else
	//		if (number == 3)
	//			printf("Three");

	// minimum 127 levels of nestings

	if (number > 5)
	{
		if (number < 10)
			printf("Larger than 5 smaller than 10\n");
		else
			printf("Larger than 10\n");
	}
	else
		printf("Less than or equal to 5");
	//else는 indenting과 상관없이 가까운 if에 엮인다.
	//헷갈릴 여지가 있는 코딩이면 중괄호로 확실하게 구분해주는 것이 좋다.

	return 0;
}