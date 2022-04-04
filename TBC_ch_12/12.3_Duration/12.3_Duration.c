#include <stdio.h>

/*
	Storage duration:
	- static storage duration //프로그램 시작될때 메모리 자리잡고, 끝날때까지 머무는 것.
	(Note: 'static' keyword indicates the linkage type, not the storage duration)
	- automatic storage duration
	- allocated storage duration
	- thread storage duration
*/

void count()
{
	int ct = 0;
	printf("count = %d\n", ct);
	ct++;
}

void static_count()
{
	static int ct = 0;	//함수가 끝나도 변수가 사라지지 않는다.
	printf("static count = %d\n", ct);
	ct++;
}

int main()
{
	count();
	count();
	static_count();
	static_count();

	return 0;
}