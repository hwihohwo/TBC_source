#include <stdio.h>

int main()
{
	for (int n = 1, nsqr = n * n; n < 10; n++, nsqr = n * n)
		printf("%d %d\n", n, nsqr);

	//Notes that commas in printf() are not comma operators
	//but separators

	//int i, j;
	//i = 1;
	//i++, j = i;// comma is a sequence point
	//printf("%d %d\n", i, j);

	//int x, y, z;
	//z = x = 1, y = 2;
	//printf("x=%d, y=%d, z=%d \n", x, y, z);
	//z = (x = 1), (y = 2);
	//printf("x=%d, y=%d, z=%d \n", x, y, z);
	//z = ((x = 1), (y = 2));
	//printf("x=%d, y=%d, z=%d \n", x, y, z);
	//// comma연산자는 제일 오른쪽의 값이 전체 expression의 값이된다.

	//int my_money = 123, 456; // error
	int my_money = (123, 456);
	printf("%d\n", my_money);

	//comma연산자를 남발하는것은 권장하지 않음.

	return 0;
}