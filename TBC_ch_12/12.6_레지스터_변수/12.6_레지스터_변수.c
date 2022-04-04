#include <stdio.h>

void temp(register int r)
{
	// do something with r
}

int main()
{
	register int r;	//컴파일러가 상황을 보고 레지스터에 넣어줌. 항상 넣는것은 아니다.
	r = 123;

	//printf("%p\n", &r);
	int* ptr = &r;	//register변수의 주소는 포인터에 저장할 수 없다.

	return 0;
}