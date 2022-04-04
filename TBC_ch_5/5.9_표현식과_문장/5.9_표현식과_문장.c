#include <stdio.h>

int main()
{
			/*Statements*/
	int x, y, apples;	// declaration statement
	apples = 3;			// assignment statement
	;					// null statement
	7;
	1 + 2;
	x = 4;
	++x;
	x = 1 + (y = 5);	// y = 5 is subexpression

	while (x++ < 10)	// while statement (structured statements)
		y = x + y;

	printf("%d\n", y);	// function statement

	return 0;			// return statement

			/*Side Effects and Sequence Points*/
	
	x = 4;						// main intent is evlauating expressions
	y = 1 + x++;

	while (x++ < 10)			// (x++ < 10) is a full expression.
		printf("%d\n", x);

	y = (4 + x++) + (6 + x++);	// Not (4 + x++) nor (6 + x++) is a full expression.
	//한 문장에서 증감연산자를 여러번 사용하거나, 함수에서 parameter로 들어가는 변수또한
	//증감연산자를 사용하는것은 좋지않다.
}