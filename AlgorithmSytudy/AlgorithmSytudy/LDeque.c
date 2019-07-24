#include <stdio.h>
#include <stdlib.h>
#include "LDeque.h"

void DequeInit(Deque*dq)
{
	dq->head = NULL;
	dq->tail = NULL;
}//End of DequeInit()

int DQIsEmpty(Deque*dq)
{
	return dq->head == NULL || dq->tail == NULL ? TRUE : FALSE;
}//End of DQIsEmpty()

void DQAddFirst(Deque*dq, Data data)
{
	Node*newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->data = data;

	if (DQIsEmpty(dq))
	{
		dq->head = newNode;
		dq->tail = dq->head;
	}
	else
	{
		newNode->next = dq->head;
		dq->head->prev = newNode;
		dq->head = newNode;
	}
}//End of DQAddFirst()

void DQAddLast(Deque*dq, Data data)
{
	Node*newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->data = data;

	if (DQIsEmpty(dq))
	{
		dq->head = newNode;
		dq->tail = dq->head;
	}
	else
	{
		newNode->prev = dq->tail;
		dq->tail->next = newNode;
		dq->tail = newNode;
	}
}//End of DQAddLast()

Data DQRemoveFirst(Deque*dq)
{
	if (DQIsEmpty(dq))
	{
		printf("\t덱이 비어있음\n");
		exit(1);
	}
	else
	{
		Node*delNode = dq->head;
		Data data = delNode->data;
		dq->head = dq->head->next;
		if (dq->head == NULL) dq->tail = NULL;
		else dq->head->prev = NULL;
		free(delNode);
		return data;
	}
}//End of DQRemoveFirst()

Data DQRemoveLast(Deque*dq)
{
	if (DQIsEmpty(dq))
	{
		printf("\t덱이 비어있음\n");
		exit(1);
	}
	else
	{
		Node*delNode = dq->tail;
		Data data = delNode->data;
		dq->tail = dq->tail->prev;
		if (dq->tail == NULL) dq->head = NULL;
		else dq->tail->next = NULL;
		free(delNode);
		return data;
	}
}//End of DQRemoveLast()

Data DQPeekFirst(Deque*dq)
{
	if (DQIsEmpty(dq))
	{
		printf("\t덱이 비어있음\n");
		exit(1);
	}
	return dq->head->data;
}//End of DQPeekFirst()

Data DQPeekLast(Deque*dq)
{
	if (DQIsEmpty(dq))
	{
		printf("\t덱이 비어있음\n");
		exit(1);
	}
	return dq->tail->data;
}//End of DQPeekLast()
