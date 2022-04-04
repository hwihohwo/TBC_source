#include <stdio.h>
#include <stdbool.h>

int main()
{
	unsigned num;
	int isPrime = 0;// flag(상태를 표시하기 위한 변수), try bool type

	scanf("%u", &num);

	isPrime = true;

	for (unsigned i = 2; (i * i) <= num; ++i)
	{
		if (num % i == 0)
		{
			isPrime = false;

			if (num == i * i)
				printf("%u is divisible by %u.\n", num, i);
			else
				printf("%u is divisible by %u and %u\n", num, i, num / i);
		}
	}

	if (isPrime)
		printf("%u is a prime number", num);
	else
		printf("%u is not a prime number", num);

	return 0;
}