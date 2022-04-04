#include <stdio.h>
#include <math.h>	//fabs()

int main()
{
	/*
	Relational Operators
	<		is less than
	<=		is less than or equal to
	==		is equal to
	>=		is greater than or equal to
	>		is greater than
	!=		is not equal to
	*/

	//int n = 0;
	//while (n++ < 5)		// n++ < 5 is a relational expression
	//	printf("%d ", n);

	//printf("\n");

	//char c = 'A';
	//while (c != 'Z')
	//	printf("%c ", c++);

	const double PI = 3.141592653598979323972719123;
	double guess = 0.0;

	printf("Input PI : ");
	scanf("%lf", &guess);
	//while (guess != PI)
	while (fabs(guess - PI) > 0.01)	//fabs는 ()안의 수치의 절대값을 반환하는 함수.
	{
		printf("Fool! Try again.\n");
		scanf("%lf", &guess);
	}

	printf("Good!");

	return 0;
}