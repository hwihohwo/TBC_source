#include <stdio.h>

void say_hello(void);// prototyping, function declaration
//함수의 선언만 main함수 앞에 해둘수도 있다.

int main()
//operating system이 프로그램 실행 시킬때는 무조건 main부터 실행시킨다.
{

	say_hello();
	


	return 0;
}


void say_hello(void)// function definition
{
	printf("Hello, World!\n");

	return;
}//return 타입이 void일때는 return없음.