#ifndef __LISTQUEUE__H
#define __LISTQUEUE__H

#define TRUE 1
#define FALSE 0

typedef int QData;

typedef struct _Node
{
	QData data;
	struct _Node*next;
}Node;

typedef struct _ListQueue
{
	Node*front;
	Node*rear;
}ListQueue;

typedef ListQueue Queue;

void QueueInit(Queue*);
int QIsEmpty(Queue*);

void EnQueue(Queue*, QData);
QData DeQeueue(Queue*);

#endif