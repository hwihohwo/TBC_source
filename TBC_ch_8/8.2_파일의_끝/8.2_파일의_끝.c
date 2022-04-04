#include <stdio.h>

int main()
{
	int c;

	//while ((c = getchar()) != EOF) // End of File
	//	putchar(c);				   // citl + z -> EOF

	//실행중인 프로그램 ctrl + c 로 강제종료(?)

	// stream이 끝나는걸 표시하는게 EOF
	while (1)
	{
		c = getchar();
		printf("%d\n", c);
			if (c == EOF)
				break;
	}

	return 0;
}