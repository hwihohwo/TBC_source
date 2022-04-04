#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define PERIOD	'.'

int main()
{

	char c;
	int n_chars = 0;
	int n_lines = 0;
	int n_words = 0;
	bool word_flag = false;
	bool line_flag = false;

	printf("Enter text : \n");

	while ((c = getchar()) != PERIOD)
	{
		if (!isspace(c))
			n_chars++;	// count non-space cahracters

		if (!isspace(c) && !word_flag)
		{
			n_words++;
			word_flag = true;
		}

		if (isspace(c))
			word_flag = false;

		if (!isspace(c) && !line_flag)
		{
			n_lines++;
			line_flag = true;
		}

		if (c == '\n')
			line_flag = false;
	}

	printf("\nCharacters = %d, Words = %d, Lines = %d",
		n_chars, n_words, n_lines);

	return 0;
}
