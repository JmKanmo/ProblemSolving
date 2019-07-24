#ifndef __LINKBASEQUEUE
#define __LINKBASEQUEUE

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _Node
{
	Data data;
	struct _Node*next;
}Node;

typedef struct LinkQueue
{
	Node*front;
	Node*rear;
}L_QUEUE;

typedef L_QUEUE QUEUE;

void QueueInit(QUEUE*LQ);
int QIsEmpty(QUEUE*LQ);

void EnQueue(QUEUE*LQ, Data data);
Data DeQueue(QUEUE*LQ);
Data QPeek(QUEUE*LQ);

#endif