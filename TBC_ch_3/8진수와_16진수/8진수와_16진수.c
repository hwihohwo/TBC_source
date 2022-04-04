#include <stdio.h>

int main()
{
	unsigned int decimal = 4294967295;
	unsigned int binary = 0b11111111111111111111111111111111;
	//2진수로 표현시 literal 앞에 0b
	unsigned int oct = 037777777777;
	//8진수는 0
	unsigned int hex = 0xffffffff;
	//16진수는 0x
	printf("%u\n", decimal);
	printf("%u\n", binary);
	printf("%u\n", oct);
	printf("%u\n", hex);

	printf("%o %x %#o %#x %#X", decimal, decimal, decimal, decimal, decimal);
	//%o 팔진수, %x 16진수
	//출력시에 pre-fix즉 8진수인지 16진수인지 여부를 명확히 표기하려면
	//%#o, %#x, %#X로 #을 붙여주면됨. 대문자로하면 출력도 대문자로 나옴.
	return 0;

}