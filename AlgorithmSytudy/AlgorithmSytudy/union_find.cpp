#include "pch.h"
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

/*
2018.10.25
union-find 자료구조 실습
두부
*/


class DisjointSet
{
public:
	//초기화 생성자
	DisjointSet(int n) :parent(n + 1), rank(n + 1, 1)
	{
		for (int i = 0; i <= n; i++)
			parent[i] = i;
	}

	//루트찾기(find) 함수
	int find(int n)
	{
		return parent[n] == n ? parent[n] : parent[n] = find(parent[n]);
	}//find()

	//두 원소의 집합을 합치는(merge) 함수
	void merge(int a, int b)
	{
		a = find(a);
		b = find(b);

		if (a != b)
		{
			if (rank[a] >= rank[b])
			{
				parent[b] = a;
				if (rank[a] == rank[b]) rank[a]++;
			}
			else 
			{
				parent[a] = b;
				if (rank[b] == rank[b]) rank[b]++;
			}
		}
	}//merge()

private:
	vector<int>parent;
	vector<int>rank;

};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	DisjointSet ds(n);

	// 데이터입력
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a == 0)
			ds.merge(b, c);
		else
			ds.find(b) == ds.find(c) ? printf("YES\n") : printf("NO\n");
	}//for()
	return 0;
}//main()