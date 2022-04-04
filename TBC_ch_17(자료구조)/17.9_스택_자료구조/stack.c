#include "stack.h"
#include <stdio.h>

void Initialize(Stack* stack)
{
	stack->top = -1;
	// allocate memory if dynamic array is used
}

bool IsFull(const Stack* stack)
{
	if (stack->top == MAX_STACK_SIZE - 1)
		return true;
	else
		return false;
}

bool IsEmpty(const Stack* stack)
{
	if (stack->top == -1)
		return true;
	else
		return false;
}

void Push(Stack* stack, element item)
{
	if (IsFull(stack) == true)
	{
		printf("Stack if full. Cannot add.\n");
		return;
	}
	//memcpy(&stack->items[++stack->top], &item, sizeof(item));
	stack->top += 1;
	stack->items[stack->top] = item;
}

element Pop(Stack* stack)
{
	if (IsEmpty(stack) == true)
	{
		printf("Stack is empty. Cannot remove.\n");
		element dummy = { -1 };// place holder, dummy
		return dummy;
	}
	return stack->items[stack->top--];
}