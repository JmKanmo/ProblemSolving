#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTree.h"

BTNode* MakeBTNode(void)
{
	BTNode*pNode = (BTNode*)malloc(sizeof(BTNode));
	pNode->left = NULL;
	pNode->right = NULL;
	return pNode;
}//End of MakeBTNode()

BTData GetData(BTNode*bt)
{
	return bt->data;
}//End of GetData()

void SetData(BTNode*bt, BTData data[])
{
	strcpy(bt->data, data);

}//End of SetData()

BTNode* GetLeftSubTree(BTNode*bt)
{
	return bt->left;
}//End of GetLeftSubTree()

BTNode* GetRightSubTree(BTNode*bt)
{
	return bt->right;
}//End of GetRightSubTree()

void MakeLeftSubTree(BTNode*main, BTNode*sub)
{
	if (main->left != NULL)
		free(main->left);

		main->left = sub;
}//End of MakeLeftSubTree()

void MakeRightSubTree(BTNode*main, BTNode*sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}//End of MakeRightSubTree()

void PrefixOrderTraversal(BTNode*bt, FuncPtr fp)
{
	if (bt == NULL) 
		return;
	
	fp(bt->data);
	PrefixOrderTraversal(bt->left, fp);
	PrefixOrderTraversal(bt->right, fp);
}//End of PrefixOrderTraversal()

void InfixOrderTraversal(BTNode*bt, FuncPtr fp)
{
	if (bt == NULL)
		return;

	InfixOrderTraversal(bt->left, fp);
	fp(bt->data);
	InfixOrderTraversal(bt->right, fp);
}//End of InfixOrderTraversal()

void PostfixOrderTraversal(BTNode*bt, FuncPtr fp)
{
	if (bt == NULL)
		return;

	PostfixOrderTraversal(bt->left, fp);
	PostfixOrderTraversal(bt->right, fp);
	fp(bt->data);
}//End of PostfixOrderTraversal()

void DeleteBT(BTNode*bt)
{
	if (bt == NULL)
		return;

	DeleteBT(bt->left);
	DeleteBT(bt->right);
	free(bt);
}//End of DeleteBT()
