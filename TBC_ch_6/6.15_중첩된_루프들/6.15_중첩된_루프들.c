#include <stdio.h>

//int main()
//{
//	const int Entire_repeat = 10;
//
//	char c = 'A';
//
//	for (int i = 0; i < Entire_repeat; i++)
//	{
//		for (c; c <= 'Z'; c++)
//			printf("%c ", c);
//
//		printf("\n");
//
//		c = 'A';
//	}
//
//	return 0;
//}   
//내가 짠 코드.

//#define NUM_ROWS	5
//#define FIRST_CHAR	'A'
//#define LAST_CHAR	'K'
////c에서는 define을 쓰는게 좀 더 스타일이 맞음.
//
//
//
//int main()
//{
//	int r;//	row loop
//	int c;// character loop
//
//	for (r = 0; r < NUM_ROWS; ++r)// outer row loop
//	{
//		for (c = FIRST_CHAR; c <= LAST_CHAR; ++c)// inner character loop
//			printf("%c ", c);
//		printf("\n");
//	}
//
//	return 0;
//}


//#define NUM_ROWS	10
//#define FIRST_CHAR	'A'
//
//int main()
//{
//	int row;	//outer low loop
//	char c;		//inner character
//
//	for (row = 0; row < NUM_ROWS; ++row)
//	{
//		for (c = FIRST_CHAR;c <= FIRST_CHAR + row; ++c)
//			printf("%c ", c);	//inner loop와 outer loop가 연결되어 있는 경우가 많음.
//		printf("\n"); 
//	}
//
//	return 0;
//}

//#define NUM_ROWS	10
//#define FIRST_CHAR	'A'
//
//int main()
//{
//	int row;	//outer low loop
//	char c;		//inner character
//
//	for (row = 0; row < NUM_ROWS; ++row)
//	{
//		for (c = FIRST_CHAR;c <= FIRST_CHAR + row; ++c)
//			printf("%c ", c);	//inner loop와 outer loop가 연결되어 있는 경우가 많음.
//		printf("\n"); 
//	}
//
//	return 0;
//}

int main()
{
	char last_word;
	int r;	// outer row loop
	char c;	// inner character

	printf("Input last word(only capital) : ");
	scanf("%c", &last_word);

	int num_row = (int)last_word - 'A' + 1;

	for (r = 0; r < num_row; ++r)
	{
		for (c = 'A' + r; c <= last_word; ++c)
			printf("%c ", c);
		printf("\n");
	}
	return 0;
}
