#include <stdio.h>	// getchar(), putchar()

int main()
{
	/*
	1. Introduce getchar(), putchar()
	2. Use while loop to precess character sequences
	3. Filter a specific character
	4. Convert numbers to asterisks
	5. Lower characters to Upper characters
	*/

	int ch;

	//ch = getchar();	
	//putchar(ch);	//한글자를 화면에 출력.

	//while (ch != '\n')// Use '\n' to find the end of a sentence
	while ((ch = getchar()) != '\n')
	{
		if (ch >= 'A' && ch <= 'Z')
			ch += 32;	// 32 = 'a' - 'A'
		else if (ch >= 'a' && ch <= 'z')
			ch -= 32;

		//for (int i = '0'; i <= '9'; ++i)
			//if (ch >= '0' && ch <= '9')	//논리연산자 and
			//	ch = '*';

		//if (ch == 'f' || ch == 'F')	//논리연산자 or
		//	ch = 'X';

		//else if (ch == 'F')
		//	ch = 'X';

		putchar(ch);

	}

	putchar(ch);

	return 0;
}
