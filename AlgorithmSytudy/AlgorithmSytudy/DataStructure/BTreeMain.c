#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"

#define NODE_NUMBER 7

void ShowData(BTData data[]);
void Input_SetData(BTNode*);
void MakeBinaryTree(BTNode*[]);

int main(void)
{
	printf("[ 이진트리 생성&순회 ]\n\n");

	BTNode*bt[NODE_NUMBER];
	MakeBinaryTree(&bt);

	printf("[ %d개의 노드로 이뤄진 이진트리생성완료 ]\n\n", NODE_NUMBER - 1);

	printf("[ 전위순회 ]\n\n");
	PrefixOrderTraversal(bt[1], ShowData);
	puts("\n");

	printf("[ 중위순회 ]\n\n");
	InfixOrderTraversal(bt[1], ShowData);
	puts("\n");

	printf("[ 후위순회 ]\n\n");
	PostfixOrderTraversal(bt[1], ShowData);
	puts("\n");

	printf("[ 이진트리삭제 ]\n\n");
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
	printf("데이터입력:");
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
			printf("[%d번째 노드생성]\n", i);
			bt[i] = MakeBTNode();
			Input_SetData(bt[i]);
		}
		else
		{
			if (i % 2 == 0)
			{
				printf("[%d번째 노드 왼쪽노드생성]\n", i / 2);
				MakeLeftSubTree(bt[i / 2], bt[i]);
				Input_SetData(bt[i / 2]->left);
			}
			else
			{
				printf("[%d번째 노드 오른쪽노드생성]\n", i / 2);
				MakeRightSubTree(bt[i / 2], bt[i]);
				Input_SetData(bt[i / 2]->right);
			}
		}
		puts("\n");
	}//for(i)
}//End of MakeBinaryTree()



