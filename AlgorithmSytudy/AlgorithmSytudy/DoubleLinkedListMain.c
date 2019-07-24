#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

int select(void);
Node*createNode(void);
void InputInfo(int*,char[]);
void setNode(Node*n, int, char[]);

int main(void)
{
	printf("[ ���߿��Ḯ��Ʈ �ǽ� ]\n\n");

	Node*node;
	int age;
	char name[30];

	Init_List();
	printf("\n����Ʈ�ʱ�ȭ �Ϸ�\n\n");

	while (1)
	{
		switch (select())
		{
		case 1:
			node = createNode();
			printf("\n[���Գ�� �����Է�]\n");
			InputInfo(&age, name);
			setNode(node, age, name);
			Insert_Node(node);
			printf("\n��� ����&���ԿϷ�\n\n");
			break;
		case 2:
			Circulate_Node();
			break;
		case 3:
			printf("\n[������� �����Է�]\n");
			InputInfo(&age, name);
			if (Delete_Node(age, name))
			{
				printf("\n�������Ϸ�\n\n");
			}
			else
			{
				printf("\n����������\n\n");
			}
			break;
		case 4:
			deleteAll();
			printf("���α׷�����\n\n");
			return -1;
		default:
			printf("\n�߸����Է�\n\n");
		}//switch(i)
	}//while(i)

	return 0;
}//End of main()

int select(void)
{
	int sel;
	printf("[1]��� ����&����  [2]����Ʈ��ȸ  [3]������ [4]����\n\n");
	printf("�Է�:");
	scanf("%d", &sel);
	return sel;
}//End of select()

Node*createNode(void) { return (Node*)malloc(sizeof(Node)); }//End of createNode()

void InputInfo(int*age,char name[])
{
	printf("\n�̸�:");
	scanf("%s", name);
	printf("����:");
	scanf("%d", age);
	getchar();
}//End of InputInfo()

void setNode(Node*node, int age, char name[])
{
	strcpy(node->name, name);
	node->age = age;
}//End of setNode()