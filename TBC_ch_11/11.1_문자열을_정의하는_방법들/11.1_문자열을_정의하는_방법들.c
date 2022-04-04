#include <stdio.h>

#define MESSAGE "A symbolic string constant"
#define MAXLENGTH 81

int main()
{
	char words[MAXLENGTH] = "A string in an array";
	const char* pt1 = "A pointer to a string.";

	puts("Puts() adds a newline at the end:");// puts() add \n at the end
	puts(MESSAGE);
	puts(words);		// char words[21] removes this warning
	puts(pt1);
	words[3] = 'p';		// OK
	puts(words);
	//pt1[8] = 'A';		// Error 읽기전용 메모리를 바꾸려해서

	char greeting[50] = "Hello, and"" How are" " you"
		" today!";

	// char greeting[50] = "Hello, and How are you today!";

	puts(greeting);

	printf("\" To be, or not to be\" Hamlet said.\n");

	printf("%s, %p, %c\n", "We", "are", *"excellent programmers");
	
	const char m1[15] = "Love you!";

	for (int i = 0; i < 15; ++i)
		printf("%d ", (int)m1[i]);	// Note the null characters
	printf("\n");

	const char m2[15] = { 'L', 'o', 'v', 'e', ' ', 'y', 'o', 'u', '!'};
	
	for (int i = 0; i < 15; ++i)
		printf("%d ", (int)m2[i]);	// Note the null characters
	printf("\n");

	const char m3[] = "Love you, too!";

	int n = 8;
	char cookies[1] = { 'A', };
	char cakes[2 + 5] = { 'A', };
	char pies[2 * sizeof(long double) + 1] = { 'A', };
	//char crumbs[n]; //VLA

	char truth[10] = "Truths is ";
	if (truth == &truth[0]) puts("true!");
	if (*truth == 'T') puts("true!");
	if (*(truth + 1) == truth[1]) puts("true!");
	if (truth[1] == 'r') puts("true!");

	return 0;
}