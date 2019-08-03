#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircularDoubleLinkedList.h"

void InitList(LinkedList*list,FuncPtr fp)
{
	list->head = (Node*)malloc(sizeof(Node));
	list->tail = (Node*)malloc(sizeof(Node));
	list->head->next = list->tail;
	list->head->prev = list->tail;
	list->tail->next = list->head;
	list->tail->prev = list->head;
	strcpy(list->head->pos, "head");
	strcpy(list->tail->pos, "tail");
	list->fp = fp;
}//End of InitDList()

int IsEmptyList(LinkedList*list)
{
	return list->head->next == list->tail ? TRUE : FALSE;
}//End of EmptyDList

void InsertNode(LinkedList*list, char animal[], int level)
{
	Node*newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->animal, animal); newNode->level = level;
	strcpy(newNode->pos, "torso");

	if (IsEmptyList(list))
	{
		list->head->next = newNode;
		list->tail->prev = newNode;
		newNode->prev = list->head;
		newNode->next = list->tail;	
	}
	else
	{
		Node*st = NULL;

		if (level <= (list->head->level + list->tail->level) / 2)
		{
			st = list->head->next;

			while (st->level <= level)
				st = st->next;

			st->prev->next = newNode;
			newNode->prev = st->prev;
			st->prev = newNode;
			newNode->next = st;
		}
		else
		{
			st = list->tail->prev;

			while (st->level >= level)
				st = st->prev;

			st->next->prev = newNode;
			newNode->next = st->next;
			st->next = newNode;
			newNode->prev = st;
		}
	}
}//End of InsertNode()

int DeleteNode(LinkedList*list)
{
	Node*temp = NULL;
	Node*delNode = NULL;

	if (IsEmptyList(&list))
	{
		printf("\n리스트가 비었음\n\n");
		return FALSE;
	}
	else
	{
		int sel;

		printf("\n삭제방식 --->  (1)데이터직접입력 (2)임의로 삭제\n\n");
		printf("선택:");
		scanf("%d", &sel);

		switch (sel)
		{
		case 1:
		{
			char animal[30];
			printf("\n삭제데이터(이름) 입력:");
			scanf("%s", animal);

			temp = list->head->next;

			while (strcmp(temp->animal, animal))
			{
				if (!strcmp(temp->pos, "tail"))
				{
					printf("\n탐색실패\n");
					return FALSE;
				}

				temp = temp->next;
			}//while()

			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delNode = temp;
			list->fp(delNode->animal, delNode->level);
			free(delNode);
			return TRUE;
		}
		case 2:
		{
			printf("\n(1)좌측데이터삭제  (2)우측데이터삭제\n\n");
			printf("선택: ");
			scanf("%d", &sel);

			if (sel == 1)
			{
				temp = list->head->next;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delNode = temp;
				list->fp(delNode->animal, delNode->level);
				free(delNode);
			}
			else if (sel == 2)
			{
				temp = list->tail->prev;
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
				delNode = temp;
				list->fp(delNode->animal, delNode->level);
				free(delNode);
			}
			else
			{
				printf("\n선택값오류\n\n");
				return FALSE;
			}
			return TRUE;
		}
		default:
			printf("\n선택값오류\n\n");
			return FALSE;
		}//switch
	}//if-else
}//End of DeleteNode()

void traversalList(LinkedList*list)
{
	int sel;
	Node*st = NULL;

	if (IsEmptyList(&list))
	{
		printf("\n리스트가 비었음\n\n");
		return;
	}
	else
	{
		printf("\n순회방향 --> (1)왼쪽에서 오른쪽  (2)오른쪽에서 왼쪽 \n");
		printf("선택하시오: ");
		scanf("%d", &sel);

		switch (sel)
		{
		case 1:
			st = list->head->next;

			while (strcmp(st->pos, "tail"))
			{
				list->fp(st->animal, st->level);
				st = st->next;
			}//while()

			break;
		case 2:
			st = list->tail->prev;

			while (strcmp(st->pos, "head"))
			{
				list->fp(st->animal, st->level);
				st = st->prev;
			}//while()

			break;
		default:
			printf("\n선택값오류\n\n");
		}//switch
	}//if-else
}//End of traversalList()


