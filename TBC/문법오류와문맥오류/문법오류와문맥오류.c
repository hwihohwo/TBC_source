#include <stdio.h>

int main()
{
	int n1, n2, n3, n4;
	
	n1 = 2;
	n2 = n1 * n1;
	n3 = n2 * n1;
	n4 = n2 * n1;//문맥오류 발생.

	return 0;

}