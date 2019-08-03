#ifndef __LDEQUE__H
#define __LDEQUE__H

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _Node
{
	Data data;
	struct _Node*prev;
	struct _Node*next;
}Node;

typedef struct _Deque
{
	Node*head;
	Node*tail;
}Deque;

void DequeInit(Deque*dq);
int DQIsEmpty(Deque*dq);

void DQAddFirst(Deque*dq, Data data);
void DQAddLast(Deque*dq, Data data);

Data DQRemoveFirst(Deque*dq);
Data DQRemoveLast(Deque*dq);

Data DQPeekFirst(Deque*dq);
Data DQPeekLast(Deque*dq);


#endif