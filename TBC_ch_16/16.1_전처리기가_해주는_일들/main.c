﻿#include <stdio.h>

int main()
{
	/*
		Program written in C

		Translating
		Preprocessing
		Compiling
		Linking

		Executagble
	*/

	/*
		International characters
	*/

	puts("안녕하세요? 한글을 사랑합니다.\n");

	/*
		Trigraph Sequences
		- Some keyboards don't provide all the symbols used in C.
		- Three-character sequences
	*/

	//  /Zc:trigraphs

	int arr[3] = { 1, 2, 3 };
	printf("arr??(0??) == %d\n", arr??(0??));
	//printf("arr[0] == %d\n", arr[0]);

	/*
		Digraphs
		- Two-character sequences
	*/

	printf("arr<:1:> == %d\n", arr<:1:>);
	//printf("arr[1] == %d\n", arr[1]);

	/* Two physical lines vs One logical line */
	printf("This is a very very very very very very \
very very very long long long long long long  line. \n");

	/*
		Tokens
		- Groups separated from each other by spaces, tabs, or line breaks
		Whitespace characters -> a single space
	*/

	int/*a variable to count a number*/n = 1; // 주석은 빈칸하나로 번역이됨.
	// int n = 1;

	return 0;
}