#include <stdio.h>

void say_hello(void);// prototyping, function declaration
//�Լ��� ���� main�Լ� �տ� �صѼ��� �ִ�.

int main()
//operating system�� ���α׷� ���� ��ų���� ������ main���� �����Ų��.
{

	say_hello();
	


	return 0;
}


void say_hello(void)// function definition
{
	printf("Hello, World!\n");

	return;
}//return Ÿ���� void�϶��� return����.