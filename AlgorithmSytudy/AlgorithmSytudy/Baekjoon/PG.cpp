#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/*
2018.11.09
세그먼트트리 실습(BOJ 9463)
두부
*/

typedef long long LL;
#define MAX 100000

vector<LL>seg_tree(MAX * 4);
vector<int>array_A(MAX);
vector<int>array_B(MAX);


LL update(int pos, int val, int node, int nodeLeft, int nodeRight)
{
	if (nodeRight<pos || nodeLeft>pos)
		return seg_tree[node];

	if (nodeLeft == nodeRight)
		return seg_tree[node] = val;

	int mid = (nodeLeft + nodeRight) / 2;

	return seg_tree[node] = update(pos, val, node * 2, nodeLeft, mid) + update(pos, val, node * 2 + 1, mid + 1, nodeRight);
}//update()

LL query(int left, int right, int node, int nodeLeft, int nodeRight)
{
	if (left > nodeRight || right < nodeLeft)
		return 0;
	
	if (left <= nodeLeft && right >= nodeRight)
		return seg_tree[node];

	int mid = (nodeLeft + nodeRight) / 2;

	return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
}//query()


int main()
{
	int t;
	LL ans;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		ans = 0;

		fill(array_A.begin(), array_A.end(), 0);
		fill(array_B.begin(), array_B.end(), 0);
		fill(seg_tree.begin(), seg_tree.end(), 0);

		for (int j = 0; j <n; j++)
		{
			int a;
			scanf("%d", &a);
			array_A[a] = j;
		}//for()

		for (int j = 0; j < n; j++)
		{
			int b;
			scanf("%d", &b);
			array_B[j] = array_A[b];
		}//for()

		for (int j = 0; j <n; j++)
		{
			ans += ((LL)array_B[j] - query(0, array_B[j], 1, 0, n - 1));
			update(array_B[j], 1, 1, 0, n-1);
		}//for()	
		printf("%lld\n", ans);
	}//for()
	return 0;
}//main()