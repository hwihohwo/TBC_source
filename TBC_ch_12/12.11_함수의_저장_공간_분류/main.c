#include <stdio.h>

/*
	Storage Classes and Functions
	- Functions external (by default) or static
	- A function declaration is assumed to be extern
*/

int g_int = 123;	// defining declaration
//TODO: try static

void fun();
void fun_second();

//void tool(); //static으로 선언된 함수. linking error 발생.

int main()
{
	fun();
	fun_second();

	//tool();

	return 0;
}

void fun()
{
	extern int g_int; // optional

	g_int += 1;
	printf("g_int in fun() %d %p\n", g_int, &g_int);
}