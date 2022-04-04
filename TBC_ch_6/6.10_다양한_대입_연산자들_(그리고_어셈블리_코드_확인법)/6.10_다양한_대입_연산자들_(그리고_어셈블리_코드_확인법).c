#include <stdio.h>

int main()
{
	 /*+=, -=, *=, /=, %=*/

	int i = 1024;

	i = i + 10;
	i += 10;

	i %= 4;

	i = i * (1 + 2);
	i *= 1 + 2;
	i *= (1 + 2);		//Check precedence

	for (int i = 0; i < 10; i++)	// i += 2 같은 형식으로 많이 씀.
		;

	return 0;
}