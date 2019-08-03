#ifndef CIRCULAR__DOUBLE__LINKED__LIST__H
#define CIRCULAR__DOUBLE__LINKED__LIST__H

#define TRUE 1
#define FALSE 0

typedef struct _Node
{ 
	struct _Node*prev;
	struct _Node*next;
	char animal[30];
	int level;
	char pos[30];
}Node;

typedef void FuncPtr(char[], int);

typedef struct _LinkedList
{
	Node*head;
	Node*tail;
	FuncPtr*fp;
}LinkedList;

void InitList(LinkedList*, FuncPtr);
int IsEmptyList(LinkedList*);
void InsertNode(LinkedList*, char[],int);
int DeleteNode(LinkedList*);
void traversalList(LinkedList*);

#endif