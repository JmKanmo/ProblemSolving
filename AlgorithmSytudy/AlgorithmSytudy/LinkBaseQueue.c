#include <stdio.h>
#include <stdlib.h>
#include "LinkBaseQueue.h"

void QueueInit(QUEUE*LQ)
{
	LQ->front = NULL;
	LQ->rear = NULL;
}//End of QueueInit()

int QIsEmpty(QUEUE*LQ)
{
	return LQ->front == NULL ? TRUE : FALSE;;
}//End of QIsEmpty()

void EnQueue(QUEUE*LQ, Data data)
{
	Node*newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(LQ))
	{
		LQ->front = newNode;
		LQ->rear = LQ->front;
	}
	else 
	{
		LQ->rear->next = newNode;
		LQ->rear = newNode;
	}
}//End of EnQueue()

Data DeQueue(QUEUE*LQ)
{
	if (QIsEmpty(LQ))
	{
		printf("큐가비어있음\n");
		return -999;
	}
	else
	{
		Node*delNode = LQ->front;
		Data data = delNode->data;
		LQ->front = LQ->front->next;
		free(delNode);
		return data;
	}
}//End of DeQueue()

Data QPeek(QUEUE*LQ)
{
	if (QIsEmpty(LQ))
	{
		printf("큐가비어있음\n");
		return -999;
	}
	return LQ->front->data;
}//End of QPeek()