#ifndef __STACK__H
#define __STACK__H

#define TRUE 1
#define FALSE 0

typedef int DType;

typedef struct _Node
{
	DType data;
	struct _Node*next;
}Node;

typedef struct _Stack
{
	Node*top;
}Stack;

void InitStack(Stack*);
int IsEmptyStack(Stack*);
void Push(Stack*, DType);
DType Pop(Stack*);
DType Peek(Stack*);

#endif