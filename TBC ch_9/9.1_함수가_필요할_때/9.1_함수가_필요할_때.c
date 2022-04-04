#include <stdio.h>
#include <string.h> // strlen()
#include <stdbool.h>

#define WIDTH	40
#define NAME	"Seong_Hwi Cho"
#define ADDRESS	"Busan, Korea"

void print_multiple_chars(char c, int n_stars, bool print_newline);// parameter
void print_string_center(char str[]);

int main()
{
	print_multiple_chars('*', WIDTH, true);

	print_string_center(NAME);
	print_string_center(ADDRESS);
	print_string_center("I am programmer");

	print_multiple_chars('*', WIDTH, false);

	return 0;
}

void print_multiple_chars(char c, int n_stars, bool print_newline)
{
	for (int i = 0; i < n_stars; ++i)
		printf("%c", c);	//putchar(c)
	
	if (print_newline)
		printf("\n");
}

void print_string_center(char str[])
{
	int n_blanks = (WIDTH - (int)strlen(str)) / 2;

	print_multiple_chars(' ', n_blanks, false);
	printf("%s\n", str);
}

void print_multiple_chars(char c, int n_stars, bool print_newline)
{
	for (int i = 0; i < n_stars; ++i)
		printf("%c", c);	//putchar(c)

	if (print_newline)
		printf("\n");
}