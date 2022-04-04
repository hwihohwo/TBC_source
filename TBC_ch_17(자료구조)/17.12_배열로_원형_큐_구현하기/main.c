#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Circular_Queue.h"

bool choice_index(int* index)
{
	if (scanf("%d%*c", index) != 1)
	{
		printf("Wrong input.\n");
		return false;
	}
	else if ((*index) < 1 || (*index) > 4)
	{
		printf("Wrong index.\n");
		return false;
	}
	else
		return true;
}

void input_customer_name(Queue* queue, Element item)
{
	strcpy(queue->item[queue->rear].name, item.name);
}

void enqueue_customer(Queue* queue)
{
	Element customer;
	printf("Please input customer's name.\n>>");
	if (scanf("%[^\n]%*c", customer.name) != 1)
		printf("Wrong input.\n");
	else if (EnQueue(queue, customer, input_customer_name) == false)
		printf("Queue is full. Cannot input anymore\n");
	else
		printf("%s added to queue.\n", customer.name);
}

void print_and_remove_item(Queue* queue)
{
	printf("%s removed from queue.\n", queue->item[queue->front].name);
	strcpy(queue->item[queue->front].name, "\0");
}

void dequeue_customer(Queue* queue)
{
	if (DeQueue(queue, print_and_remove_item) == false)
		printf("Queue is already empty.\n");
	else
		printf("Dequeue finished.\n");
}

void print_an_item(Element item)
{
	printf("%s ", item.name);
}

void print_all_customers(Queue* queue)
{
	PrintAll(queue, print_an_item);
}

int main()
{
	Queue waiting;
	Initialize(&waiting);
	for (int i = 0; i < MAX; ++i)
		strcpy(waiting.item[i].name, "\0");
	int index = 0;
	while (1)
	{
		printf("1. Enqueue a customer's name.\n");
		printf("2. Dequeue.\n");
		printf("3. PrintAll.\n");
		printf("4. Exit program.\n>>");
		if (choice_index(&index) == false)
			continue;
		switch (index)
		{
		case (1):
			enqueue_customer(&waiting);
			break;
		case (2):
			dequeue_customer(&waiting);
			break;
		case (3):
			print_all_customers(&waiting);
			break;
		case (4):
			printf("Good bye.\n");
			exit(0);
		}
	}
	return 0;
}
