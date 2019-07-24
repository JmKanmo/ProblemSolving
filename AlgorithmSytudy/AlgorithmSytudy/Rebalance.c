#include <stdio.h>
#include "Rebalance.h"

int GetHeight(BTNode*bt)
{
	if (!bt)
		return 0;

	int left = GetHeight(GetLeftSubTree(bt));
	int right = GetHeight(GetRightSubTree(bt));

	return left > right ? left + 1 : right + 1;
}//End of GetHeight()

int GetBalanceFactor(BTNode*bt)
{
	int Left_Height = GetHeight(GetLeftSubTree(bt));
	int Right_Height = GetHeight(GetRightSubTree(bt));

	return Left_Height - Right_Height;
}//End of GetBalanceFactor()

void RotateLL(BTNode**bt, BTNode*mNode, BTNode*pNode, BTNode*cNode)
{
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	if (mNode == pNode)
	{
		if (*bt == mNode)
			*bt = cNode;
	}

	if (mNode != pNode)
	{
		if (GetLeftSubTree(mNode) == pNode)
			ChangeLeftSubTree(mNode, cNode);
		else
			ChangeRightSubTree(mNode, cNode);
	}
}//End of RotateLL()

void RotateRR(BTNode**bt, BTNode*mNode, BTNode*pNode, BTNode*cNode)
{
	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	if (mNode == pNode)
	{
		if (*bt == mNode)
			*bt = cNode;
	}

	if (mNode != pNode)
	{
		if (GetRightSubTree(mNode) == pNode)
			ChangeRightSubTree(mNode, cNode);
		else
			ChangeLeftSubTree(mNode, cNode);
	}
}//End of RotateRR()

void RotateLR(BTNode**bt, BTNode*mNode, BTNode*pNode, BTNode*cNode, BTNode*sNode)
{
	RotateRR(bt, cNode, cNode, sNode);
	ChangeLeftSubTree(pNode,GetRightSubTree(sNode));
	ChangeRightSubTree(sNode, pNode);

	if (mNode == pNode)
		*bt = sNode;

	if (mNode != pNode)
	{
		if (GetLeftSubTree(mNode) == pNode)
			ChangeLeftSubTree(mNode, sNode);
		else
			ChangeRightSubTree(mNode, sNode);
	}
}//End of RotateLR()

void RotateRL(BTNode**bt, BTNode*mNode, BTNode*pNode, BTNode*cNode, BTNode*sNode)
{
	RotateLL(bt, cNode, cNode, sNode);
	ChangeRightSubTree(pNode, GetLeftSubTree(sNode));
	ChangeLeftSubTree(sNode, pNode);

	if (mNode == pNode)
		*bt = sNode;

	if (mNode != pNode)
	{
		if (GetRightSubTree(mNode) == pNode)
			ChangeRightSubTree(mNode, sNode);
		else
			ChangeLeftSubTree(mNode, sNode);
	}
}//End of RotateRL()

void Rebalance(BTNode**bt, const DataKey target, const int c)
{ 
	if (c == 1)
	{
		BTNode*sNode = *bt;
		BTNode*mNode = sNode;
		BTNode*pNode = mNode;
		BTNode*cNode = pNode;

		int sCount = 0;
		int balFactorP = 0;
		int balFactorC = 0;

		while (sNode->key != target)
		{
			sNode = target < sNode->key ? GetLeftSubTree(sNode) : GetRightSubTree(sNode);

			switch (++sCount)
			{
			case 1:
				cNode = target < cNode->key ? GetLeftSubTree(cNode) : GetRightSubTree(cNode);
				break;

			case 2:
				break;

			case 3:
				pNode = cNode;
				cNode = target < cNode->key ? GetLeftSubTree(cNode) : GetRightSubTree(cNode);
				break;

			default:
				mNode = pNode;
				pNode = cNode;
				cNode = target < cNode->key ? GetLeftSubTree(cNode) : GetRightSubTree(cNode);
			}//switch

			balFactorP = GetBalanceFactor(pNode);
			balFactorC = GetBalanceFactor(cNode);
		}//while(i)

		switch (balFactorP)
		{
		case 2:
			if (balFactorC == 1) RotateLL(bt, mNode, pNode, cNode);
			else if (balFactorC == -1) RotateLR(bt, mNode, pNode, cNode, sNode);
			break;
		case -2:
			if (balFactorC == 1) RotateRL(bt, mNode, pNode, cNode, sNode);
			else if (balFactorC == -1) RotateRR(bt, mNode, pNode, cNode);
			break;
		}//switch
	}
	else if (c == 2)
	{
		BTNode*mNode = *bt;
		BTNode*pNode = mNode;
		BTNode*nArr[5];

		int toggle = FALSE;
		int count = 0;

		if (!pNode)
			return;

		while (1)
		{
			if (!GetLeftSubTree(pNode) && !GetRightSubTree(pNode))
			{
				nArr[count++] = pNode;

				if (count == 3)
				{
					if ((nArr[0]->left == nArr[1]) && (nArr[1]->left == nArr[2]))
						RotateLL(bt, mNode, nArr[0], nArr[1]);

					else if ((nArr[0]->right == nArr[1]) && (nArr[1]->right == nArr[2]))
						RotateRR(bt, mNode, nArr[0], nArr[1]);

					else if ((nArr[0]->right == nArr[1]) && (nArr[1]->left == nArr[2]))
						RotateRL(bt, mNode, nArr[0], nArr[1], nArr[2]);

					else if ((nArr[0]->left == nArr[1]) && (nArr[1]->right == nArr[2]))
						RotateLR(bt, mNode, nArr[0], nArr[1], nArr[2]);
				}
				break;
			}
			else if (GetLeftSubTree(pNode) && GetRightSubTree(pNode))
			{
				if (toggle == TRUE)
					break;
				else
				{
					count = 0;
					mNode = pNode;
				}
				pNode = target < pNode->key ? GetLeftSubTree(pNode) : GetRightSubTree(pNode);
			}
			else
			{
				BTNode*temp;

				nArr[count++] = pNode;

				if (count == 3)
				{
					if ((nArr[0]->left == nArr[1]) && (nArr[1]->left == nArr[2]))
						RotateLL(bt, mNode, nArr[0], nArr[1]);

					else if ((nArr[0]->right == nArr[1]) && (nArr[1]->right == nArr[2]))
						RotateRR(bt, mNode, nArr[0], nArr[1]);

					else if ((nArr[0]->right == nArr[1]) && (nArr[1]->left == nArr[2]))
						RotateRL(bt, mNode, nArr[0], nArr[1], nArr[2]);

					else if ((nArr[0]->left == nArr[1]) && (nArr[1]->right == nArr[2]))
						RotateLR(bt, mNode, nArr[0], nArr[1], nArr[2]);
					break;
				}

				if (pNode->key == target)
					temp = NULL;

				else
					temp = target < pNode->key ? GetLeftSubTree(pNode) : GetRightSubTree(pNode);

				if (!temp)
				{
					toggle = TRUE;
					pNode = !GetLeftSubTree(pNode) ? GetRightSubTree(pNode) : GetLeftSubTree(pNode);
				}
				else
					pNode = temp;
			}
		}//while(i)
	}//if-else
}//End of Rebalance()








