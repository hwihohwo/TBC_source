#include <stdio.h>

void my_func(int);

int main()
{
	my_func(1);

	return 0;
}

void my_func(int n)
{
	printf("Level %d, address of variable n = %d\n", n, (int) & n);

	if (n < 4)	// 종료조건을 걸어주지않으면 stack overflow가 발생.
		my_func(n + 1);

	printf("Level %d, address of variable n = %d\n", n, (int) & n);
}
