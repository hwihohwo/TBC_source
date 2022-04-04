//#define _CRT_SECURE_NO_WARNINGS. 마이크로소프트 비쥬얼 스튜디오에서는 scanf 쓸때 넣어야함.
// project setting에서 바꿔서 더 깔끔하게 할 수 있다.

#include <stdio.h>

int main()
{
	int i = 0;

	scanf("%d", &i); // & : ampersand
	
	printf("Value is %d\n", i);

	return 0;
}