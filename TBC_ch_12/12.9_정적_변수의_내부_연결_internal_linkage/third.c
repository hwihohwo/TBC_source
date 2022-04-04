#include <stdio.h>

extern int g_int;	// referencing declaration

void fun_third(void)
{
	g_int += 1;
	printf("g_;int in fun_third() %d %p\n", g_int, &g_int);
}