#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"

#define NODE_NUMBER 7

void ShowData(BTData data[]);
void Input_SetData(BTNode*);
void MakeBinaryTree(BTNode*[]);

int main(void)
{
	printf("[ ����Ʈ�� ����&��ȸ ]\n\n");

	BTNode*bt[NODE_NUMBER];
	MakeBinaryTree(&bt);

	printf("[ %d���� ���� �̷��� ����Ʈ�������Ϸ� ]\n\n", NODE_NUMBER - 1);

	printf("[ ������ȸ ]\n\n");
	PrefixOrderTraversal(bt[1], ShowData);
	puts("\n");

	printf("[ ������ȸ ]\n\n");
	InfixOrderTraversal(bt[1], ShowData);
	puts("\n");

	printf("[ ������ȸ ]\n\n");
	PostfixOrderTraversal(bt[1], ShowData);
	puts("\n");

	printf("[ ����Ʈ������ ]\n\n");
	DeleteBT(bt[1]);

	return 0;
}//End of main()

void ShowData(BTData data[])
{
	printf("%s ", data);
}//End of ShowData()

void Input_SetData(BTNode*bt)
{
	BTData data[30];
	printf("�������Է�:");
	scanf("%s", data);
	getchar();
	SetData(bt, data);
}//End of InputData()

void MakeBinaryTree(BTNode*bt[])
{
	int i;

	for (i = 1;i < NODE_NUMBER;i++) 
		bt[i] = MakeBTNode();
	
	for(i = 1;i < NODE_NUMBER;i++)
	{
		if (i == 1)
		{
			printf("[%d��° ������]\n", i);
			bt[i] = MakeBTNode();
			Input_SetData(bt[i]);
		}
		else
		{
			if (i % 2 == 0)
			{
				printf("[%d��° ��� ���ʳ�����]\n", i / 2);
				MakeLeftSubTree(bt[i / 2], bt[i]);
				Input_SetData(bt[i / 2]->left);
			}
			else
			{
				printf("[%d��° ��� �����ʳ�����]\n", i / 2);
				MakeRightSubTree(bt[i / 2], bt[i]);
				Input_SetData(bt[i / 2]->right);
			}
		}
		puts("\n");
	}//for(i)
}//End of MakeBinaryTree()



