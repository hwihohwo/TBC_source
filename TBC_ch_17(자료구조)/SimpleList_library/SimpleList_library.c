
#include "pch.h"
#include "framework.h"

// TODO: This is an example of a library function
#include <stdio.h>
#include <stdlib.h>
#include "SimpleList.h"

static void CopyToNode(Element item, Node* pnode)
{
	pnode->item = item;
}

void InitializeList(List* plist)
{
	plist->head = NULL;
}

bool IsEmpty(const List* plist)
{
	if (plist->head == NULL)
		return true;
	else
		return false;
}

bool IsFull(const List* plist)
{
	// true when malloc fails

	Node* pt;
	bool full;

	pt = (Node*)malloc(sizeof(Node));
	if (pt == NULL)
		full = true;
	else
		full = false;
	free(pt);

	return full;
}

bool AddItem(List* plist, Element item)
{
	Node* new_node;
	Node* search = plist->head;

	new_node = (Node*)malloc(sizeof(Node));

	if (new_node == NULL)
	{
		printf("Malloc failed.\n");
		return false;
	}

	CopyToNode(item, new_node);

	new_node->next = NULL;

	if (search == NULL)
		plist->head = new_node;
	else
	{
		while (search->next != NULL)
			search = search->next;
		search->next = new_node;
	}

	return true;
}

unsigned int CountItems(const List* plist)
{
	Node* search = NULL;
	unsigned int count = 0;
	search = plist->head;
	while (search != NULL)
	{
		search = search->next;
		count++;
	}
	return count;
}

bool InsertItemFront(Element item, List* plist)
{
	Node* new_node;
	new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		printf("Malloc failed.\n");
		return false;
	}
	CopyToNode(item, new_node);
	Node* temp = plist->head;
	plist->head = new_node;
	new_node->next = temp;
	return true;
}

bool AppendItem(Element item, Node* prev)
{
	Node* new_node;
	new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		printf("Malloc failed.\n");
		return false;
	}
	CopyToNode(item, new_node);
	Node* temp = prev->next;
	prev->next = new_node;
	new_node->next = temp;
	return true;
}



unsigned int WriteAllItems(const List* plist, FILE* file, void (*write_an_item_func)(FILE* file, Element item))
{
	Node* search = plist->head;
	unsigned int count = 0;
	while (search != NULL)
	{
		(*write_an_item_func)(file, search->item);
		search = search->next;
		count++;
	}
	return count;
}

unsigned int PrintAllItems(List* plist, void (*print_an_item_func)(Element item))
{
	Node* search = NULL;
	unsigned int count = 0;
	search = plist->head;
	while (search != NULL)
	{
		printf("%d : ", count);
		(*print_an_item_func)(search->item);
		search = search->next;
		count++;
	}
	return count;
}

void Traverse(const List* plist, void (*pfun)(Element item))
{
	Node* search = NULL;
	search = plist->head;
	while (search != NULL)
	{
		(*pfun)(search->item);
		search = search->next;
	}
}

bool Find(const List* plist, Element item_to_find, int* index, Element* item_found, bool (*compare_func)(Element a, Element b))
{
	Node* pnode = plist->head;
	*index = 0;
	while (pnode != NULL)
	{
		if ((*compare_func)(item_to_find, pnode->item) == true)
		{
			*item_found = pnode->item;
			return true;
		}
		pnode = pnode->next;
		(*index)++;
	}
	return false;
}

Node* FindNodeByIndex(const List* plist, const int index)
{
	Node* pnode = plist->head;
	int count = 0;
	while (pnode != NULL)
	{
		if (count == index) break;

		pnode = pnode->next;
		count++;
	}
	return pnode;
}

void InsertbyIndex(Element item, List* plist, int index)
{
	Node* prev = FindNodeByIndex(plist, index - 1);

	if (prev == NULL) // when index is 0
		InsertItemFront(item, plist);
	else
		AppendItem(item, prev);
}

void ClearList(List* plist)
{
	Node* iterator = plist->head;
	Node* temp;

	while (iterator != NULL)
	{
		temp = iterator->next;
		free(iterator);
		iterator = temp;
	}

	plist->head = NULL;
}


bool FindItemByIndex(const List* plist, const int index, Element** item)
{
	Node* pnode = plist->head;

	int count = 0;

	while (pnode != NULL)
	{
		if (count == index) break;

		pnode = pnode->next;
		count++;
	}

	if (pnode == NULL)
		return false;
	else
	{
		*item = &pnode->item;
		return true;
	}
}

void RemoveFirstItem(List* plist)
{
	Node* temp = NULL;
	if (plist->head != NULL)
		temp = plist->head->next;
	free(plist->head);
	plist->head = temp;
}

void RemoveNextItem(Node* prev)
{
	Node* temp = NULL;
	if (prev->next == NULL)
		temp = NULL;
	else
		temp = prev->next->next;
	free(prev->next);
	prev->next = temp;
}

void RemoveByIndex(List* plist, int index)
{
	Node* prev = FindNodeByIndex(plist, index - 1);

	if (prev == NULL) // when index is 0
		RemoveFirstItem(plist);
	else
		RemoveNextItem(prev);
}

unsigned int FindAndRun(const List* plist, Element item_to_find,
	bool (*compare_func)(Element a, Element b), void (*func_run)(Element item))
{
	Node* pnode = plist->head;

	int count = 0;
	while (pnode != NULL)
	{
		if ((*compare_func)(pnode->item, item_to_find) == true)
			(*func_run)(pnode->item);

		pnode = pnode->next;
		count += 1;
	}

	return count;
}
