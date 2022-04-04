#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double seed_m, target_m, inter;
	int year = 0;
	//annual interest : 3%
	printf("Input your seed money : ");
	scanf("%lf", &seed_m);
	printf("Input your target money : ");
	scanf("%lf", &target_m);
	printf("Input annual interest (%%) : ");
	scanf("%lf", &inter);

	double fund = seed_m;

	while (fund < target_m)
	{
		//fund = fund * (1+inter/100);
		fund += fund * inter / 100.0;	//같은기능.
		//year = year + 1;
		//year += 1;
		year++; // 3가지 다 같은기능.

		printf("%lf\n", fund);
	}
	
	printf("You will take %d years\n", year);

	return 0;
}