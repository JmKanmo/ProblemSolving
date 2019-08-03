#ifndef __BINARYTREE__H
#define __BINARYTREE__H

typedef char DataKey;
typedef char* BTData;

typedef struct _BTNode
{
	DataKey key;
	const char data[20];
	struct _BTNode*left;
	struct _BTNode*right;
}BTNode;

typedef void FuncPtr(DataKey, BTData);

BTNode*MakeBTNode(void);
void SetData(BTNode*, DataKey, BTData);
BTData GetData(BTNode*);
BTNode* GetLeftSubTree(BTNode*);
BTNode* GetRightSubTree(BTNode*);
void MakeLeftSubTree(BTNode*, BTNode*);
void MakeRightSubTree(BTNode*, BTNode*);
void ChangeLeftSubTree(BTNode*, BTNode*);
void ChangeRightSubTree(BTNode*, BTNode*);
void PreOrderTraversal(BTNode*, FuncPtr);
void InOrderTraversal(BTNode*, FuncPtr);
void PostOrderTraversal(BTNode*, FuncPtr);

#endif