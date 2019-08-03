#include "pch.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/*
2018.10.30 
크루스칼알고리즘 구현
두부
*/


#define MAX 10001

typedef pair<int, int> Pair;

vector<Pair>adj[MAX];
int n, m;

// 사이클 확인을 위한 union-find 클래스 
class Disjoint
{
public:
	vector<int>parent;
	vector<int>rank;

	Disjoint(int n) :parent(n + 1), rank(n + 1)
	{
		for (int i = 1; i <= n; i++)
			parent[i] = i;
	}//Disjoint()

	int find(int n)
	{
		if (n == parent[n])
			return n;

		return parent[n] = find(parent[n]);
	}//find()

	void merge(int n1, int n2)
	{
		n1 = find(n1);
		n2 = find(n2);

		if (rank[n1] >= rank[n2])
		{
			parent[n2] = n1;

			if (rank[n1] == rank[n2])
				rank[n1]++;
		}
		else
		{
			parent[n1] = n2;
		}
	}//merge()
};


//크루스칼 알고리즘 구현

int kruskal()
{
	int min = 0;
	vector<pair<int, Pair>>edges;
	Disjoint set(n);

	for (int i = 1; i <= n; i++)
	{
		for (auto vertex : adj[i])
		{
			int v = vertex.first;
			int cost = vertex.second;
			edges.push_back(make_pair(cost, make_pair(i, v)));
		}//for()
	}//for()

	sort(edges.begin(), edges.end());

	for (auto edge : edges)
	{
		int cost = edge.first;
		int v1 = edge.second.first;
		int v2 = edge.second.second;

		if (set.find(v1) == set.find(v2))
			continue;

		set.merge(v1, v2);
		min += cost;
	}//for()
	return min;
}//kruskal()

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back(make_pair(b, c));
	}//for()

	printf("%d\n", kruskal());
	return 0;
}//main()
