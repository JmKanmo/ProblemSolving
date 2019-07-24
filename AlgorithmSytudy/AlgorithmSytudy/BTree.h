#ifndef BTREE__H
#define BTREE__H

typedef char BTData;

typedef struct _BTNode
{
	BTData data[30];
	struct _BTNode*left;
	struct _BTNode*right;
}BTNode;

typedef void FuncPtr(BTData data);

BTNode* MakeBTNode(void);

BTData GetData(BTNode*bt);
void SetData(BTNode*bt, BTData data[]);

BTNode* GetLeftSubTree(BTNode*bt);
BTNode* GetRightSubTree(BTNode*bt);

void MakeLeftSubTree(BTNode*main, BTNode*sub);
void MakeRightSubTree(BTNode*main, BTNode*sub);

void PrefixOrderTraversal(BTNode*bt, FuncPtr fp);
void InfixOrderTraversal(BTNode*bt, FuncPtr fp);
void PostfixOrderTraversal(BTNode*bt, FuncPtr fp);

void DeleteBT(BTNode*bt);

#endif