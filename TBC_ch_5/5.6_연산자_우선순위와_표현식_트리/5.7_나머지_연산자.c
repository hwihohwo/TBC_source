#include <stdio.h>

int main()
{
	int hour = 0, min = 0, sec = 0;

	printf("Input seconds : ");
	scanf("%d", &sec);

	while (sec >= 0)
	{

		min = sec / 60;

		//sec = sec % 60;
		sec %= 60;

		hour = min / 60;
		//min = min % 60;
		min %= 60;

		printf("%d hours, %d minutes, %d seconds\n", hour, min, sec);
	
		printf("Input seconds : ");
		scanf("%d", &sec);
	
	}

	printf("Good bye\n");

	/*음수의 나누기*/

	//int div, mod;

	//div = 11 / 5;
	//mod = 11 % 5;
	//printf("div = %d, mod = %d\n", div, mod);

	//div = 11 / -5;
	//mod = 11 % -5;
	//printf("div = %d, mod = %d\n", div, mod);

	//div = -11 / -5;
	//mod = -11 % -5;	// first operand is negative
	//printf("div = %d, mod = %d\n", div, mod);

	//div = -11 / 5;
	//mod = -11 % 5;	// first operand is negative
	//printf("div = %d, mod = %d\n", div, mod);

	return 0;
}