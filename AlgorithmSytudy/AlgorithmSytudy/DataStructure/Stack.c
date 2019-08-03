#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void InitStack(Stack*st)
{
	st->top = NULL;
}//End of InitStack()

int IsEmptyStack(Stack*st)
{
	return st->top == NULL ? TRUE : FALSE;
}//End of IsEmptyStack()

void Push(Stack*st, DType data)
{
	Node*newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (IsEmptyStack(&st))
	{
		st->top = newNode;
	}
	else
	{
		newNode->next = st->top;
		st->top = newNode;
	}
}//End of Push()

DType Pop(Stack*st)
{
	Node*delNode = NULL;
	DType delData;

	if (IsEmptyStack(&st))
	{
		printf("스택이 비었음\n");
		exit(1);
	}
	else
	{
		delNode = st->top;
		st->top = st->top->next;
		delData = delNode->data;
		free(delNode);
		return delData;
	}
}//End of Pop()

DType Peek(Stack*st)
{	
	if (IsEmptyStack(&st))
	{
		printf("스택이 비었음\n");
		exit(1);
	}
	else
		return st->top->data;
}//End of Peek()