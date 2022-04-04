#include <stdio.h>
#include <assert.h>

//#include <limits.h>
//_Static_assert(CHAR_BIT == 9, "9-bit char assumed");
// compile time에서 잡아주는 assert

int divide(int a, int b);

int main()
{
	int a, b;
	int f = scanf("%d%d", &a, &b);

	printf("a / b = %d", divide(a, b));

	return 0;
}

int divide(int a, int b)
{
	assert(b != 0); //release 모드에서는 작동하지 않는다.
	// 절대로 일어나선 안되는 일에 대해서 assert를 걸어주는 습관을 들일것.

	//if (b == 0) {
	//	printf("Cannot divide\n");
	//	exit(1);
	//}

	return a / b;
}
