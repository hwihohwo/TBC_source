#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stack.h"

#define WIDTH 7
#define HEIGHT 7

static int map[HEIGHT][WIDTH] = {	// 0: empty, 1: full
							0, 0, 0, 0, 0, 0, 0,
							0, 1, 1, 1, 1, 1, 0,
							0, 1, 0, 0, 0, 1, 0,
							0, 1, 0, 0, 0, 1, 0,
							0, 1, 0, 0, 0, 1, 0,
							0, 1, 1, 1, 1, 1, 0,
							0, 0, 0, 0, 0, 0, 0,
};

void print_map()
{
	for (int j = 0; j < HEIGHT; ++j)
	{
		for (int i = 0; i < WIDTH; ++i)
			printf("%d ", map[j][i]);
		printf("\n");
	}
	printf("\n");
}

element get_element(const int j, const int i)
{
	element new_element;
	new_element.i = i;
	new_element.j = j;
	return new_element;
}

void print_stack(const Stack* stack)
{
	printf("Stack : ");
	if (IsEmpty(stack) == true)
		printf("Empty");
	else
		for (int i = 0; i <= stack->top; ++i)
			printf("(%d, %d) ", stack->items[i].i, stack->items[i].j);
	printf("\n");
}

int main()
{
	print_map();

	Stack to_visit;
	Initialize(&to_visit);

	//Push(&to_visit, get_element(0, 0));// start cell
	Push(&to_visit, get_element(3, 3));// start cell
	print_stack(&to_visit);

	while (IsEmpty(&to_visit) != true)
	{
		element cell = Pop(&to_visit);
		if (map[cell.j][cell.i] == 0)
			map[cell.j][cell.i] = 1;

		if (cell.j > 0 && map[cell.j - 1][cell.i] != 1)
			Push(&to_visit, get_element(cell.j - 1, cell.i)); // Push up
		if (cell.j < (HEIGHT - 1) && map[cell.j + 1][cell.i] != 1)
			Push(&to_visit, get_element(cell.j + 1, cell.i)); // Push down
		if (cell.i > 0 && map[cell.j][cell.i - 1] != 1)
			Push(&to_visit, get_element(cell.j, cell.i - 1)); // Push left
		if (cell.i < (WIDTH - 1) && map[cell.j][cell.i + 1] != 1)
			Push(&to_visit, get_element(cell.j, cell.i + 1)); // Push right

		// Debugging
		system("cls"); // system("clear"); in linux
		print_stack(&to_visit);
		printf("Cell : (%d, %d)\n", cell.j, cell.i);
		print_map();
		int dummy = _getch();
	}

	printf("Result:\n");
	print_map();

	return 0;
}