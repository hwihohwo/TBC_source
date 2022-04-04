#include <stdio.h>

int main()
{
	char c;
	while ((c = getchar()) != '.')
	{
		printf("You love ");

		switch (c)	//Note : integer types only
		{
		case 'a':
		case 'A': //대문자 A일때도 apple이 출력.
			printf("apple");
			break;
		case 'b':
		case 'B':
			printf("baseball");
			break;
		case 'c':
		case 'C':
			printf("cake");
			break;
		default:
			printf("nothing");
			//break;	default뒤에는 break필요없음.
		}

		printf(".\n");

		while (getchar() != '\n')
			continue;
	}

	return 0;
}