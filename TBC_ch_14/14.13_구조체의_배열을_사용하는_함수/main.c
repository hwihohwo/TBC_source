#include <stdio.h>
#include <stdlib.h>

#define SLEN 101

struct book
{
	char name[SLEN];
	char author[SLEN];
};

void print_books(const struct book* books, int n);

int main()
{
	//struct book my_books[3];// = { {"The Great Gatsby", "F. Scott Fitzgerald"}, ...};
	struct book* my_books = (struct book*)malloc(sizeof(struct book) * 3);
	if (my_books == NULL)
	{
		printf("Malloc failed");
		exit(1);
	}

	my_books[0] = (struct book){"The Great Gatsby", "F. Scott Fitzgerald"};
	my_books[1] = (struct book){ "Hemlet", "Willam Shakespeare" };
	my_books[2] = (struct book){ "The Odyssey", "Homer" };

	print_books(my_books, 3);

	free(my_books);

	return 0;
}

void print_books(const struct book* books, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("Book %d : \"%s\" written by \"%s\"\n",
			i + 1, (books + i)->name, books[i].author);
	}
}