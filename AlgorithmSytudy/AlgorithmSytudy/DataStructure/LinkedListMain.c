#include <stdio.h>
#include "CircularDoubleLinkedList.h"

void print(char animal[], int level)
{
	printf("\nÀÌ¸§: %s \n·¹º§: %d\n", animal, level);
}//End of print()

int main(void)
{
	LinkedList list;

	InitList(&list,print);

	InsertNode(&list, "ÇÇÄ«Ãò", 3); InsertNode(&list, "ÆÄÀÌ¸®",3);
	InsertNode(&list, "°ÅºÏ¿Õ", 8); InsertNode(&list, "ÇÇÁ¸Åõ", 6);
	InsertNode(&list, "¾Æº¸Å©", 7); InsertNode(&list, "¹Â",8);
	InsertNode(&list, "¹ÂÃ÷", 15);

	traversalList(&list);
	traversalList(&list);

	DeleteNode(&list); DeleteNode(&list);
	DeleteNode(&list); DeleteNode(&list);

	traversalList(&list);
	traversalList(&list);

	while (!IsEmptyList(&list))
		DeleteNode(&list);

	return 0;
}//End of main()