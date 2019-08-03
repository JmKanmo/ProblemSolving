#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SingleLinkedList.h"

void Init_List(void)
{
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	temp = (Node*)malloc(sizeof(Node));
	head->Next = tail;
	tail->Next = NULL;
	temp->Next = head;
}//End of Init_Node()

void Insert_Node(Node*node)
{
	Node*back = head;
	Node*front = head->Next;
	Node*circul = front;

	while (circul->Next != NULL)
	{
		if (node->age < circul->age)
		{
			back->Next = node;
			node->Next = front;
			return;
		}
		back = back->Next;
		front = front->Next;
		circul = circul->Next;
	}//while(i)

	temp->Next->Next = node;
	node->Next = tail;
	temp->Next = node;
}//End of Insert_Node()

void Circulate_List(void)
{
	Node*one_Node = head->Next;

	while (one_Node->Next != NULL)
	{
		printf("이름:%s\n", one_Node->Name);
		printf("나이:%d\n", one_Node->age);
		puts("\n");
		one_Node = one_Node->Next;
	}//while(i)
	puts("\n");
}//End of Circulate_List()

int Delete_Node(int age,char name[])
{
	Node*del_Node;
	Node*back = head;
	Node*front = head->Next;

	while (front->Next != NULL)
	{
		if (front->age == age && strcmp(front->Name, name) == 0)
		{
			del_Node = front;
			back->Next = front->Next;
			free(del_Node);
			return 1;
		}
		front = front->Next;
		back = back->Next;
	}//while(i)
	return 0;
}//End of Delete_Node()

