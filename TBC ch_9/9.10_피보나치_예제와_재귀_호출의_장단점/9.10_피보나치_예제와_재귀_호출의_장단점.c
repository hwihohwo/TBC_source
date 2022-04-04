﻿#include <stdio.h>

int fibonacci(int number);

int main()
{
	for (int count = 1; count < 13; ++count)
		printf("%d ", fibonacci(count));

	return 0;
}

int fibonacci(int number)
{
	printf("fibonacci with %d\n", number);

	if (number > 2)
		return fibonacci(number - 1) + fibonacci(number - 2);// double recursion
	else
		return 1;
}

// Note : memory (in)efficiency, redundant computation