#include <stdio.h>
#include <math.h>	// pow()
#include <string.h>	// strlen()
#include <stdlib.h>	// exit()
#include <stdbool.h>

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);

int main()
{
	/*
		Regular Logical Operators : &&, ||, and !

		bool have_apple = true;
		bool like_apple = true;
		if (have_apple && like_apple)
			eat_apple();

		Bitwise Logical Operators :
		- Bitwise NOT ~
		- Bitwise AND &
		- Bitwise OR |
		- Bitwise EXCLUSIVE OR ^
	*/

	unsigned char a = 6;
	unsigned char b = 5;

	printf("%hhu\n", a);
	print_binary(a);

	printf("%hhu\n", b);
	print_binary(b);

	printf("%hhu\n", a & b);
	print_binary(a & b);

	printf("%hhu\n", a | b);
	print_binary(a | b);

	printf("%hhu\n", a ^ b);
	print_binary(a ^ b);

	printf("%hhu\n", ~a);
	print_binary(~a);

	return 0;
}

unsigned char to_decimal(const char bi[])
{
	const size_t n = strlen(bi);

	unsigned char dec = 0;

	for (size_t i = 0; i < n; ++i)
	{
		if (bi[i] == '1')
			dec += (unsigned char)pow(2.0, (double)(n - 1 - i));
		else if (bi[i] != '0')
		{
			printf("Wrong character : %c", bi[i]);
			exit(1);
		}
	}

	return dec;
}

void print_binary(const unsigned char num)
{
	printf("Decimal %3d \t== Binary ", num);

	const int count = sizeof(num) * 8;


	for (int i = count; i >= 0; --i) //감소로 반복할때 size_t(unsigned)자료형은 0밑으로 내려갈때 매우 큰숫자로 가기 때문에 무한루프로 돌게됨.
	{
		double mask = pow((double)2, (double)i);

		if ((num & (unsigned char)mask) == mask)
			printf("1");
		else if (i == count)
			continue;
		else
			printf("0");
	}

		printf("\n");
}