#include <stdio.h>
#include <float.h>
#include <math.h>

int main()
{
	//round-off errors (ex1)-------------
	float a, b;
	a = 1.0E20f + 1.0f;
	b = a - 1.0E20f;
	printf("%f\n", b);

	//round-off errors (ex2)--------------
	float c = 0.0f;
	c = c + 0.01f;//100번 더하기.
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	c = c + 0.01f;
	//부동소수점 표현법은 0.01을 정확히 표현할 수 없음.
	//이 오차가 누적되어서 1.00이 아닌 0.999999가 출력됨.
	printf("%f\n", c);

	//overflow---------------------
	float max = 3.402823466e+38F;
	printf("%f\n", max);
	max = max * 100.0f;
	printf("%f\n", max);//float에게 너무 커서 inf(무한대)로 출력됨.
	//double로 정의해도 double의 최대치 에서는 같은 문제 발생.
	
	//underflow--------------------
	float f = 1.401298464e-45F;
	printf("%e\n", f);
	f = f / 100.0f;
	// subnormal 정밀도 한계로 더이상 표현할 수 없는 작은숫자.
	// 숫자가 사라지고 0으로 나옴.
	printf("%e\n", f);

	float fl = 104.0f;
	printf("%f\n", fl);
	fl = fl / 0.0f;
	printf("%f\n", fl);//inf

	float fsin = asinf(1.0f);
	printf("%f\n", fsin);

	fsin = asinf(2.0f);
	printf("%f\n", fsin);
	//수학적으로 존재하지않는 값 강제로 계산시 계산x
	return 0;
}