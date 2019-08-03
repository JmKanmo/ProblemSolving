#ifndef __BINARY__SEARCH__TREE__H
#define __BINARY__SEARCH__TREE__H

#include "BinaryTree.h"
#include "Rebalance.h"

typedef BTData BSTData;

typedef struct _BSTree
{
	BTNode* bt;
	FuncPtr*fp;
}BSTree;

char data[20];

void BSTreeInit(BSTree*, FuncPtr);
void BSTreeInsert(BSTree*, DataKey, BSTData);
BSTData BSTreeSearch(BSTree*, DataKey);
BSTData BSTreeDelete(BSTree*, DataKey);
void BSTreeTraversal(BSTree*);

#endif