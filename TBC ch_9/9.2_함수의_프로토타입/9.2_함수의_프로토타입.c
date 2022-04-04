#include <stdio.h>
#include <string.h> // strlen()
#include <stdbool.h>

#define WIDTH	40
#define NAME	"Seong_Hwi Cho"
#define ADDRESS	"Busan, Korea"

void print_string_center(char str[]);

int main()
{
	print_multiple_chars('*', WIDTH, true);// argument

	print_string_center(NAME);
	print_string_center(ADDRESS);
	print_string_center("I am programmer");

	print_multiple_chars('*', WIDTH, false);

	return 0;
}

void print_string_center(char str[])
{
	int n_blanks = (WIDTH - (int)strlen(str)) / 2;

	print_multiple_chars(' ', n_blanks, false);
	printf("%s\n", str);
}
