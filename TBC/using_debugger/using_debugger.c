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
	int x = 1;// �̰� say_hello�Լ� �ȿ����� ������ ��ȿ�ϴ�.
			  /*�ٸ� �Լ����� ���ǵ� ������ �̸� ���Ƶ� ���� �������.*/
	x = 10;

	printf("Hello, World!");

	return;
}