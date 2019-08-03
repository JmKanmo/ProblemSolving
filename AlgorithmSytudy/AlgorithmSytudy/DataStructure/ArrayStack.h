#ifndef __ARRAYSTACK__H
#define __ARRAYSTACK__H

#define TRUE 1
#define FALSE 0
#define STACKSIZE 100

typedef int Data;

typedef struct _ArrayStack
{
	Data arr[STACKSIZE];
	int top_Index;
}ArrayStack;

ArrayStack stack;

void Init_AS(void);
int IsEmpty_AS(void);
void Push_AS(Data);
Data Pop_AS(void);
Data Peek_AS(void);

#endif