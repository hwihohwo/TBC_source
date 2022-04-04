#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define TMAX 40

typedef struct {
	char character[TMAX];
	char name[TMAX];
} Item;

void print_items_array(Item items[], int size);
int compare_items(const void* first, const void* second);

const Item* sequential_search(const Item items[], const int size, const char name[TMAX]);
const Item* binary_search(const Item items[], const int size, const char name[TMAX]);

int main()
{
	/* Assume that there is no duplicated items */

	Item items[] = {
						{"Iron Man", "Tony Stark"},
						{"Thor", "Thor Odinson"},
						{"Ant-Man", "Hank Pym"},
						{"Wasp", "Janet van Dyne"},
						{"Hulk", "Bruce Banner"},
						{"Captain America", "Steve Rogers"},
						{"Scarlet Witch", "Wanda Maximoff"},
						{"Black Widow", "Natasha Romanoff"},
						{"Dr. Strange", "Stephen Strange"},
						{"Daredevil", "Matthew Murdock"},
						{"Punisher", "Frank Castle"},
						{"Batman", "Bruce Wayne"}
					};

	int n = sizeof(items) / sizeof(items[0]);

	print_items_array(items, n);

	qsort(items, n, sizeof(Item), compare_items);

	print_items_array(items, n);

	while (1)
	{
		char key[TMAX] = "";
		printf("Input key >> ");

		fgets(key, TMAX, stdin);
		if ((strlen(key) > 0) && (key[strlen(key) - 1] == '\n'))
			key[strlen(key) - 1] = '\0';

		if (strcmp(key, "exit") == 0)
			break;

		//const Item* found = sequential_search(items, n, key);
		const Item* found = binary_search(items, n, key);

		if (found == NULL)
			printf("Not in the list.\n\n");
		else
			printf("%s is %s\n\n", found->character, found->name);
	}

	return 0;
}

void print_items_array(Item items[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%s (%s)\n", items[i].character, items[i].name);
	printf("\n");
}

int compare_items(const void* first, const void* second)
{
	Item* first_item = (Item*)first;
	Item* second_item = (Item*)second;

	return strcmp(first_item->character, second_item->character);
}

const Item* sequential_search(const Item items[], const int size, const char name[TMAX])
{
	Item* find = NULL;
	for (int i = 0; i < size; ++i)
	{
		if (strcmp(items[i].character, name) == 0)
		{
			find = items[i].character;
			break;
		}
	}
	return find;
}

const Item* binary_search(const Item items[], const int size, const char name[TMAX])
{
	int first = 0;
	int last = size - 1;
	int middle = (last + first) / 2;
	int cmp;

	while (first <= last)
	{
		cmp = strcmp(items[middle].character, name);
		if (cmp == 0)
		{
			return &items[middle];
		}
		else if (cmp > 0)
			last = middle - 1;
		else 
			first = middle + 1;
		middle = (last + first) / 2;
	}
	return NULL;
}