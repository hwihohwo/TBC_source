//#define _CRT_SECURE_NO_WARNINGS. 마이크로소프트 비쥬얼 스튜디오에서는 scanf 쓸때 넣어야함.
// project setting에서 바꿔서 더 깔끔하게 할 수 있다.

#include <stdio.h>

int main()
{
	int i = 0, j = 0; //변수는 초기화를 해주는것을 권장.
	int sum = 0;

	printf("Input Two Integers\n");

	scanf("%d%d", &i, &j); 

	sum = i + j;

	printf("%d plus %d = %d\n", i, j, sum);//변수 선언안하고 i+j로도 가능은함.

	return 0;
}