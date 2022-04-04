#include <stdio.h>
#include <limits.h>

int main()
{
	//%[flags][width][.precision][length]specifier
	printf("%10i\n", 1234567);
	printf("%-10i\n", 1234567);
	printf("%+i %+i\n", 123, -123);
	printf("% i \n% i\n", 123, -123);
	printf("%X\n", 17);
	printf("%#X\n", 17);
	printf("%05i\n", 123);//빈자리를 0으로 채워줌. 순서대로 파일명같은거 만들때 필요.
	printf("%*i\n", 7, 456);//width를 control string안 말고 밖에서 바꾸고 싶을때 *사용.

	printf("\nPrecision\n");
	printf("%.3d\n", 1024);
	printf("%.5d\n", 1024);//빈자리에 0채워서 유효숫자 맞춤.
	printf("%.3f\n", 123456.1234567);
	printf("%.3f\n", 123456.1235);//반올림 해줌.
	printf("%10.3f\n", 123.45678);
	printf("%010.3f\n", 123.45678);
	printf("%.5s\n", "ABCDEFGHIJKLMN");
	printf("%.s\n", "ABCDEFGHIJKLMN");//width에 0이 들어있는 것과 같아서 아무것도 출력안됨.

	printf("\nLength\n");
	printf("%hhd %hd %d\n", 257, 257, 257);
	printf("%d %lld %lld\n", INT_MAX + 1, INT_MAX + 1, 2147483648LL);

	return 0;
} 