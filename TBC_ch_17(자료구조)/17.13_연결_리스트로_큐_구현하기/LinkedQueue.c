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
// ���ο����� ����� �� �ְ�. main�Լ������� �ڼ��� ������ �ִ��� �Ⱥ��̵���
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
	return pq->n_items; //�迭�� �� �����Ǿ��ֱ� ������ �ϳ��� ���� �۾��� ���� ��������,
}				// hip�� ����� �޸𸮸� �����ͷ� ���󰡴� linkedlist�� �Ź� ���°��� ȿ���� ������.

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