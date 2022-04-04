#include <stdio.h>
#include <stdint.h>//고정너비정수 자료형 사용하게하는 library
#include <inttypes.h>//안에 이미 stdint.h가 include되어있음.

int main()
{
	int i;
	int32_t i32;	 //32 bit integer
	int_least8_t i8; // smallest 8 bit
	int_fast8_t f8;  // fastest minimum
	intmax_t imax;   // biggest signed integers
	uintmax_t uimax; // biggest unsignes integers

	i32 = 1004;

	printf("me32 = %d\n", i32);
	printf("me32 = %" "d" "\n", i32);
	printf("me32 = %" PRId32 "\n", i32);
	//앞의 고정너비정수 형식에 따라 PRI~~로 맞춰서 적어주면 됨.
	//<inttypes.h>가 include되어있는 상태에서 사용가능한 매크로.
	//멀티 플랫폼 관련코딩에서 신경을 써야함.
	return 0;
}