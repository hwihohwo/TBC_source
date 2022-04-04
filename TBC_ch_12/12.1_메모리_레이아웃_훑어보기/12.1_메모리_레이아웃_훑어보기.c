#include <stdio.h>

//프로그램의 일부에서 큰 메모리가 필요한 경우

#define MAX 1000

void func()
{
	int l_arr[MAX] = { 0, };
}
//main은 항상 프로그램과 함께 동작하기 때문에 따로 함수등에 선언하는게 좋음.
int main()
{
	/*
	Call func()


	Call func()
	*/

	return 0;
}