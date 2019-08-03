#include <stdio.h>
#include "CircularDoubleLinkedList.h"

void print(char animal[], int level)
{
	printf("\n�̸�: %s \n����: %d\n", animal, level);
}//End of print()

int main(void)
{
	LinkedList list;

	InitList(&list,print);

	InsertNode(&list, "��ī��", 3); InsertNode(&list, "���̸�",3);
	InsertNode(&list, "�źϿ�", 8); InsertNode(&list, "������", 6);
	InsertNode(&list, "�ƺ�ũ", 7); InsertNode(&list, "��",8);
	InsertNode(&list, "����", 15);

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