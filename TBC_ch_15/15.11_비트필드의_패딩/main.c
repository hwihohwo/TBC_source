#include <stdio.h>
#include <stdio.h>
#include <limits.h>	// CHAR_BIT
#include <stdbool.h>
#include <string.h>

void char_to_binary(unsigned char uc)
{
	const int bits = CHAR_BIT * sizeof(unsigned char);
	for (int i = bits - 1; i >= 0; i--)
		printf("%d", (uc >> i) & 1);
}

void print_binary(char* data, int bytes)//Note: extended for any sizes
{
	for (int i = 0; i < bytes; ++i)
		char_to_binary(data[bytes - 1 - i]);
	printf("\n");
}

int main()
{
	struct {
		bool option1	: 1;
		//bool			: 0; // 해당 자료형 만큼 메모리를 더 할당받음.
		bool option2	: 1;
		unsigned long long option3 : 16; 
		//비트필드 앞의 자료형은 어떤 방식으로 해석하라고 정하는 역할.
		//그리고 구조체에 어느정도의 메모리를 할당해달라고 요구함.
	} bbf;

	memset((char*)&bbf, 0x00, sizeof(bbf));
	print_binary((char*)&bbf, sizeof(bbf));
	bbf.option1 = 1;
	bbf.option2 = 1;
	bbf.option3 = 0xffff;
	print_binary((char*)&bbf, sizeof(bbf));

	printf("%zu bytes\n", sizeof(bbf));

	struct {
		unsigned short option1 : 1;
		unsigned short option2 : 1;
		//unsigned short : 0;
		unsigned short option3 : 1;
	}usbf;

	printf("%zu bytes\n", sizeof(usbf));

	struct {
		unsigned int option1 : 1;
		//unsigned int : 0;
		unsigned int option2 : 1;
		//bool option3 : 1;
	}uibf;

	printf("%zu bytes\n", sizeof(uibf));

	return 0;
}