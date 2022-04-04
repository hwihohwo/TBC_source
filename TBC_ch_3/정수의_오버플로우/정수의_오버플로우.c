#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
	unsigned int u_max = UINT_MAX;
	unsigned int u_min = 0;
	signed int i_max = INT_MAX;
	signed int i_min = INT_MIN;
	unsigned int i = 0b11111111111111111111111111111111;
	//0b는 뒤의 literal constant가 이진수라는뜻.

	printf("max of uint = %u\n", u_max);
	printf("min of uint = %u\n", u_min);
	printf("max of int = %d\n", i_max);
	printf("min of int = %d\n", i_min);
	
	unsigned int u_max_plus = UINT_MAX + 1;

	// i to binary representation
	char buffer[33];
	_itoa(u_max_plus, buffer, 2);
	
	// print decimal and binary
	printf("decimal: %u\n", u_max_plus);
	printf("binary: %s\n", buffer);

	return 0;
}//오버플로우. 자료형의 가장 큰 값에서 1을 더하면 가장작은값으로,
// 가장 작은값에서 1을 빼면 가장큰값으로 돌아가 버림.