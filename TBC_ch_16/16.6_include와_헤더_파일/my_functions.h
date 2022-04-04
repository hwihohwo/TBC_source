#pragma once
extern int status;

static int si = 0;

extern int add(int a, int b);

static int multiply(int a, int b)	//static함수는 body를 헤더파일에 둘 수 있다.
{
	return a * b;
}

//int subtract(int a, int b)
inline int subtract(int a, int b)
{
	return a - b;
}

void print_status();
void print_address();