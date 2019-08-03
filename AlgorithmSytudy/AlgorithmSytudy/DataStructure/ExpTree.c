#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListStack.h"
#include "ExpTree.h"

BTNode* MakeExpTree(char exp[])
{
	int i;
	char ch;
	Stack stack;
	BTNode*node;

	Init_S(&stack);

	for (i = 0;i < strlen(exp);i++)
	{
		ch = exp[i];
		node = MakeBTNode();
		Init_BT(node);

		if (isdigit(ch))
		{
			SetData(node, ch - '0');
		}
		else
		{
			SetData(node, ch);
			MakeRightSubTree(node, Pop_S(&stack));
			MakeLeftSubTree(node, Pop_S(&stack));
		}

		Push_S(&stack, node);
	}//for(i)	
	return Pop_S(&stack);
}//End of MakeExpTree()

int CalExpTree(BTNode*bt)
{
	int leftNum;
	int rightNum;
 
	if (!bt->left && !bt->right)
		return bt->data;

	leftNum = CalExpTree(bt->left);
	rightNum = CalExpTree(bt->right);

	switch (bt->data)
	{
	case '+': return leftNum + rightNum;
	case '-': return leftNum - rightNum;
	case '*': return leftNum * rightNum;
	case '/': return leftNum / rightNum;
    }//switch
}//End of CalExpTree()

void Show_Exp_PrefixOrderType(BTNode*bt)
{
	if (bt == NULL)
		return;

	if (isdigit(bt->data + '0'))
		printf("%c", bt->data + '0');
	else
		printf("%c", bt->data);

	Show_Exp_PrefixOrderType(bt->left);
	Show_Exp_PrefixOrderType(bt->right);
}//End of Show_Exp_PrefixOrderType()

void Show_Exp_InfixOrderType(BTNode*bt)
{
	if (bt == NULL)
		return;

	if (!isdigit(bt->data + '0'))
		printf("(");

	Show_Exp_InfixOrderType(bt->left);

	if (isdigit(bt->data + '0'))
		printf("%c", bt->data + '0');	
	else
		printf("%c", bt->data);

	if (bt->right == NULL)
		return;

	if (!isdigit(bt->right->data + '0'))
	{
		Show_Exp_InfixOrderType(bt->right);
		printf(")");
	}
	else if (isdigit(bt->right->data + '0'))
	{
		printf("%c", bt->right->data + '0');
		printf(")");
	}
}//End of Show_Exp_InfixOrderType()

void Show_Exp_PostfixOrderType(BTNode*bt)
{
	if (bt == NULL)
		return;

	Show_Exp_PostfixOrderType(bt->left);
	Show_Exp_PostfixOrderType(bt->right);

	if (isdigit(bt->data + '0'))
		printf("%c", bt->data + '0');
	else
		printf("%c", bt->data);
}//End of Show_Exp_PostfixOrderType()




