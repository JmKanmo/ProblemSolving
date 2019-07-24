#ifndef QUEUE__H
#define QUEUE__H

#define TRUE 1
#define FALSE 0

#define QUEUE_LEN 10

typedef int QData;

typedef struct _Queue
{
	QData arr[QUEUE_LEN];
	int front;
	int rear;
	int toggle;
}Queue;

void InitQ(Queue*);
int IsEmptyQ(Queue*);
void EnQueue(Queue*, QData);
QData DeQueue(Queue*);
QData PeekQ(Queue*);

#endif