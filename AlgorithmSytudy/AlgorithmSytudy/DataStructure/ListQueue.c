#include <stdio.h>
#include <stdlib.h>
#include "ListQueue.h"

void QueueInit(Queue*q)
{
	q->front = NULL;
	q->rear = NULL;
}//End of QueueInit()

int QIsEmpty(Queue*q)
{
	return q->front == NULL ? TRUE : FALSE;
}//End of QIsEmpty()

void EnQueue(Queue*q, QData data)
{
	Node*pNode = (Node*)malloc(sizeof(Node));
	pNode->data = data;
	pNode->next = NULL;

	if (QIsEmpty(q))
	{
		q->front = pNode;
		q->rear = q->front;
	}
	else
	{
		q->rear->next = pNode;
		q->rear = q->rear->next;
	}
}//End of EnQueue()

QData DeQeueue(Queue*q)
{
	if (QIsEmpty(q))
	{
		printf("큐가 비어있음.\n");
		exit(1);
	}
	
	QData delData;
	Node*delNode = q->front;

	q->front = q->front->next;
	delData = delNode->data;
	free(delNode);
	return delData;
}//End of DeQueue()