#include <stdio.h>
#include <ctype.h>		// islower()
#include <stdbool.h>
#include <iso646.h>		// and, or, not

#define PERIOD '.'

int main()
{
/*
	Logical operators

	&& : and
	|| : or
	!  : not
*/

	//bool test1 = 3 > 2 || 5 > 6;	// true
	//bool test2 = 3 > 2 && 5 > 6;	// false
	//bool test3 = !(5 > 6);			// true, equivalent to 5 <= 6

	//printf("%d %d %d\n", test1, test2, test3);

	/*Character counting example*/

	//char ch;
	//int count = 0;

	//while ((ch = getchar()) != PERIOD)
	//{
	//	if (ch != '\n' && ch != ' ')
	//		count++;
	//}

	//printf("%d", count);

	//Alternatives in iso646.h

	//&&	: and
	//||	: or
	//!		: not

	/*Precedence*/
	// !는 단항연산자이므로 우선순위 높다.
	// ||, &&는 우선순위 낮은편. 이중에서는 &&가 ||보다는 우선순위가 높다.
	
	//int a = 1, b = 2, c = 3, d = 4;

	//a > b && b > c || b > d;
	//((a > b) && (b > c)) || (b > d); 
	//헷갈리면 괄호를 적극 활용하자. 의도를 명확하게 해야함.

	/*Short-circuit Evaluation

		- Logical expressions are evaluated from left to right
		- && and || are sequence points*/

	//int temp = (1 + 2) * (3 + 4);

	//printf("Before : %d\n", temp);

	//if (temp == 0 && (++temp == 1024))
	//{	// do nothing
	//}
	//// &&는 왼쪽 expression이 false가 되면 뒤의 expression은 계산도 진행하지 않음.
	//printf("After : %d\n", temp);

	//int x = 1, y = 2;
	//if (x++ > 0 && x + y == 4)
	//	printf("%d %d\n", x, y);
	
	//논리 연산자와 증감 연산자를 동시에 쓰는것과 같은
	//헷갈리는 상황은 피하는 것이 좋다.

	/*Ranges*/

	//for (int i = 0; i < 100; ++i)
	//	if (i >= 10 && i <= 20)
	//		printf("%d ", i);

	//printf("\n");

	//for (int i = 0; i < 100; ++i)
	//	if (10 <= i <= 20)		//Note : if((10 <= i ) <= 20)
	//		printf("%d ", i);

	for (char c = 0; c < 127; ++c)
		if (c >= 'a' && c <= 'z')
			printf("%c ", c);

	printf("\n");

	for (char c = 0; c < 127; ++c)
		if (islower(c))
			printf("%c ", c);

	return 0;
}

          
