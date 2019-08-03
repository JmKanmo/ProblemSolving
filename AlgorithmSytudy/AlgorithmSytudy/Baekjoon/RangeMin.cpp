#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

/*
2018.11.1
구간트리실습(최소값구하기)
두부
*/

#define INT_MAX 987654321

//구간트리(구간 최소값)
class RMQ
{
public:
	vector<int>range_min;
	int len;

	RMQ(vector<int>&array)
	{
		len = array.size();
		range_min.resize(len * 4);
		init(array, 0, len - 1, 1);
	}//RMQ()

	//구간트리 초기화함수
	int init(vector<int>&array, int left, int right, int node)
	{
		if (left == right)
			return range_min[node] = array[left];

		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		
		return range_min[node] = min(leftMin, rightMin);
	}//init()

	//질의처리함수(특정구간의 최소값반환)
	int query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if (right < nodeLeft || nodeRight < left)
			return INT_MAX;
		if (left <= nodeLeft && nodeRight <= right)
			return range_min[node];

		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}//query()
  
	int query(int left, int right) {
		return query(left, right, 1, 0, len - 1);
	}//query()

	//구간트리 갱신함수
	int update(int idx, int newVal, int node, int nodeLeft, int nodeRight)
	 {
		if (idx<nodeLeft || idx>nodeRight)
			return range_min[node];

		if (nodeLeft == nodeRight)
			return range_min[node] = newVal;

		int mid = (nodeLeft + nodeRight) / 2;

		return min(update(idx, newVal, node * 2, nodeLeft, mid), update(idx, newVal, node * 2 + 1, mid + 1, nodeRight));
	}//update()

	int update(int idx, int newVal)
	{
		return update(idx, newVal, 1, 0, len - 1);
	}
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

 	vector<int>arr(n + 1);

	for (int i = 1; i <=n; i++)
		scanf("%d", &arr[i]);

	RMQ rmq(arr);

	for (int j = 0; j < m; j++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", rmq.query(a, b));
	}//for()
}//main()
