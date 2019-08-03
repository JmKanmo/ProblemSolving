#include <stdio.h>
#include "CircularQueue.h"

void QueueInit(Queue*CQ)
{
	CQ->front = 0;
	CQ->rear = 0;
}//End of QueueInit()

int QIsEmpty(Queue*CQ)
{
	return (CQ->front == CQ->rear) ? TRUE : FALSE;
}//End of QIsEmpty()

int GetNextPos(int pos)
{
	return (pos == ARRAY_LEN - 1) ? 0 : pos + 1;
}//End of GetNextPos()

void EnQueue(Queue*CQ, Data data)
{
	if (CQ->front == GetNextPos(CQ->rear))
	{
		printf("큐가꽉찼음\n");
		return;
	}
	CQ->rear = GetNextPos(CQ->rear);
	CQ->arr[CQ->rear] = data;
}//End of EnQueue()

Data DeQueue(Queue*CQ)
{
	if (QIsEmpty(CQ))
	{
		printf("큐가비었음\n");
		return -999;
	}
	CQ->front = GetNextPos(CQ->front);
	return CQ->arr[CQ->front];
}//End of DeQueue()

Data QPeek(Queue*CQ)
{
	if(QIsEmpty(CQ))
	{
		printf("큐가비었음\n");
		return -999;
	}
	return CQ->arr[GetNextPos(CQ->front)];
}//End of QPeek()