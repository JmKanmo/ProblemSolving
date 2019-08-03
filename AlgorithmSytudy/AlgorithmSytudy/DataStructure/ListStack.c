#include <stdio.h>
#include <stdlib.h>
#include "ListStack.h"

void Init_LS(void)
{
	head = (Stack*)malloc(sizeof(Stack));
	head->next = NULL;
}//End of Init_Stack()

int IsEmpty_LS(void) { return head->next == NULL ? TRUE : FALSE; }//End of IsEmpty()

void Push_LS(Data data)
{
	Stack*node = (Stack*)malloc(sizeof(Stack));
	node->data = data;
	node->next = head->next;
	head->next = node;
}//End of push()

Data Pop_LS(void)
{
	if (!IsEmpty_LS())
	{
		Stack*PopNode = head->next;
		Data PopData = PopNode->data;
		head->next = head->next->next;
		free(PopNode);
		return PopData;
	}
	return FALSE;
}//End of Pop()

Data Peek_LS(void) { return !IsEmpty_LS() ? head->next->data : FALSE; }//End of Peek_S()