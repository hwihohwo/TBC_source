#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define STRLEN 40 //name length
#define MAXNUM 40 //max number

int input_int()
{
	int input;

	while (1)
	{
		printf(">> ");
		if (scanf("%d%*c", &input) == 1) return input;
		else
		{
			printf("Please input an integer and press enter. Try again.\n");
			while (getchar() != '\n') continue;
		}
	}
}

void clear_buffer()
{
	while (getchar() != '\n')
		continue;
}

struct mov_rate {
	char mov_name[STRLEN];
	double mov_rate;
};

int main()
{
	struct mov_rate list[MAXNUM];
	FILE* mov_list = NULL;
	char filename[STRLEN] = { '\0' };
	char filename2[STRLEN] = { '\0' };
	char str_search[STRLEN] = { '\0' };
	bool search_result = false;
	int num = 0; // size_t를 사용하는게 좀 더 정밀함.
	int option = 0;
	int mov_index = 0;
	char c;

	printf("Please input filename to read and press Enter.\n>>");

	int flag = scanf("%s%*c", filename);

	if ((mov_list = fopen(filename, "r+")) == NULL)
	{
		printf("ERROR: Cannot open file.");
		exit(1);
	}

	if (fscanf(mov_list, "%d%*c", &num) != 1)
	{
		printf("ERROR: Wrong file format.");
		exit(1);
	}

	printf("%d items have been read from the file.\n", num);

	for (int i = 0; i < num; ++i)
	{
		if (fscanf(mov_list, "%[^\n]%*c", list[i].mov_name) != 1 ||
			fscanf(mov_list, "%lf%*c", &list[i].mov_rate) != 1)
		{
			printf("ERROR: Wrong file format.\n");
			exit(1);
		}
	}

	while (1)
	{
		printf("\nPlease select an option and press enter.\n");
		printf("1. Print all items\t2. Print an item\n");
		printf("3. Edit an item\t\t4. Add an item\n");
		printf("5. Insert an item\t6. Delete an item\n");
		printf("7. Delete all items\t8. Save file\n");
		printf("9. Search by name\t10. Quit\n>>");

		flag = scanf("%d", &option);

		clear_buffer(); //buffer check항상 신경쓸것.

		if (option < 1 || option > 10)
		{
			printf("Invalid item");
			continue;
		}

		switch (option)
		{
		case (1):
			for (int i = 0; i < num; ++i)
				fprintf(stdout, "%d : \"%s\", %.1lf\n", i, list[i].mov_name, list[i].mov_rate);
			break; //case(1) end

		case (2):

			while (1)
			{
				printf("Input the index of item to print.\n>>");
				flag = scanf("%d", &mov_index);
				clear_buffer();
				if (mov_index < 0 || mov_index > num)
				{
					printf("Wrong index.\n");
					clear_buffer();
					continue;
				}
				fprintf(stdout, "%d : \"%s\", %.1lf\n", mov_index, list[mov_index].mov_name, list[mov_index].mov_rate);
				break;
			}// case 2 while
			break; //case(2) end

		case (3):

			while (1)
			{
				printf("Input the index of item to edit.\n>>");
				flag = scanf("%d", &mov_index);
				clear_buffer();
				if (mov_index < 0 || mov_index > num)
				{
					printf("Wrong index.\n");
					continue;
				}
				printf("Input new title and press enter.\n>>");
				flag = fscanf(stdin, "%[^\n]%*c", list[mov_index].mov_name);
				printf("Input new rating and press enter.\n>>");
				flag = fscanf(stdin, "%lf%*c", &list[mov_index].mov_rate);
				break;
			}// case(3) while
			break; //case(3) end

		case (4):
			if (num == MAXNUM)
			{
				printf("No more space.\n");
				continue;
			}
			num++;
			printf("Input title and press enter.\n>>");
			flag = fscanf(stdin, "%[^\n]%*c", list[num - 1].mov_name);
			printf("Input rating and press enter.\n>>");
			flag = fscanf(stdin, "%lf%*c", &list[num - 1].mov_rate);
			break; //case(4) end

		case (5):
			if (num == MAXNUM)
			{
				printf("No more space.\n");
				continue;
			}
			num++;
			while (1)
			{
				printf("Input the index of item to insert.\n>>");
				flag = scanf("%d", &mov_index);
				clear_buffer();
				//memmove(&list[mov_index + 1], &list[mov_index],
				//	sizeof(struct mov_rate) * (num - mov_index));
				if (mov_index < 0 || mov_index > num)
				{
					printf("Wrong index.\n");
					continue;
				}
				for (int i = num - 1; i > mov_index; --i)
				{
					strcpy(list[i].mov_name, list[i - 1].mov_name);
					list[i].mov_rate = list[i - 1].mov_rate;
				}
				printf("Input new title and press enter.\n>>");
				flag = fscanf(stdin, "%[^\n]%*c", list[mov_index].mov_name);
				printf("Input new rating and press enter.\n>>");
				flag = fscanf(stdin, "%lf%*c", &list[mov_index].mov_rate);
				break;
			} // case (5) while
			break;// case(5) end

		case (6):
			while (1)
			{
				printf("Input the index of item to delete.\n>>");
				flag = scanf("%d", &mov_index);
				clear_buffer();
				//memmove(&list[mov_index], &list[mov_index + 1],
					//	sizeof(struct mov_rate) * (num - mov_index));
				if (mov_index < 0 || mov_index > num)
				{
					printf("Wrong index.\n");
					continue;
				}
				for (int i = mov_index; i < num; ++i)
				{
					strcpy(list[i].mov_name, list[i + 1].mov_name);
					list[i].mov_rate = list[i + 1].mov_rate;
				}
				num--;
				break;
			}// case (6) while
			break; // case (6) end

		case (7):
			printf("Delete all items?(press y to delete)\n>>");
			flag = scanf("%c%*c", &c);
			if (c == 'y')
			{
				for (int i = 0; i < num; ++i)
				{
					for (int j = 0; j < STRLEN; ++j)
						list[i].mov_name[j] = '\0';
					list[i].mov_rate = 0;
				}
				num = 0;
			}
			else
				continue;
			break; // case (7) end

		case (8):
			printf("Please input filename to write and press Enter.\n>>");
			if (fscanf(stdin, "%[^\n]%*c", filename2) != 1)
			{
				printf("Wrong input. Termination.\n");
				exit(1);
			}
			FILE* fw = NULL;
			fw = fopen(filename2, "w");
			fprintf(fw, "%d\n", num);
			for (int i = 0; i < num; ++i)
			{
				fprintf(fw, "%s\n%lf\n", list[i].mov_name, list[i].mov_rate);
			}
			printf("%d items have been saved to the file.\n", num);
			fclose(fw);
			break; // case (8) end

		case (9):
			while (1)
			{
				printf("Input title to search and press enter.\n>>");
				flag = scanf("%[^\n]", str_search);
				clear_buffer();
				for (int i = 0; i < num; ++i)
				{
					if (strcmp(list[i].mov_name, str_search) == 0)
					{
						printf("%d : \"%s\", %.1lf\n", i, list[i].mov_name, list[i].mov_rate);
						search_result = true;
						break;
					}
				}
				if (search_result == false)
				{
					printf("Nothing Matched.\n");
					continue;
				}
				break;
			}// case (9) while
			break; // case (9) end

		default:
			printf("Good bye");
			fclose(mov_list);
			exit(0);
		}// switch

	}// while

	return 0;
}// main