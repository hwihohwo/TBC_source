#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define STRLEN	500

int main(int argc, char* argv[])
{
	int ch;
	//char ch_w[STRLEN];
	int i = 0;
	FILE* fr;		//TODO: file pointer to write
	FILE* fw;
	
	/*
	typedef struct _iobuf
	{
		char* _ptr;
		int _cnt;
		char*  _base;
		int _flag;
		int _file;
		int _charbuf;
		int _bufsiz;
		char*	tmpfname;
	} FILE;
	*/

	//const char* out_filename = "output.txt"	//TODO: Use this
	unsigned long count = 0;

	if (argc != 3)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fr = fopen(argv[1], "r")) == NULL) // Open a text file for reading.
	{
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((fw = fopen(argv[2], "w")) == NULL)
	{
		printf("Can't open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}


	while ((ch = fgetc(fr)) != EOF) // getc(fr)
	{
		//putc(ch, stdout);	// same as purchar(ch);
		fputc(ch, stdout);	//putc보다 조금 더 안정적이라고함.

		fputc(ch, fw);

		count++;
	}

	/*
		fopen mode strings for text files
		- r: reading
		- w: creating-and-writing or over-writing
		- a: appending or creating-and-writing
		- r+: both reading and writing
		- w+: reading and writing, over-writing or creating
		- a+: reading and writing, appending or creating
	*/

	//TODO: open file to write with "w" mode string


	//while (fgets(ch_w, STRLEN, stdin) != NULL)
	//{
	//
	//	fputs(ch_w, fw);

	//	//TODO: use fputs() to write a file stream!
	//}

	fclose(fr);
	fclose(fw);
	//TODO:

	printf("FILE %s has %lu characters\n", argv[1], count);

	return 0;
}