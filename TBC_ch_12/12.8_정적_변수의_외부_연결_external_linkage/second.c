#include <stdio.h>	// printf() in second.c

extern int g_int;
//file scope������ 1�������� �ʱ�ȭ ���ָ� ������.
// �����ϸ� extern���� �������� �ʱ�ȭ�� �����ִ°� �� �򰥸�.
//block������ �ʱ�ȭ�� �� �� ����.

void temp()
{
	g_int += 1000;
}

void fun_sec()
{
	temp();

	g_int += 7;
	printf("g_int in fun() %d %p\n", g_int, &g_int);
}

