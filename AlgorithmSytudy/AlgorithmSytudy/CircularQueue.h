#ifndef __CIRCULAR__QUEUE__H
#define __CIRCULAR__QUEUE__H

#define TRUE 1
#define FALSE 0

#define ARRAY_LEN 100

typedef int Data;

typedef struct _C_Queue
{
	Data arr[ARRAY_LEN];
	int front;
	int rear;
}C_Queue;

typedef C_Queue Queue;

void QueueInit(Queue*CQ);
int QIsEmpty(Queue*CQ);

void EnQueue(Queue*CQ, Data data);
Data DeQueue(Queue*CQ);
Data QPeek(Queue*CQ);

#endif 