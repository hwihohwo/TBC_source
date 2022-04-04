#include <stdio.h>	// printf() in second.c

extern int g_int;
//file scope에서는 1곳에서만 초기화 해주면 괜찮음.
// 가능하면 extern쓰는 곳에서는 초기화를 안해주는게 덜 헷갈림.
//block에서는 초기화를 할 수 없다.

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

