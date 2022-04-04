#include <stdio.h>
#include <float.h>

int main()
{
	printf("%u\n", sizeof(float));
	printf("%u\n", sizeof(double));
	printf("%u\n", sizeof(long double));

	float f = 123.456f;//float형 뒤에는 f붙여주는게 좋음.
	double d = 123.456;//double뒤에는 붙이지 않아도 됨.

	float f2 = 123.456;//literal에 f붙이지 않아서 double로 8바이트짜리.
					   //4바이트인 float에 넣으려해서 오류 메세지가 나옴.
	double d2 = 123.456f;//literal이 더 작은 단위이므로 오류안생김.

	int i = 3;
	float f3 = 3.f; //3.0f
	double d3 = 3.; //3.0

	float f4 = 1.234e10f;

	float f5 = 0xb.aP1; 
	//십진법에서 e대신에 16진법에서는 p를사용.
	double d5 = 1.0625e0;

	printf("%f %F %e %E\n", f, f, f, f);
	//%e를 사용시 scientific notation으로 출력.
	printf("%f %F %e %E\n", d, d, d, d);
	printf("%a %A\n", f5, f5);
	//16진수로 출력시 %a사용.
	printf("%a %A\n", d5, d5);

	return 0;
}