#include <stdio.h>
#include "MyHeader.h"

int main()
{
	int i = hello();

	int b = add(2, 3);

	printf("%d\n", b);

	printf("%d\n", i);

	printf("%p\n", hello);

	return 0;
}