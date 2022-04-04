#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define STRLEN 40

struct movie {
	char title[STRLEN];
	unsigned int year;
};

typedef struct movie Element;

typedef struct node {
	Element item;
	struct node* next;
}Node;

typedef struct list {
	Node* head;		// head pointer
	int size;		// number of items
}List;

void InitializeList(List* plist);
bool IsEmpty(const List* plist);
bool IsFull(const List* plist);
bool AddItem(List* plist, Element item);
void InsertbyIndex(Element item, List* plist, int index);
void RemoveByIndex(List* plist, int index);
bool InsertItemFront(Element item, List* plist);
bool AppendItem(Element item, Node* prev);
bool Find(const List* plist, Element item_to_find, int* index, Element* item_found, bool (*compare_func)(Element a, Element b));
unsigned int CountItems(const List* plist);
unsigned int PrintAllItems(List* plist, void (*print_an_item_func)(Element item));
unsigned int WriteAllItems(const List* plist, FILE* file, void (*write_an_item_func)(FILE* file, Element item));
void Traverse(const List* plist, void (*pfun)(Element item));
void ClearList(List* plist);
bool FindItemByIndex(const List* plist, const int index, Element** item);
void RemoveFirstItem(List* plist);
void RemoveNextItem(Node* prev);
unsigned int FindAndRun(const List* plist, Element item_to_find,
	bool (*compare_func)(Element a, Element b), void (*func_run)(Element item));