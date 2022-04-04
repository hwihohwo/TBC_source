#define _CRT_SECURE_NO_WARNINGS

#include < stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
	char c = 65;
	short s = 200;
	unsigned int ui = 3000000000U;// 3'000'000'000U
	//뒤의 U는 unsigned int의 literal이라는 의미를 나타냄. 컴파일러가 자동으로 처리하므로 생략해도 무방.
	//숫자의 자릿수 구분하는 ' 는 c++에서는 표준이지만 c에서는 아님.
	//컴파일러에서 처리해주기도 하나 가능하면 c에서는 안쓰는게 좋음.
	long l = 65537L;
	long long ll = 12345678908642LL;

	printf("char = %hhd, %d, %c\n", c, c, c);
	printf("short = %hhd, %hd, %d\n", s, s, s);
	printf("unsigned int = %u, %d\n", ui, ui);
	printf("long = %hd, %ld\n", l, l);
	printf("long long = %lld, %ld\n", ll, ll);

	return 0;

}