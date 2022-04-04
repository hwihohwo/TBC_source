#include <stdio.h>
#include <complex.h>//복소수형을 쓸수있도록 함.

int main()
{
	_Dcomplex z; //_Fcomplex(float), long double 타입도 있음.
	z._Val[0] = 1.0;
	z._Val[1] = 1.0;

	return 0;
}// 보통 직접 만들어서 사용하는 경우가 많아
 // VS에서는 꼼꼼하게 지원하지는 않음.