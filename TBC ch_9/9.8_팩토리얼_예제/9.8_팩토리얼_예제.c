#include <stdio.h>
#include <stdbool.h>
//loop vs recursion

long loop_factorial(int n);
long recursive_factorial(int n);

int main()
{
	int num;
	bool quit;

	while (1)
	{
		printf("Input a positive integer(press q to quit) : ");

		quit = scanf("%d", &num);

		if (quit == false)
			break;

		else if (num < 0)
			printf("Wrong input.\n"); 

		else
		{
			printf("%d\n", loop_factorial(num));
			printf("%d\n", recursive_factorial(num));
		}
	}
	return 0;
}

long loop_factorial(int n)
{
	int factorial = 1;

	for (int i = 1; i <= n; ++i)
		factorial *= i;
	
	return factorial;
}

long recursive_factorial(int n)
{
	if (n > 0)
		return n * recursive_factorial(n - 1); // tail (end) recursion
	else
		return 1;
}