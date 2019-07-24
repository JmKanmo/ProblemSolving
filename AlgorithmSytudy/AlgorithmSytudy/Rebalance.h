#ifndef __REBALANCE__H
#define __REBALANCE__H

#include "BinaryTree.h"
#include "BinarySearchTree.h"

#define TRUE 1
#define FALSE 0

int GetHeight(BTNode*);
int GetBalanceFactor(BTNode*);
void RotateLL(BTNode**, BTNode*, BTNode*, BTNode*);
void RotateRR(BTNode**, BTNode*, BTNode*, BTNode*);
void RotateLR(BTNode**, BTNode*, BTNode*, BTNode*, BTNode*);
void RotateRL(BTNode**, BTNode*, BTNode*, BTNode*, BTNode*);
void Rebalance(BTNode**, const DataKey, const int);

#endif
