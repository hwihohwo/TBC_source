#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.141592f //기호적 상수
// PI = 3.141592f라고 하면 컴파일러가 = 표시까지 같이 PI에 넣어버림.
#define AI_NAME "Friday"
// 전처리 단계에서 선언해두면 변경시 편함.

int main()
{
	const float pi = 3.141592f; //이렇게 기호적 상수로 선언도 가능.
	//c이후의 언어들에서는 const 변수로 사는경우가 더 권장됨.
	float radius, area, circum;

	printf("I'm %s.\n", AI_NAME);
	printf("Please, Input radius\n");

	scanf("%f", &radius);

	area = PI * radius * radius; //area = pi*r*r

	circum = 2.0f * PI * radius; // circum = 2.0 * pi * r

	// sphere area, sphere volume, ...

	printf("Area is %f\n", area);

	printf("Circumference is %f\n", circum);
	//TODO:, strings, const

	return 0;

}