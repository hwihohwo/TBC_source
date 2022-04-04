#include <stdio.h>

int main()
{
	/*
	while (expression)
	 statement
	 */
	 //컴퓨터 내부에서는 expression의 값이 0이면 false, 
	 //0이 아닌 값이면 true라고 판단.


	int i;

	//i = 1;
	//while (i < 5)			// infinite loop
	//	printf("Hi!\n");	// iteration(계속 반복하는것)

	//i = 1;
	//while (--i < 5)			// wrong direction
	//	printf("Hi!\n");

	//i = 1;
	//while (i < 5)
	//{
	//	printf("i before = %d\n", i);
	//	i++;
	//	printf("i after = %d\n", i);
	//}

	//i = 10;
	//while (i++ < 5)		// cannot enter
	//{
	//	printf("Hi\n");
	//}

	/*Common mistakes*/

	//i = 0;
	//while (i < 3)
	//{
	//	printf("%i\n", i);
	//	i++;				// indenting
	//}

	//i = 0;
	//while (i++ < 3);		// null statement
	//	printf("%i\n", i);

	while (scanf("%d", &i) == 1)
		;// null statement
	// do something (?)


	return 0;
}