#include <stdio.h>

void say_hello(void);

int main()
{
	int x, y, z;

	x = 1;
	y = 20;
	z = 3;

	z = x + y;

	say_hello();

	return 0;

}

void say_hello(void)
{
	int x = 1;// 이곳 say_hello함수 안에서만 변수가 유효하다.
			  /*다른 함수에서 정의된 변수는 이름 같아도 서로 상관없음.*/
	x = 10;

	printf("Hello, World!");

	return;
}