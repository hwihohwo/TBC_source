#include <stdio.h>
#include <string.h>

#define NLEN 30

struct name_count {
	char first[NLEN];
	char last[NLEN];
	int num;
};

void receive_input(struct name_count*);
void count_characters(struct name_count*);
void show_result(const struct name_count*);
char* s_gets(char* st, int n);

int main()
{
	struct name_count user_name;

	receive_input(&user_name);
	count_characters(&user_name);
	show_result(&user_name);

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

void receive_input(struct name_count* user_name)
{
	int flag;

	printf("Input your first name:\n>>");

	//s_gets(user_name->first, NLEN);
	flag = scanf("%[^\n]%*c", user_name->first); // ^ : cap operator
	//[^\n]은  \n이 나타날때 까지 입력받으라는 의미. %*c는 c를 하나 무시하라는 의미. 여기서는 \n을 하나 무시함.
	if (flag != 1)
		printf("Wrong input");

	printf("Input your last name:\n>>");

	//s_gets(user_name->last, NLEN);
	flag = scanf("%[^\n]&*c", user_name->last);
	if (flag != 1)
		printf("Wrong input");
}

void count_characters(struct name_count* str_nc)
{
	str_nc->num = (int)strlen(str_nc->first) + (int)strlen(str_nc->last);
}

void show_result(const struct name_count* user_name)
{
	printf("Hi, %s %s. Your name has %d characters.",
		user_name->first, user_name->last, user_name->num);
}