#include <stdio.h>
#include "SimpleList.h"

List movie;


void clear_buffer()
{
	while (getchar() != '\n') continue;
}

void read_file(List* plist)
{
	char filename[STRLEN] = { '\0' };
	FILE* mov;

	printf("Please input filename to read and press Enter.\n>>");

	if (scanf("%[^\n]%*c", filename) != 1)
	{
		printf("Wrong input.\n");
		exit(1);
	}
	mov = fopen(filename, "r");
	if (mov == NULL)
	{
		printf("Cannot open file.\n");
		exit(1);
	}
	if (fscanf(mov, "%d%*c", &plist->size) != 1)
	{
		printf("Wrong format\n");
		exit(1);
	}
	Item temp;
	for (int i = 0; i < plist->size; ++i)
	{
		if (fscanf(mov, "%[^\n]%*c", temp.title) != 1 ||
			fscanf(mov, "%f%*c", &temp.rating) != 1)
		{
			printf("Wrong format.\n");
			exit(1);
		}
		if (AddItem(&movie, temp) == false)
			exit(1);
	}
	printf("%d items have been read from the file.\n", plist->size);
	fclose(mov);
}// read_file

int select_index()
{
	int index;

	while (1)
	{
		printf("\nPlease select an option and press enter.\n");
		printf("1. Print all items		2. Print an item\n");
		printf("3. Edit an item			4. Add an item\n");
		printf("5. Insert an item		6. Delete an item\n");
		printf("7. Delete all items		8. Save file\n");
		printf("9. Search by name		10. Quit\n>>");

		if (scanf("%d%*c", &index) != 1)
		{
			printf("Wrong input.\n");
			clear_buffer();
			continue;
		}

		else if (index < 1 || index > 10)
		{
			printf("Wrong index.\n");
			clear_buffer();
			continue;
		}
		else
			return index;
	}
}

int input_item(const List* plist)
{
	int item;
	int index = CountItems(plist);
	while (1)
	{
		if (scanf("%d", &item) != 1)
		{
			printf("Wrong input. Please try again.\n");
			clear_buffer();
			continue;
		}
		else if (item < 0 || item > index - 1)
		{
			printf("Wrong item number. Please try again.\n");
			clear_buffer();
			continue;
		}
		else
		{
			clear_buffer();
			return item;
		}
	}
}

void print_an_item(const Item item)
{
	printf("%s\t%.1f\n", item.title, item.rating);
}

void print_all(List* plist)
{
	unsigned int count = PrintAllItems(plist, print_an_item);
	printf("%u items have been printed.\n", count);
}

void search_and_print_item(const List* plist)
{
	Node* search = NULL;
	printf("Input the index of item to print.\n>>");
	int item = input_item(plist);
	search = plist->head;
	for (int i = 0; i < item; ++i)
	{
		search = search->next;
	}
	print_an_item(search->item);
}

void edit_an_item(const List* plist)
{
	Node* search = NULL;
	printf("Input the index of item to edit.\n>>");
	int item = input_item(plist);
	search = plist->head;
	for (int i = 0; i < item; ++i)
	{
		search = search->next;
	}
	printf("Input new title and press enter.\n>>");
	int flag = scanf("%[^\n]%*c", search->item.title);
	printf("Input new rating and press enter.\n>>");
	flag = scanf("%f", &search->item.rating);
}

void add_an_item(List* plist)
{
	Item temp;
	printf("Input title and press enter.\n>>");
	int flag = scanf("%[^\n]%*c", temp.title);
	printf("Input rating and press enter.\n>>");
	flag = scanf("%f", &temp.rating);
	if (AddItem(plist, temp) == false)
		exit(1);
	printf("%u : ", CountItems(plist) - 1);
	print_an_item(temp);
}

void insert_an_item(List* plist)
{
	Item temp;
	int index;
	printf("Input the index of item to insert.\n>>");
	index = input_item(plist);
	printf("Input title and press enter.\n>>");
	int flag = scanf("%[^\n]%*c", temp.title);
	printf("Input rating and press enter.\n>>");
	flag = scanf("%f", &temp.rating);
	InsertbyIndex(temp, plist, index);
}

void delete_an_item(List* plist)
{
	int index;
	printf("Input the index of item to delete.\n>>");
	index = input_item(plist);
	RemoveByIndex(plist, index);
}

void delete_all_items(List* plist)
{
	ClearList(plist);
}

void write_an_item(FILE* file, Item item)
{
	fprintf(file, "%s\n%.1f\n", item.title, item.rating);
}

void save_file(const List* const plist)
{
	FILE* fw;
	char filename_save[STRLEN] = { '\0' };
	printf("Please input filename to save.\n>>");
	int flag = scanf("%[^\n]%*c", filename_save);
	fw = fopen(filename_save, "w");
	if (fw == NULL)
	{
		printf("Save failed.\n");
		exit(1);
	}
	unsigned int num = CountItems(plist);
	fprintf(fw, "%d\n", num);
	WriteAllItems(plist, fw, write_an_item);
	fclose(fw);
}

bool compare(Item a, Item b)
{
	bool cmp = strcmp(a.title, b.title);
	if (cmp == 0)
		return true;
	else
		return false;
}

void search_by_name(const List* plist)
{
	int index = 0;
	bool find = false;
	Item item_to_search;
	Item* item_found = (Item*)malloc(sizeof(Item));
	if (item_found == NULL)
	{
		printf("ERROR: malloc failed.\n");
		exit(1);
	}
	printf("Input title to search.\n>>");
	int flag = scanf("%[^\n]%*c", item_to_search.title);
	find = Find(plist, item_to_search, &index, item_found, compare);
	if (find == false)
	{
		printf("Cannot found.\n");
		free(item_found);
	}
	else
	{
		printf("%d : ", index);
		print_an_item(*item_found);
		free(item_found);
	}
}
int main()
{
	int index;

	read_file(&movie);
	while (1)
	{
		index = select_index();

		switch (index)
		{
		case (1):
			print_all(&movie);
			break;
		case (2):
			search_and_print_item(&movie);
			break;
		case (3):
			edit_an_item(&movie);
			break;
		case (4):
			add_an_item(&movie);
			break;
		case (5):
			insert_an_item(&movie);
			break;
		case (6):
			delete_an_item(&movie);
			break;
		case (7):
			delete_all_items(&movie);
			break;
		case (8):
			save_file(&movie);
			break;
		case (9):
			search_by_name(&movie);
			break;
		case (10):
			printf("Good bye.\n");
			delete_all_items(&movie);
			exit(0);
		}//switch
	}//while
	return 0;
}// main