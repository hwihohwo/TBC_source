#include <stdio.h>

int count()
{
	int ct = 0;
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;

	//return &ct; //함수 끝나면 변수가 사라지기 때문에 사용x
}

int* static_count()
{
	static int ct = 0;	// initialized only once!
	printf("static count = %d %lld\n", ct, (long long)&ct);
	ct++;

	return &ct;			// static 변수이기 때문에 가능은 함. 권장하지는 않는다. 다른 block에서 사용하고 싶다면 차라리 전역 변수로.
}

//int func(static int i)	// Warning (Error in GCC)
//{		// parameter변수는 함수가 실행될때 메모리 배정을 받는데,
//		// static메모리 공간에 넣는다는 것은 맞지않음.
//}

void counter_caller()
{
	count();
}

void static_counter_caller()
{
	static_count();
}

int main()
{
	count();
	count();
	counter_caller();

	static_count();
	static_count();
	static_counter_caller();

	return 0;
}