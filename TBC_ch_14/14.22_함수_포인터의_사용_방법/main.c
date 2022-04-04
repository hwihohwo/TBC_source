#include <stdio.h>
#include <ctype.h>

void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void UpdateString(char* str, int (*pf)(int))
{
	while (*str)
	{
		*str = (*pf)(*str);
		str++;
	}
}

int main()
{
	char str[] = "Hello, World!";

	void (*pf)(char*);

	pf = ToUpper;// Name of a function is a pointer
	// pf = &ToUpper;//Acceptable
	// pf = ToUpper(str);//Not acceptible in C

	printf("String literal %lld\n", (long long)("Hello, World!"));
	printf("Funcion pointer %lld\n", (long long)ToUpper);
	printf("Variable %lld\n", (long long)str);

	(*pf)(str);
	//포인터를 통해 함수 실행시키려면 입력, 반환 자료형태를 알아야 하기 때문에 포인터도 같은 형태로 지정해야함.
	//pf(str);//K&R X, ANSI OK

	printf("ToUpper %s\n", str);

	pf = ToLower;

	pf(str);

	printf("ToLower %s\n", str);

	/*
		passing function pointers to functions
	*/

	UpdateString(str, toupper);

	printf("ToUpper %s\n", str);

	UpdateString(str, tolower);

	printf("ToLower %s\n", str);

	//Note: __cdecl is function calling convention

	return 0;
}