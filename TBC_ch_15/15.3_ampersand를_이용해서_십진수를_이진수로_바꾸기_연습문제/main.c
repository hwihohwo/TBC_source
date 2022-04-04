#include <stdio.h>
#include <math.h>	// pow()
#include <string.h>	// strlen()
#include <stdlib.h>	// exit()
#include <stdbool.h>

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);

int main()
{
	unsigned char i = to_decimal("01000110");
	unsigned char mask = to_decimal("00000101");

	print_binary(i);
	print_binary(mask);
	print_binary(i & mask);
	//print_binary(-20);
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
	int count = 0;
	bool size_check = false;

	printf("Decimal %3d \t== Binary ", num);

	while (1)
	{
		if (num > pow((double)2, (double)count))
			count++;
		else
		{
			size_check = true;
			break;
		}
	}

	if (size_check)
	{
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

	else
		printf("Wrong input %d\n", num);
}