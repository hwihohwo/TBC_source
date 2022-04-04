#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define SLEN 101

struct book
{
	char name[SLEN];
	char author[SLEN];
};

void print_books(const struct book* books, int n);
void write_books(const char* filename, const struct book* books, int n);
struct book* read_books(const char* filename, int* n);
void read_books2(const char* filename, struct book** books_dptr, int* n);

int main()
{
	char temp;
	int n = 3;

	struct book* my_books = (struct book*)malloc(sizeof(struct book) * 3);
	if (my_books == NULL)
	{
		printf("Malloc failed");
		exit(1);
	}

	my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
	my_books[1] = (struct book){ "Hemlet", "Willam Shakespeare" };
	my_books[2] = (struct book){ "The Odyssey", "Homer" };

	print_books(my_books, n);

	printf("\nWriting to a file.\n");
	write_books("books.dat", my_books, n);
	free(my_books);
	n = 0;
	printf("Done.\n");

	printf("\nPress any key to read data from a file.\n\n");
	temp = _getch();

	//my_books = read_books("books.txt", &n);
	read_books2("books.dat", &my_books, &n);
	print_books(my_books, n);
	free(my_books);
	n = 0;

	return 0;
}

void print_books(const struct book* books, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("Book %d : \"%s\" written by \"%s\"\n",
			i + 1, books[i].name, books[i].author);
	}
}

void write_books(const char* filename, const struct book* books, int n)
{

	FILE* fw = fopen(filename, "wb");
	if (fw == NULL)
	{
		fputs("Failed to open file", stderr);	// stderr 에러예상될때는 써볼것.
		exit(1);
	}

	fwrite(&n, sizeof(n), 1, fw);
	fwrite(books, sizeof(struct book), n, fw);

	fclose(fw);
}

struct book* read_books(const char* filename, int* n)
{
	//char temp;
	struct book* books = NULL;

	FILE* fr = fopen(filename, "rb");
	if (fr == NULL)
	{
		printf("Failed to open file");
		exit(1);
	}

	fread(n, sizeof(*n), 1, fr);
	

	books = (struct book*)calloc(sizeof(struct book), *n);

	if (books == NULL)
	{
		printf("Malloc failed");
		exit(1);
	}

	fread(books, sizeof(struct book), *n, fr);

	fclose(fr);

	return books;
}

void read_books2(const char* filename, struct book** books_dptr, int* n)
{
	//char temp;
	struct book* books = NULL;

	FILE* fr = fopen(filename, "rb");
	if (fr == NULL)
	{
		printf("Failed to open file");
		exit(1);
	}

	fread(n, sizeof(*n), 1, fr);


	books = (struct book*)calloc(sizeof(struct book), *n);

	if (books == NULL)
	{
		printf("Malloc failed");
		exit(1);
	}

	fread(books, sizeof(struct book), *n, fr);

	fclose(fr);

	*books_dptr = books;
}