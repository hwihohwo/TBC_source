#pragma once
#include <stdio.h>
#include <stdbool.h>

#define STRLEN 40
#define MAX 8

typedef struct element {
	char name[STRLEN];
}Element;

typedef struct queue {
	Element item[MAX];
	int front;
	int rear;
} Queue;

void Initialize(Queue* queue);
bool EnQueue(Queue* queue, const Element item, void (*input_item_func)(Queue* queue, Element item));
bool DeQueue(Queue* queue, void (*remove_item_func)(Queue* queue));
bool IsFull(const Queue * queue);
bool IsEmpty(const Queue * queue);
void PrintAll(const Queue * queue, void (*print_an_item_func)(Element item));