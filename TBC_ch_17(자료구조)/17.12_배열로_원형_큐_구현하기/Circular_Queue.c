#include <stdio.h>
#include "Circular_Queue.h"

void Initialize(Queue* queue)
{
	queue->front = 0;
	queue->rear = 0;
}

void TraverseQueue(Queue* queue, void (*func)(Element element))
{
	for (int i = queue->front; i != queue->rear; i = (i + 1) % MAX)
		(*func)(queue->item[(i + 1) % MAX]);
}

void PrintAll(const Queue * queue, void (*print_an_item_func)(Element item))
{
	int count = queue->front + 1;
	int index = 0;
	while (1)
	{
		printf("%d : ", index);
		(*print_an_item_func)(queue->item[count]);
		count++;
		index++;
		if (count == MAX)
			count = 0;
		if (count == queue->rear + 1)
			break;
	}
	printf("\n");
}

bool EnQueue(Queue* queue, const Element item, void (*input_item_func)(Queue* queue, Element item))
{
	if (IsFull(queue) == true)
		return false;
	if ((queue->rear) + 1 == MAX)
		queue->rear = 0;
	else
		queue->rear++;
	(*input_item_func)(queue, item);
	return true;
}

bool DeQueue(Queue* queue, void (*remove_item_func)(Queue* queue))
{
	if (IsEmpty(queue) == true)
		return false;
	if ((queue->front) + 1 == MAX)
		queue->front = 0;
	else
		queue->front++;
	(*remove_item_func)(queue);
	return true;
}

bool IsFull(const Queue * queue)
{
	if (queue->rear + 1 == MAX && 0 == queue->front)
		return true;
	else if (queue->rear + 1 == queue->front)
		return true;
	else
		return false;
}

bool IsEmpty(const Queue * queue)
{
	if (queue->rear == queue->front)
		return true;
	else
		return false;
}
