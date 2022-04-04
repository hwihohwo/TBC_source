#include <stdio.h>

int main()
{
	int n = 1;

	while (n < 3)
	{
		printf("%d\n", n);
		n = n + 1;
	}
	//디버거로 반복문 찍어보기.
	return 0;
}