#include "pch.h"
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

/*
2018.10.25
union-find �ڷᱸ�� �ǽ�
�κ�
*/


class DisjointSet
{
public:
	//�ʱ�ȭ ������
	DisjointSet(int n) :parent(n + 1), rank(n + 1, 1)
	{
		for (int i = 0; i <= n; i++)
			parent[i] = i;
	}

	//��Ʈã��(find) �Լ�
	int find(int n)
	{
		return parent[n] == n ? parent[n] : parent[n] = find(parent[n]);
	}//find()

	//�� ������ ������ ��ġ��(merge) �Լ�
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

	// �������Է�
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