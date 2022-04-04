#include <stdio.h>
/*
10
10 / 2 = 5, remainder = 0
5 / 2 = 2, remainder = 1
2 / 2 = 1, remainder = 0
1 / 2 = 0, remainder = 1
*/

void print_binary(unsigned long n);
void print_binary_loop(unsigned long n);

int main()
{
	unsigned long num = 10;

	print_binary_loop(num);
	printf("\n");
	print_binary(num);

	printf("\n");

}

void print_binary_loop(unsigned long n)
{
	int quotient, remainder;

	while (1)
	{
		quotient = n / 2;

		remainder = n % 2;

		printf("%d", remainder);

		n = quotient;

		if (n == 0)
			break;
	}
}

void print_binary(unsigned long n)
{
	int quotient, remainder;

	quotient = n / 2;
	remainder = n % 2;

	n = quotient;

	if (n != 0)
	print_binary(n);

	printf("%d", remainder);

	return;
}