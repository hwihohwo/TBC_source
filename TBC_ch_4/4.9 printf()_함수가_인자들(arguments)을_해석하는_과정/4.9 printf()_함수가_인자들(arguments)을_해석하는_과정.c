#include <stdio.h>

int main()
{
	float	n1 = 3.14;  // 4 bytes
	double	n2 = 1.234; // 8 bytes
	int		n3 = 1024;	// 4 bytes

	printf("%f %f %d\n\n", n1, n2, n3);

	//Note the warnings in output window
	printf("%d %d %d\n\n", n1, n2, n3);		// 4, 4, 4 (N, N, N)
	printf("%lld %lld %d\n\n", n1, n2, n3);	// 8, 8, 4 (N, N, Y)
	printf("%f %d %d\n\n", n1, n2, n3);		// 8, 4, 4 (Y, N, N)
	printf("%f %lld %d\n\n", n1, n2, n3);	// 8, 8, 4 (Y, N, Y)

	return 0;
}	//64bit환경과 32bit환경에서의 차이도 기억해둘것. 예제는 32bit기준으로 작성됨.