#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STRLEN 40

struct mov_list {
	char title[STRLEN];
	float rating;
	struct mov_list* next;
};

typedef struct mov_list list;

list* head = NULL;
list* search = NULL;
list* new_node = NULL;

int read_file()
{
	int num = 0;
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

	if (fscanf(mov, "%d%*c", &num) != 1)
	{
		printf("Wrong format\n");
		exit(1);
	}

	for (int i = 0; i < num; ++i)
	{
		new_node = (list*)malloc(sizeof(list));

		if (new_node == NULL)
		{
			printf("ERROR: malloc failed.\n");
			exit(1);
		}

		if (fscanf(mov, "%[^\n]%*c", new_node->title) != 1 ||
			fscanf(mov, "%f%*c", &new_node->rating) != 1)
		{
			printf("Wrong format.\n");
			exit(1);
		}
		new_node->next = NULL;

		if (head == NULL)
			head = new_node;
		else
		{
			search = head;
			while (search->next != NULL)
			{
				search = search->next;
			}
			search->next = new_node;
		}
	}
	printf("%d items have been read from the file.\n", num);
	fclose(mov);

	return num;
}// read_file

void clear_buffer()
{
	while (getchar() != '\n') 
		continue;
}

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

int input_item(int num)
{
	int item;
	while (1)
	{
		if (scanf("%d", &item) != 1)
		{
			printf("Wrong input. Please try again.\n");
			clear_buffer();
			continue;
		}
		else if (item < 0 || item > num - 1)
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

void print_all_items(int num)
{
	search = head;
	for (int i = 0; i < num; ++i)
	{
		printf("%d : %s\t%.1f\n", i, search->title, search->rating);
		search = search->next;
	}
}

void search_and_print_item(int num)
{
		printf("Input the index of item to print.\n>>");

		int item = input_item(num);

		search = head;
		for (int i = 0; i < item; ++i)
		{
			search = search->next;
		}
		printf("%s\n%.1f", search->title, search->rating);
}

void edit_an_item(int num)
{
	printf("Input the index of item to edit.\n>>");

	int item = input_item(num);

	search = head;
	for (int i = 0; i < item; ++i)
	{
		search = search->next;
	}
	printf("Input new title and press enter.\n>>");
	int flag = scanf("%[^\n]%*c", search->title);
	printf("Input new rating and press enter.\n>>");
	flag = scanf("%f", &search->rating);
}

void add_an_item(int* num)
{
	search = head;
	new_node = (list*)malloc(sizeof(list));
	if (new_node == NULL)
	{
		printf("ERROR: malloc failed.\n");
		exit(1);
	}
	if (head == NULL)
		head = new_node;
	else
	{
		while (search->next != NULL)
		{
			search = search->next;
		}
		search->next = new_node;
	}
	new_node->next = NULL;
	printf("Input title and press enter.\n>>");
	int flag = scanf("%[^\n]%*c", new_node->title);
	printf("Input rating and press enter.\n>>");
	flag = scanf("%f", &new_node->rating);
	(*num)++;
	printf("%d : %s\t%.1f\n", (*num) - 1, new_node->title, new_node->rating);
}

void insert_an_item(int* num)
{
	int item;
	printf("Input the index of item to insert.\n>>");
	item = input_item(*num);
	search = head;
	new_node = (list*)malloc(sizeof(list));
	if (new_node == NULL)
	{
		printf("ERROR: malloc failed.\n");
		exit(1);
	}
	printf("Input title and press enter.\n>>");
	int flag = scanf("%[^\n]%*c", new_node->title);
	printf("Input rating and press enter.\n>>");
	flag = scanf("%f", &new_node->rating);
	if (item == 0)
	{
		list* temp = head;
		head = new_node;
		new_node->next = temp;
	}
	else
	{
		list* prev = search;
		for (int i = 0; i < item; ++i)
		{
			prev = search;
			search = search->next;
		}
		prev->next = new_node;
		new_node->next = search;
	}
	(*num)++;
}

void delete_an_item(int* num)
{
	int item;
	printf("Input the index of item to delete.\n>>");
	item = input_item(*num);
	search = head;
	list* temp = NULL;
	temp = head;
	if (item == 0)
	{
		head = head->next;
		free(search);
	}
	else
	{
		for (int i = 0; i < item; ++i)
		{
			temp = search;
			search = search->next;
		}
		temp->next = search->next;
		free(search);
	}
	(*num)--;
}

void delete_all_items(int* num)
{
	char c;
	printf("Are you sure?(y/n)\n");
	if (scanf("%c%*c", &c) != 1)
	{
		printf("Wrong input\n.");
		return;
	}
	else if (c == 'y')
	{
		*num = 0;
		while (search != NULL)
		{
			search = head->next;
			free(head);
			head = search;
		}
		head = NULL;
	}
	else
		return;
}

void save_file(int* num)
{
	FILE* fw;
	char filename_save[STRLEN] = {'\0'};
	printf("Please input filename to save.\n>>");
	int flag = scanf("%[^\n]%*c", filename_save);
	fw = fopen(filename_save, "w");
	if (fw == NULL)
	{
		printf("Save failed.\n");
		exit(1);
	}
	fprintf(fw, "%d\n", *num);
	search = head;
	while (search != NULL)
	{
		fprintf(fw, "%s\n%.1f\n", search->title, search->rating);
		search = search->next;
	}
	fclose(fw);
}

void search_by_name()
{
	int count = 0;
	bool find = true;
	search = head;
	char search_name[STRLEN] = {'\0'};
	printf("Input title to search.\n>>");
	int flag = scanf("%[^\n]%*c", search_name);
	while (strcmp(search_name, search->title) != 0)
	{
		if (search->next == NULL)
		{
			find = false;
			break;
		}
		search = search->next;
		count++;
	}
	if (find == false)
	{
		printf("Cannot find title.\n");
		return;
	}
	else
	{
		printf("%d : %s\t %.1f\n", count, search->title, search->rating);
		return;
	}
}

int main()
{
	int index;
	int num;

	num = read_file();
	while (1)
	{
		index = select_index();

		switch (index)
		{
		case (1):
			print_all_items(num);
			break;
		case (2):
			search_and_print_item(num);
			break;
		case (3):
			edit_an_item(num);
			break;
		case (4):
			add_an_item(&num);
			break;
		case (5):
			insert_an_item(&num);
			break;
		case (6):
			delete_an_item(&num);
			break;
		case (7):
			delete_all_items(&num);
			break;
		case (8):
			save_file(&num);
			break;
		case (9):
			search_by_name();
			break;
		case (10):
			printf("Good bye.\n");
			delete_all_items(&num);
			exit(0);
		}//switch
	}//while
	return 0;
}// main