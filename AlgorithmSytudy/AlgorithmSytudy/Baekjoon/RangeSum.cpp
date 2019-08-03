#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

/*
2018.11.02
구간트리실습(구간합)
두부
*/

typedef long long LL;


//구간트리 클래스
class Segment_Tree
{
public:
	vector<LL>range_sum;
	int len;

	Segment_Tree(vector<LL>&ref)
	{
		len = ref.size();
		range_sum.resize(len * 4);
		init(ref, 0, len - 1, 1);
	}//Segment_Tree()


	//구간트리 초기화함수
	LL init(vector<LL>&ref, int left, int right, int node)
	{
		if (left == right)
			return range_sum[node] = ref[left];

		LL mid = (left + right) / 2;

		LL left_sum = init(ref, left, mid, node * 2);
		LL right_sum = init(ref, mid + 1, right, node * 2 + 1);

		return range_sum[node] = left_sum + right_sum;
	}//init()


	// 질의응답처리 함수
	LL query(int left, int right, int nodeLeft, int nodeRight, int node)
	{
		if (left > nodeRight || right < nodeLeft)
			return 0;

		else if (left <= nodeLeft && right >= nodeRight)
			return range_sum[node];

		LL mid = (nodeLeft + nodeRight) / 2;

		return query(left, right, nodeLeft, mid, node * 2) + query(left, right, mid + 1, nodeRight, node * 2 + 1);
	}//query()

	LL query(int left, int right)
	{
		return query(left - 1, right - 1, 0, len - 1, 1);
	}//query()


	// 구간트리갱신함수
	LL update(int idx, int newVal, int nodeLeft, int nodeRight, int node)
	{
		if (idx<nodeLeft || idx>nodeRight)
			return range_sum[node];

		else if (nodeLeft == nodeRight)
			return range_sum[node] = newVal;

		int mid = (nodeLeft + nodeRight) / 2;
		return range_sum[node] = update(idx, newVal, nodeLeft, mid, node * 2) + update(idx, newVal, mid + 1, nodeRight, node * 2 + 1);
	}//update()

	void update(int idx, int newVal)
	{
		update(idx - 1, newVal, 0, len - 1, 1);
	}//update()
};


int main()
{
	LL n, m, k;
	scanf("%lld %lld %lld", &n, &m, &k);

	vector<LL>arr(n);
	
	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);

	Segment_Tree st(arr);

	for (int i = 0; i < m + k; i++)
	{
		LL a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);

		if (a == 1)
			st.update(b, c);
		else
		   printf("%lld\n",st.query(b, c));
	}//for()
	return 0;
}//main()

