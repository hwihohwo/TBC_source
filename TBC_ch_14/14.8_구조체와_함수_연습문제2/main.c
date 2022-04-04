#include <stdio.h>
#include <string.h>

#define NLEN 30

struct name_count {
	char first[NLEN];
	char last[NLEN];
	int num;
};

struct name_count receive_input();
struct name_count count_characters(struct name_count);
void show_result(const struct name_count);
char* s_gets(char* st, int n);

int main()
{
	struct name_count user_name;

	user_name = receive_input();
	user_name = count_characters(user_name);
	show_result(user_name);

	return 0;
}

char* s_gets(char* st, int n)
{
	char* str_p;
	char* find;

	str_p = fgets(st, n, stdin);

	if (str_p)
	{
		find = strchr(st, '\n');

		if (find != NULL)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return str_p;
}

struct name_count receive_input()
{
	int flag;
	struct name_count str_nc;

	printf("Input your first name:\n>>");

	flag = scanf("%[^\n]%*c", str_nc.first);
	if (flag != 1)
		printf("Wrong input");

	printf("Input your last name:\n>>");

	flag = scanf("%[^\n]&*c", str_nc.last);
	if (flag != 1)
		printf("Wrong input");

	return str_nc;
}

struct name_count count_characters(struct name_count str_nc)
{
	str_nc.num = (int)strlen(str_nc.first) + (int)strlen(str_nc.last);

	return str_nc;
}

void show_result(const struct name_count str_nc)
{
	printf("Hi, %s %s. Your name has %d characters.",
		str_nc.first, str_nc.last, str_nc.num);
}