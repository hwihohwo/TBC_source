#include <stdio.h>

int main()
{
	float Won = 0.0f, dollar = 0.0f;

	printf("환전할 금액(원)을 입력하세요\n");

	scanf("%f", &Won);

	dollar = Won * 0.00089f;

	printf("해당금액은 %f달러 입니다.\n", dollar);

	return 0;
}