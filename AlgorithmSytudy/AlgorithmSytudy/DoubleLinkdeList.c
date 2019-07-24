#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "DoubleLinkedList.h"

void Init_List(void)
{
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->prev = NULL;
	head->next = tail;
	tail->prev = head;
	tail->next = NULL;
}//End of Init_List()

void Insert_Node(Node* node)
{   
	if (head->next == tail)
	{
		head->next = node;
		node->prev = head;
		node->next = tail;
		tail->prev = node;
	}
	else {
		if (node->age < head->next->age)
		{
			node->prev = head;
			node->next = head->next;
			head->next->prev = node;
			head->next = node;
		}
		else if (node->age > tail->prev->age)
		{
			node->next = tail;
			node->prev = tail->prev;
			tail->prev->next = node;
			tail->prev = node;
		}
		else
		{
			Node*temp = abs(head->next->age - node->age) < abs(tail->prev->age - node->age) ? head->next : tail->prev;

			if (temp->age < node->age)
			{
				while (temp->age <= node->age)
				{
					if (temp->age == node->age)
					{
						if (strcmp(node->name, temp->name) < 0)
						{
							node->prev = temp->prev;
							node->next = temp;
							temp->prev->next = node;
							temp->prev = node;
							return;
						}
					}
					temp = temp->next;
				}//while(i)
				node->prev = temp->prev;
				node->next = temp;
				temp->prev->next = node;
				temp->prev = node;
			}
			else
			{
				while (temp->age >= node->age)
				{
					if (temp->age == node->age)
					{
						if (strcmp(node->name, temp->name) > 0)
						{
							node->prev = temp;
							node->next = temp->next;
							temp->next->prev = node;
							temp->next = node;
							return;
						}
					}
					temp = temp->prev;
				}//while(i)	
				node->prev = temp;
				node->next = temp->next;
				temp->next->prev = node;
				temp->next = node;
			}//if-else
		}//if-else if-else
	}//if-else
}//End of Insert_Node()

	void Circulate_Node(void)
	{
		if (head->next == tail)
		{
			printf("리스트에 노드가없음\n\n");
			return;
		}

		Node* temp = NULL;

		int sel;
		printf("\n순회방향설정 --> [1] - 왼쪽부터 / [2] - 오른쪽부터\n");
		printf("선택:");
		scanf("%d", &sel);

		switch (sel)
		{
		case 1:
			temp = head->next;
			while (temp->next != NULL)
			{
				printf("\n이름: %s\n나이:%d\n\n", temp->name, temp->age);
				temp = temp->next;
			}//while(i)
			break;
		case 2:
			temp = tail->prev;
			while (temp->prev != NULL)
			{
				printf("\n이름: %s\n나이:%d\n\n", temp->name, temp->age);
				temp = temp->prev;
			}//while(i)
			break;
		default:
			printf("\n잘못된입력\n\n");
			return;
		}//switch()
}//End of Circulate_List()

int Delete_Node(int age, char name[])
{
	Node*temp = NULL;
	Node*delNode = NULL;

	if (head->next == tail || age<head->next->age || age>tail->prev->age)
	{
		return 0;
	}
	
	temp = abs(head->next->age - age) < abs(tail->prev->age - age) ? head->next : tail->prev;
	
	if (temp->age < age)
	{
		while (temp->age <= age)
		{
			if (strcmp(name, temp->name) == 0 && age == temp->age)
			{
				delNode = temp;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				free(delNode);
				return 1;
		     }
			temp = temp->next;
		}//while(i)
	}
	else
	{
		while (temp->age >= age)
		{ 
			if (strcmp(name, temp->name) == 0 && age == temp->age)
			{
				delNode = temp;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				free(delNode);
				return 1;
		    } 
			temp = temp->prev;
		}//while(i)
	}//if - else
	return 0;
}//End of Delete_Node()

void deleteAll(void)
{
	Node*temp = head->next;
	Node*delNode = NULL;
	
	while (temp->next != NULL)
	{
		delNode = temp;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		temp = temp->next;
		free(delNode);
	}//while(i)
	free(head);
	free(tail);
}//End of deleteAll()








