#include <stdio.h>
#include <math.h>	// pow()
#include <string.h>	// strlen()
#include <stdlib.h>	// exit()

unsigned char to_decimal(const char bi[]);

int main()
{
	printf("Binary (string) to Decimal conversion\n");

	printf("%d\n", to_decimal("3425"));

	printf("%d\n", to_decimal("00000110"));
	printf("%d\n", to_decimal("00010110"));

	// Note: ^ (caret) means power in math.
	// Hint: (int)pow(2, 3) == 8

	printf("%d\n", to_decimal("10010100"));

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