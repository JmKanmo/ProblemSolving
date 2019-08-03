#ifndef __EXPTREE__H
#define __EXPTREE__H

#include "BTree.h"

BTNode* MakeExpTree(char[]);
int CalExpTree(BTNode*);

void Show_Exp_PrefixOrderType(BTNode*);
void Show_Exp_InfixOrderType(BTNode*);
void Show_Exp_PostfixOrderType(BTNode*);

#endif