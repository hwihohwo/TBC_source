#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void update_string(char* str, int(*pf)(int));
void ToUpper(char* str);
void ToLower(char* str);
void Transpose(char* str);//TODO: add a new menu

int main()
{
	char options[] = { 'u', 'l', 't'};//TODO: add a new menu
	int n = sizeof(options) / sizeof(char);

	typedef void (*FUNC_TYPE)(char*);
	FUNC_TYPE operations[] = { ToUpper, ToLower, Transpose };//TODO: add a new menu

	printf("Enter a string\n>> ");

	char input[100];

	while (scanf("%[^\n]%*c", input) != 1)
		printf("Please try again.\n>> ");



	while (true)
	{
		printf("Choose an option:\n");
		printf("u) to upper\n");
		printf("l) to lower\n");
		printf("t) to transpose\n");

		char c;
		bool found = false;

		while(scanf("%c", &c) != 1)	//scanf("%c%*[^\n]%*c", &c)에서 %*[^\n]가 실행되지 않으면 %*c도 실행안됨.
			printf("Please try again.\n>> ");

		while (getchar() != '\n')
			continue;

		for (int i = 0; i < n; ++i)
		{
			if (c == options[i])
			{
				operations[i](input);
				found = true;
				break;
			}
		}

		if (found)
			break;
		else
			printf("Please try again\n");
	}

	printf("%s\n", input);

	return 0;
}

void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void update_string(char* str, int(*pf)(int))
{
	while (*str)
	{
		*str = (*pf)(*str);
		str++;
	}
}


void Transpose(char* str)
{
	while (*str)
	{
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}