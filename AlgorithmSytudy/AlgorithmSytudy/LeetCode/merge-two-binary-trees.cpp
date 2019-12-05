#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

struct TreeNode {
	int val = 0;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* allocate() {
	TreeNode*node = (TreeNode*)malloc(sizeof(TreeNode));
	node->val = 0;
	node->left = NULL;
	node->right = NULL;
	return node;
}

TreeNode* traverse(TreeNode* t1, TreeNode* t2)
{
	TreeNode* newNode = allocate();

	if ((t1 && t1->left) || (t2 && t2->left)) {
		newNode->left = traverse(t1 ? t1->left : t1, t2 ? t2->left : t2);
	}

	if ((t1 && t1->right) || (t2 && t2->right)) {
		newNode->right = traverse(t1 ? t1->right : t1, t2 ? t2->right : t2);
	}

	if (t1 && t2) {
		newNode->val = t1->val + t2->val;
	}
	else {
		if (t1) {
			newNode->val = t1->val;
		}
		else {
			newNode->val = t2->val;
		}
	}
	return newNode; 
}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
	if (!t1 && !t2) return {};
	TreeNode* mergedTree = traverse(t1, t2);
	return mergedTree;
}

int main()
{
	TreeNode* t1 = allocate();
	
	TreeNode* t2 = allocate();
	
	mergeTrees({}, {});
	return 0;
}