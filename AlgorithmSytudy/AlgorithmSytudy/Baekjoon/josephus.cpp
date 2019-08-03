#include "pch.h"
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

/*
2018.10.23
�����۽�����(���� 1158)
�κ�
*/


//�����۽��˰��� �����Լ�

void josephus(int n, int m)
{
	queue<int>q; //�˰��� �ʿ��� ť

	for (int i = 1; i <= n; i++)
		q.push(i);

	cout << "<";

	while (q.size() != 0)
	{
		if (q.size() == 1)
		{
			cout << q.front() << ">";
			q.pop();
			break;
		}
		for (int i = 1; i < m; i++)
		{
			q.push(q.front());
			q.pop();
		}//for()
		cout << q.front() << ", ";
		q.pop();
	}//while()
}//josephus()

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	//�����۽� �Լ� ȣ��
	josephus(n, m);
	return 0;
}//main()
