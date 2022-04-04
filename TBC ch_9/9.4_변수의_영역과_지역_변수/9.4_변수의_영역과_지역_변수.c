#include <stdio.h>

//int a; 파일 전체에서 사용가능한 변수.

int int_max(int i, int j);

int int_max(int i, int j)
{
	//a = 456;
	int m;
	m = i > j ? i : j;
	return m;
}

int main()
{
	//m = 123;

	int a;

	a = int_max(1, 2);

	printf("%d\n", a);
	printf("%p\n", &a);

	{
		int a; //실무에서는 헷갈리지 않게 가능하다면 외부의 변수와 이름 겹치기 않게.
		a = int_max(4, 5);

		printf("%d\n", a);
		printf("%p\n", &a);

		int b = 123;
	}

	printf("%d\n", a);
	printf("%p\n", &a);

	return 0;
}