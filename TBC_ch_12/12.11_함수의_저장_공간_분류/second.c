#include <stdio.h>

extern int g_int;//	referencing declaration

void tool(void);

void fun_second(void)
{
	tool();

	g_int += 1;
	printf("g_int; in fun_second() %d %p\n", g_int, &g_int);
}

static void tool(void) //definition과 declaration어디에 static붙여도 상관없음.
{
	//
}