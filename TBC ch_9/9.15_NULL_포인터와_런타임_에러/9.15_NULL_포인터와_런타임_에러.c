#include <stdio.h>

int main()
{
	//int a = 1234;
	//printf("%p\n", &a);
	//printf("%d\n", a);

	//int *ptr = 1234;

	//printf("%p\n", ptr);
	//printf("%d\n", *ptr);

	int* safer_ptr = NULL;

	//포인터 변수를 사용해도 되는지 확인하기 위해 NULL대입.

	int a = 123;

	/*safer_ptr = &a;*/

	int b;
	scanf("%d", &b);

	if (b % 2 == 0)
		safer_ptr = &a;

	if (safer_ptr != NULL)
		printf("%p\n", safer_ptr);
	if (safer_ptr != NULL)
		printf("%d\n", *safer_ptr);
	//처음 포인터 변수 선언시 사용될지 안될지 모르니까 
	//NULL값을 관습적으로 넣어둬서 런타임에러를 방지한다.

	return 0;
}