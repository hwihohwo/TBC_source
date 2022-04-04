#include <stdio.h>

// https://docs.microsoft.com/ko-kr/cpp/preprocessor/pragma-directives-and-the-pragma-keyword?view=msvc-170

/*
#pragma tokens (ex: once)
*/

//#pragma pack(1) //1바이트로 패딩하라는 의미.
//_Pragma("pack(1)") // destringizing : remove first and last ", \" -> "
//#define PACK1 _Pragma("pack(1)") //매크로 형태로 만들 수 있다.
//PACK1

//#pragma warning( disable : 4477 )
//#pragma warning( error : 4477 )

struct s {
	int i;
	char ch;
	double d;
};

int main()
{
	struct s A;
	printf("Size of A is: %zu", sizeof(A));

	return 0;
}