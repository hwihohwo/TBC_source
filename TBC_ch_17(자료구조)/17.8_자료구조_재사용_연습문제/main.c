#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SimpleList.h"

void Clear_buffer()
{
	while (getchar() != '\n') break;
}

void read_an_item(FILE* file, Element* item)
{
	if (fscanf(file, "%[^\n]%*c", item->title) != 1 ||
		fscanf(file, "%u%*c", &item->year) != 1)
	{
		printf("Wrong format.\n");
		exit(1);
	}
}

void Read_file(List* plist, void (*read_an_item_func)(FILE* file, Element* item))
{
	FILE* fr;
	Element movie;
	unsigned int num = 0;
	unsigned int count = 0;
	char filename[STRLEN] = { '\0' };
	printf("Input filename to open.\n>>");
	int flag = scanf("%[^\n]%*c", filename);
	fr = fopen(filename, "r");
	if (fr == NULL)
	{
		printf("Cannot open.\n");
		exit(1);
	}
	if (fscanf(fr, "%u\n", &num) != 1)
	{
		printf("Wrong format.\n");
		exit(1);
	}
	while (1)
	{
		if (count == num) break;
		read_an_item_func(fr, &movie);
		AddItem(plist, movie);
		count++;
	}
}

void print_an_item(const Element item)
{
	printf("%s\n   %d\n", item.title, item.year);
}

unsigned int menu()
{
	unsigned int input = 0;
	while (1)
	{
		printf("Input a number to execute.\n");
		printf("1. Print all members.\n");
		printf("2. Print all members whose names start with.\n");
		printf("3. Print all members who joined in 1965.\n");
		printf("4. exit\n>>");
		int flag = scanf("%u%*c", &input);
		if (input < 1 || input > 4)
		{
			printf("Wrong input.\n");
			continue;
		}
		return input;
	}
}

void print_all_items(List* plist)
{
	unsigned int count = PrintAllItems(plist, print_an_item);
	printf("%u items have been printed.\n", count);
}

bool name_starts_with(const Element a, const Element b)
{
	size_t n = strlen(a.title);
	int comp = memcmp(a.title, b.title, n);
	if (comp == 0)
		return true;
	else
		return false;
}

void find_name_starts_with(List* plist)
{
	Element item_to_find;
	Element* item_found;
	int index = 0;
	Node* pnode = plist->head;
	printf("Input a word to find.\n>>");
	int flag = scanf("%[^\n]%*c", item_to_find.title);
	while (pnode != NULL)
	{
		if (name_starts_with(item_to_find, pnode->item) == true)
		{
			FindItemByIndex(plist, index, &item_found);
			print_an_item(*item_found);
		}
		pnode = pnode->next;
		index++;
	}
}

bool Joined_in(List* plist, unsigned int year)
{
	bool result = false;
	Node* pnode = plist->head;
	while (pnode != NULL)
	{
		if (year == pnode->item.year)
		{
			print_an_item(pnode->item);
			result = true;
		}
		pnode = pnode->next;
	}
	return result;
}

void find_joined_year(List* plist)
{
	unsigned int joined_year;
	printf("Input a year to find.\n>>");
	int flag = scanf("%u%*c", &joined_year);
	bool result = Joined_in(plist, joined_year);
	if (result == false)
		printf("Cannot found.\n");
}

int main()
{
	List avengers;
	unsigned int input = 0;

	InitializeList(&avengers);

	Read_file(&avengers, read_an_item);

	while (1)
	{
		input = menu();

		switch (input)
		{
		case (1):
			print_all_items(&avengers);
			break;
		case (2):
			find_name_starts_with(&avengers);
			break;
		case (3):
			find_joined_year(&avengers);
			break;
		case (4):
			printf("Good bye.\n");
			ClearList(&avengers);
			exit(0);
		}// switch
	}
	/*
	1. Read data from a file.
	2. Print all members.
	3. Print all members whose names start with "Black".
	4. Print all members who joined in 1965.
	*/

}