#include <stdio.h>
#include <math.h>

void print_binary(const char num);

int main()
{
	/*
	Signed Integers

	- Sign-magnitude representation
	00000001 is 1 and 10000001 is -1
	00000000 is +0, 10000000 is -0
	Two zeros +0 -0, from -127 to +127

	- One's complement method
	To reverse the sign, invert each bit.
	00000001 is 1 and 11111110 is -1.
	11111111 is -0
	from -127 to +127

	- Two's complement method (commomly used in most systems)
	To reverse the sign, invert each bit and add 1.
	from -128 to +127

	*/

	print_binary(127);
	print_binary(-127);
	print_binary(~127 + 1);

	print_binary(12);
	print_binary(-12);
	print_binary(~12 + 1);

	print_binary(7);
	print_binary(-7);
	print_binary(~-7 + 1);

	return 0;
}



void print_binary(const char num)
{
	printf("Decimal %3d \t== Binary ", num);

	const char count = sizeof(num) * 8;


	for (int i = (count - 1); i >= 0; --i) 
	{
		const char mask = (char)pow((double)2, (double)i);

		if ((num & mask) == mask)
			printf("1");
		else
			printf("0");
	}

	printf("\n");
}