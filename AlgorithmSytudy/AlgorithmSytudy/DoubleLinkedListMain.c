#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

int select(void);
Node*createNode(void);
void InputInfo(int*,char[]);
void setNode(Node*n, int, char[]);

int main(void)
{
	printf("[ 이중연결리스트 실습 ]\n\n");

	Node*node;
	int age;
	char name[30];

	Init_List();
	printf("\n리스트초기화 완료\n\n");

	while (1)
	{
		switch (select())
		{
		case 1:
			node = createNode();
			printf("\n[삽입노드 정보입력]\n");
			InputInfo(&age, name);
			setNode(node, age, name);
			Insert_Node(node);
			printf("\n노드 생성&삽입완료\n\n");
			break;
		case 2:
			Circulate_Node();
			break;
		case 3:
			printf("\n[삭제노드 정보입력]\n");
			InputInfo(&age, name);
			if (Delete_Node(age, name))
			{
				printf("\n노드삭제완료\n\n");
			}
			else
			{
				printf("\n노드삭제실패\n\n");
			}
			break;
		case 4:
			deleteAll();
			printf("프로그램종료\n\n");
			return -1;
		default:
			printf("\n잘못된입력\n\n");
		}//switch(i)
	}//while(i)

	return 0;
}//End of main()

int select(void)
{
	int sel;
	printf("[1]노드 생성&삽입  [2]리스트조회  [3]노드삭제 [4]종료\n\n");
	printf("입력:");
	scanf("%d", &sel);
	return sel;
}//End of select()

Node*createNode(void) { return (Node*)malloc(sizeof(Node)); }//End of createNode()

void InputInfo(int*age,char name[])
{
	printf("\n이름:");
	scanf("%s", name);
	printf("나이:");
	scanf("%d", age);
	getchar();
}//End of InputInfo()

void setNode(Node*node, int age, char name[])
{
	strcpy(node->name, name);
	node->age = age;
}//End of setNode()