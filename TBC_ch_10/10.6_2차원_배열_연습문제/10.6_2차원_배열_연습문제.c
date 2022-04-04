#include <stdio.h>

#define MONTHS 12
#define YEARS 3

int main()
{
	double year2016[MONTHS] = { -3.2, 0.2, 7.0,	14.1, 19.6,	23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 };
	double year2017[MONTHS] = { -1.8, -0.2,	6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 };
	double year2018[MONTHS] = { -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 };
	
	double year_tem[YEARS][MONTHS] =
	{
		{ -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 },
		{ -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 },
		{ -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 }
	};

	printf("[Temperature Data]\n");

	printf("Year index : ");
	for (int m = 1; m <= MONTHS; ++m)
		printf("\t%d ", m);

	printf("\n");

	for (int y = 0; y < YEARS; ++y)
	{
		printf("Year %d     : ", y);
		for (int m = 0; m < MONTHS; ++m)
			printf("\t%.1lf ", year_tem[y][m]);
		printf("\n");
	}
	printf("\n");

	printf("[Year's average temperature of 3 years]\n");

	for (int y = 0; y < YEARS; ++y)
	{
		printf("year %d :", y);
		double sum = 0.0;
		for (int m = 0; m < MONTHS; ++m)
			sum += year_tem[y][m];
		printf(" average temperature = %.1lf\n", sum / (double)MONTHS);
	}

	printf("\n");

	printf("[Monthly average temperature for 3 years]\n");

	printf("Month index : ");

	for (int m = 1; m <= MONTHS; ++m)
		printf("\t%d", m);

	printf("\n");

	printf("Avg temps   : ");
	for (int m = 0; m < MONTHS; ++m)
	{
		double sum = 0.0;
		for (int y = 0; y < YEARS; ++y)
			sum += year_tem[y][m];
		printf("\t%.1lf", sum / (double)YEARS);
	}
	
	printf("\n");

	return 0;
}