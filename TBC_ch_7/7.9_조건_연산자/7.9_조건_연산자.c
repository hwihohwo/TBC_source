#include <stdio.h>
#include <stdbool.h>

int main()
{
	int temp;
	temp = true ? 1024 : 7;	// ternary(삼항연산자)
	printf("%d\n", temp);	// conditional operator

	temp = false ? 1024 : 7;
	printf("%d\n", temp);

	//int number;
	//scanf("%d", &number);

	//bool is_even = (number % 2 == 0) ? true : false;
	////const를 사용할 수 있는 상황이면 사용하는게 맘편하다.

	//if (is_even)
	//	printf("Even");
	//else
	//	printf("Odd");
	/*(number % 2 == 0) ?
		(printf("Even")) : (printf("Odd"));*/
	//직접 printf를 넣는것도 가능하지만 보통은
	//flag를 활용해서 표시하고 그 기능을 구현하는게 더 좋다.

	//int a = 1, b = 2;
	//int max = (a > b) ? a : b;

	return 0;
}
