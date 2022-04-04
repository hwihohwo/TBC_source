#include <stdio.h>

int main()
{
	const int Entire_repeat = 10;

	char c = 'A';

	for (int i = 0; i < Entire_repeat; i++)
	{
		for (c; c < 'Z'; c++)
			printf("%c", c);
	}

	return 0;
}