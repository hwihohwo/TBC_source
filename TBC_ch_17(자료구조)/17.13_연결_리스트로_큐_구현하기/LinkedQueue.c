#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkedQueue.h"

static void CopyToNode(Item item, Node* pn)
{
	pn->item = item;
}

static void CopyToItem(Node* pn, Item* pi)
{
	*pi = pn->item;
}
// 내부에서만 사용할 수 있게. main함수에서는 자세한 구조를 최대한 안보이도록
void InitializeQueue(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->n_items = 0;
}

bool QueueIsFull(const Queue* pq)
{
	return pq->n_items == MAXITEMS;
}

bool QueueIsEmpty(const Queue* pq)
{
	return pq->n_items == 0;
}

int QueueItemCount(const Queue* pq)
{
	return pq->n_items; //배열은 쭉 나열되어있기 때문에 하나씩 세도 작업이 비교적 빠르지만,
}				// hip에 저장된 메모리를 포인터로 따라가는 linkedlist는 매번 세는것은 효율이 떨어짐.

bool EnQueue(Item item, Queue* pq)
{
	if (QueueItemCount(pq) >= MAXITEMS)
	{
		printf("Queue is full. Cannot enqueue.\n");
		return false;
	}
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		printf("Malloc failed.\n");
		exit(1);
	}
	new_node->item = item;
	new_node->next = NULL;
	if (pq->front == NULL)
		pq->front = new_node;
	else
		pq->rear->next = new_node;
	pq->rear = new_node;
	pq->n_items++;
	return true;
}

bool DeQueue(Item* item, Queue* pq)
{
	if (QueueIsEmpty(pq) == true)
	{
		printf("Queue is already empty.\n");
		return false;
	}
	Node* temp = pq->front;
	*item = temp->item;
	pq->front = pq->front->next;
	if (pq->front == NULL)
		pq->rear = NULL;
	free(temp);
	pq->n_items--;
	return true;
}

void EmptyTheQueue(Queue* pq)
{
	Node* temp = pq->front;
	while (pq->front != NULL)
	{
		pq->front = pq->front->next;
		free(temp);
		temp = pq->front;
	}
	InitializeQueue(pq);
}

void TraverseQueue(Queue* pq, void (*func)(Item item))
{
	Node* temp = pq->front;
	while (temp != NULL)
	{
		(*func)(temp->item);
		temp = temp->next;
	}
}