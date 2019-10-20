#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, pair<int, int>>Pair;

struct Tree {
	int number;
	int size;
	Tree* left;
	Tree* right;
};

Tree* tree;
vector<int>ret;

void init(int size,int number) {
	tree = (Tree*)malloc(sizeof(Tree));
	tree->left = NULL;
	tree->right = NULL;
	tree->size = size;
	tree->number = number;
}

bool comp(const Pair& p1, const Pair& p2)
{
	return p1.second.second > p2.second.second;
}

vector<Pair>sorted_func(vector<vector<int>> nodeinfo)
{
	vector<Pair>temp;

	for (int i = 0; i < nodeinfo.size(); i++)
		temp.push_back(Pair(i + 1, make_pair(nodeinfo[i][0], nodeinfo[i][1])));

	sort(temp.begin(), temp.end(), comp);
	init(temp[0].second.first, temp[0].first);
	return temp;
}

void insert_Node(Pair node)
{
	Tree* temp = tree;
	int node_size = node.second.first;
	int node_number = node.first;

	while (true)
	{
		if (node_size < temp->size)
		{
			if (temp->left == NULL) {
				temp->left = (Tree*)malloc(sizeof(Tree));
				temp->left->left = NULL;
				temp->left->right = NULL;
				temp->left->number = node_number;
				temp->left->size = node_size;
				break;
			}
			temp = temp->left;
		}
		else
		{
			if (temp->right == NULL) {
				temp->right = (Tree*)malloc(sizeof(Tree));
				temp->right->left = NULL;
				temp->right->right = NULL;
				temp->right->number = node_number;
				temp->right->size = node_size;
				break;
			}
			temp = temp->right;
		}
	}
}

void pre_traverse(Tree* tree)
{
	if (tree == NULL)
		return;

	ret.push_back(tree->number);
	pre_traverse(tree->left);
	pre_traverse(tree->right);
}

void post_traverse(Tree* tree)
{
	if (tree == NULL)
		return;

	post_traverse(tree->left);
	post_traverse(tree->right);
	ret.push_back(tree->number);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<Pair>sorted = sorted_func(nodeinfo);
	vector<vector<int>> answer;

	for (int i = 1; i < sorted.size(); i++)
		insert_Node(sorted[i]);

	pre_traverse(tree);
	answer.push_back(ret);
	ret.clear();
	post_traverse(tree);
	answer.push_back(ret);
	ret.clear();
	free(tree);
	return answer;
}

int main()
{
	solution({ {5, 3 }, { 11, 5 }, { 13, 3 }, { 3, 5 }, { 6, 1 }, { 1, 3 }, { 8, 6 }, { 7, 2 }, { 2, 2 } });

	return 0;
}