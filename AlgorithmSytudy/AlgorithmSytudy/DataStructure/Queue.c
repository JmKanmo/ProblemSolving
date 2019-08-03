#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int GetNextIdx(int idx)
{ 
	return idx + 1 == QUEUE_LEN ? 1 : idx + 1;
}//End of GetNextIdx()

void InitQ(Queue*q)
{
	q->front = 0;
	q->rear = 0;
	q->toggle = FALSE;
}//End of InitQueue()

int IsEmptyQ(Queue*q)
{
	return q->front == q->rear ? TRUE : FALSE;
}//End of IsEmptyQueue()

void EnQueue(Queue*q, QData data)
{
	if (q->toggle && IsEmptyQ(q))
	{
		printf("Å¥°¡ ²ËÃ¡À½\n");
		return;
	}
	else
	{
		if (q->front + 1 == QUEUE_LEN && q->rear == 0)
		{
			printf("Å¥°¡ ²ËÃ¡À½\n");
			return;
		}

		if (GetNextIdx(q->front) == q->rear)
			q->toggle = (!q->toggle);
		 
		q->arr[GetNextIdx(q->front)] = data;
		q->front = GetNextIdx(q->front);
	}
}//End of EnQueue()

QData DeQueue(Queue*q)
{
	QData delData;

	if (IsEmptyQ(q))
	{
		if (q->toggle)
			q->toggle = (!q->toggle);	
		else
		{
			printf("Å¥°¡ ºñ¾úÀ½\n");
			exit(1);
		}
	}
		delData = q->arr[GetNextIdx(q->rear)];
		q->rear = GetNextIdx(q->rear);
		return delData;
}//End of DeQueue()

QData PeekQ(Queue*q)
{
	QData pData;

	if (!q->toggle && IsEmptyQ(q))
	{
		printf("Å¥°¡ ºñ¾úÀ½\n");
		exit(1);
	}
	return q->arr[GetNextIdx(q->rear)];
}//End of PeekQ
