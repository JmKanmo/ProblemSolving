#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

/*
2018.11.14
BFS 실습(BOJ 7576)
두부
*/

typedef pair<int, int> Pair;

#define GET(K) K==0? 1:0

int main()
{
	int M, N;
	int**arr = NULL, **visit = NULL;
	int day = 0, r1 = 0, r2 = 1, cnt = 0, cnt1 = 0;
	bool bVar = false, flag = false;
	queue<Pair>q[2];

	scanf("%d %d", &M, &N);

	arr = new int*[N];
	visit = new int*[N];

	for (int i = 0; i < N; i++) {
		arr[i] = new int[M];
		visit[i] = new int[M];
	}//for()

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			visit[i][j] = 0;
		}//for()

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1) {
				q[r1].push(make_pair(i, j));
				visit[i][j] = 1;
				cnt++;
			}
			else if (arr[i][j] == -1)
				cnt1++;
		}//for()

	if (cnt == N * M - cnt1)
	{
		printf("0\n");
		return 0;
	}

	while (!bVar)
	{
		while (q[r1].empty() != true)
		{
			int idx1 = q[r1].front().first;
			int idx2 = q[r1].front().second;
			q[r1].pop();

			for (int i = 1; i <= 4; i++)
			{
				int temp1 = idx1;
				int temp2 = idx2;

				if (i == 1) temp2 -= 1;
				else if (i == 2) temp2 += 1;
				else if (i == 3) temp1 -= 1;
				else temp1 += 1;

				if ((temp1 < 0 || temp1 >= N || temp2 < 0 || temp2 >= M) || visit[temp1][temp2] || arr[temp1][temp2] != 0)
					continue;
				else {
					visit[temp1][temp2] = 1;
					q[r2].push(make_pair(temp1, temp2));
					arr[temp1][temp2] = 1;
					cnt++;
				}
			}//for()
		}//while()
		r1 = GET(r1);
		r2 = GET(r2);
		if (q[r1].empty() && q[r2].empty())
			bVar = true;
		else
			day++;
	}//while()

	if (N*M - cnt1 == cnt)
		printf("%d\n", day);
	else
		printf("-1\n");

	for (int i = 0; i < N; i++) {
		delete[] arr[i];
		delete[] visit[i];
	}//for()
	delete[]arr;
	delete[]visit;
	return 0;
}//main()