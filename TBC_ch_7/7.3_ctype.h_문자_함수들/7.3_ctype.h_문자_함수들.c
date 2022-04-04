#include <stdio.h>
#include <ctype.h>	//isalpha() and more

int main()
{
	int ch;

	while ((ch = getchar()) != '\n')
	{
	/*	if (islower(ch))
			ch = toupper(ch);
		else if (isupper(ch))
			ch = tolower(ch);*/

		//for (int i = '0'; i <= '9'; ++i)
			if (isdigit(ch) != 0)	//논리연산자 and
				ch = '*';

		//if (ch == 'f' || ch == 'F')	//논리연산자 or
		//	ch = 'X';

		//else if (ch == 'F')
		//	ch = 'X';

		putchar(ch);

	}

	putchar(ch);

	return 0;
}

