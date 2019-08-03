#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinarySearchTree.h"

void BSTreeInit(BSTree*bst,FuncPtr fp)
{
	bst->bt = NULL;
	bst->fp = fp;
}//End of BSTreeInit()

void BSTreeInsert(BSTree*bst, DataKey key, BSTData data)
{
	BTNode*newNode = MakeBTNode();
	SetData(newNode, key, data);

	BTNode*pNode = bst->bt;

	if (!pNode)
		bst->bt = newNode;
	else
	{
		while (1)
		{
			if (newNode->key == pNode->key)
			{
				printf("\n키값이 중복됨\n");
				return;
			}
			else
			{
				if (newNode->key > pNode->key)
				{
					if (!GetRightSubTree(pNode))
					{
						MakeRightSubTree(pNode, newNode);
						break;
					}
					else
						pNode = GetRightSubTree(pNode);
				}
				else
				{
					if (!GetLeftSubTree(pNode))
					{
						MakeLeftSubTree(pNode, newNode);
						break;
					}
					else
						pNode = GetLeftSubTree(pNode);
				}//if-else
			}//if-else
		}//while(i)
	}//if-else
	Rebalance(&bst->bt, key, 1);
}//End of AddData()

BSTData BSTreeSearch(BSTree*bst, DataKey key)
{
	BTNode*pNode = bst->bt;

	while (pNode != NULL)
	{
		if (pNode->key == key)
			return GetData(pNode);
		else
			pNode = key < pNode->key ? GetLeftSubTree(pNode) : GetRightSubTree(pNode);
	}
	return pNode;
}//End of SearchData()

BSTData BSTreeDelete(BSTree*bst, DataKey key)
{
	BTNode*dpNode = bst->bt;
	BTNode*dNode = dpNode;
	BSTData delData;

	while (dNode)
	{
		if (dNode->key == key)
			break;
		dpNode = dNode;
		dNode = dNode->key > key ? GetLeftSubTree(dNode) : GetRightSubTree(dNode);
	}//while(i)

	if (!dNode)
		return dNode;

	if (GetLeftSubTree(dNode) && GetRightSubTree(dNode))
	{
		BTNode*rpNode = dNode;
		BTNode*rNode = GetLeftSubTree(rpNode);
		BTNode*pNode = rpNode;

		while (GetRightSubTree(rNode))
		{
			rpNode = rNode;
			rNode = GetRightSubTree(rNode);
		}//while(i)

		strcpy(data, GetData(dNode));
		SetData(dNode, rNode->key, GetData(rNode));

		if (GetLeftSubTree(rpNode) == rNode)
			ChangeLeftSubTree(rpNode, GetLeftSubTree(rNode));
		else
			ChangeRightSubTree(rpNode, GetLeftSubTree(rNode));

		free(rNode);

		if (GetLeftSubTree(pNode))
			Rebalance(&pNode->left, dNode->key, 2);
		else
			Rebalance(&bst->bt, dNode->key, 2);
	}
	else
	{
		if (dNode == dpNode)
		{
			dpNode = GetLeftSubTree(dpNode) ? GetLeftSubTree(dpNode) : GetRightSubTree(dpNode);
			bst->bt = dpNode;	
		}
	else
	{
		if (!GetLeftSubTree(dNode) && !GetRightSubTree(dNode))
		{
			if (GetLeftSubTree(dpNode) == dNode)
				ChangeLeftSubTree(dpNode, GetLeftSubTree(dNode));
			else
				ChangeRightSubTree(dpNode, GetLeftSubTree(dNode));
			
			Rebalance(&bst->bt, dNode->key, 2);
		}
		else
		{
			if (GetLeftSubTree(dpNode) == dNode)
			{
				if (GetLeftSubTree(dNode))
					ChangeLeftSubTree(dpNode, GetLeftSubTree(dNode));
				else
					ChangeLeftSubTree(dpNode, GetRightSubTree(dNode));
			}
			else
			{
				if (GetLeftSubTree(dNode))
					ChangeRightSubTree(dpNode, GetLeftSubTree(dNode));
				else
					ChangeRightSubTree(dpNode, GetRightSubTree(dNode));
			 }//if-else			
		  }//if-else
      }//if-else
		strcpy(data, GetData(dNode));
		free(dNode);
    }//if-else
	return (delData = data);
}//End of BSTreeRemove()

void BSTreeTraversal(BSTree*bst)
{
	InOrderTraversal(bst->bt, bst->fp);
}//End of BSTreeTraversal()
