#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"

BTNode*MakeBTNode(void)
{
	BTNode*bt = (BTNode*)malloc(sizeof(BTNode));
	bt->key = 0;
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}//End of MakeBTNode()

void SetData(BTNode*bt, DataKey key, BTData data)
{
	bt->key = key;
	strcpy(bt->data, data);
}//End of SetData()

BTData GetData(BTNode*bt)
{
	return bt->data;
}//End of GetData()

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
	if (main->left)
		free(main->left);

	main->left = sub;
}//End of MakeLeftSubTree()

void MakeRightSubTree(BTNode*main, BTNode*sub)
{
	if (main->right)
		free(main->right);

	main->right = sub;
}//End of MakeRightSubTree()

void ChangeLeftSubTree(BTNode*main, BTNode*sub)
{
	main->left = sub;
}//End of ChangeLeftSubTree()

void ChangeRightSubTree(BTNode*main, BTNode*sub)
{
	main->right = sub;
}//End of ChangeRightSubTree()

void PreOrderTraversal(BTNode*bt, FuncPtr fp)
{
	if (!bt)
		return;

	fp(bt->key, bt->data);
	PreOrderTraversal(bt->left, fp);
	PreOrderTraversal(bt->right, fp);
}//End of PreOrderTraversal()

void InOrderTraversal(BTNode*bt, FuncPtr fp)
{
	if (!bt)
		return;

	InOrderTraversal(bt->left, fp);
	fp(bt->key, bt->data);
	InOrderTraversal(bt->right, fp);
}//End of InOrderTraversal()

void PostOrderTraversal(BTNode*bt, FuncPtr fp)
{
	if (!bt)
		return;

	PostOrderTraversal(bt->left, fp);
	PostOrderTraversal(bt->right, fp);
	fp(bt->key, bt->data);
}//End of PostOrderTraversal()

