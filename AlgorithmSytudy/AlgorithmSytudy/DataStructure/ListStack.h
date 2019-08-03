#ifndef __LISTSTACK__H
#define __LISTSTACK__H

#define TRUE 1
#define FALSE 0

typedef char Data;

typedef struct _ListStack
{
	Data data;
	struct _ListStack* next;
}ListStack;

typedef ListStack Stack;

Stack*head;

void Init_LS(void);
int IsEmpty_LS(void);
void Push_LS(Data);
Data Pop_LS(void);
Data Peek_LS(void);

#endif