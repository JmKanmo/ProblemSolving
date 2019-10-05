#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;
typedef pair<pair<int, int>, int> GP_Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

int N, M, land_cnt, answer;
int board[11][11];
int visited[11][11];

int parent[7];
vector<GP_Pair> bridges;

bool comp(const GP_Pair& p1, const GP_Pair& p2)
{
	return p1.second < p2.second ? true : false;
}

void init()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= 6; i++) 
		parent[i] = i;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &board[i][j]);
}

void bfs(Pair start, int number)
{
	queue<Pair>q;
	q.push(start);
	visited[start.first][start.second] = number;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx1[i], pos.second + idx2[i]);

			if (next.first<1 || next.first>N || next.second<1 || next.second>M)
				continue;

			if (!visited[next.first][next.second] && board[next.first][next.second])
			{
				visited[next.first][next.second] = number;
				q.push(next);
			}
		}
	}
}

void setLandNumber()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (!visited[i][j] && board[i][j])
				bfs(Pair(i, j), ++land_cnt);
		}
	}
}

void makeBridge(Pair pos)
{
	for (int idx = 0; idx < 4; idx++)
	{
		Pair next = pos;
		int step = 0;

		for (int j = 1; j <= 10; j++)
		{
			next = Pair(next.first + idx1[idx], next.second + idx2[idx]);
			step += 1;

			if (next.first<1 || next.first>N || next.second<1 || next.second>M)
				break;

			if (visited[next.first][next.second])
			{
				if (step > 2 && visited[next.first][next.second] != visited[pos.first][pos.second])
				{
					bridges.push_back(GP_Pair(make_pair(visited[pos.first][pos.second], visited[next.first][next.second]), step - 1));
				}
				break;
			}
		}
	}
}

void setBridges()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (board[i][j] != 0)
				makeBridge(Pair(i, j));
		}
	}
}

int find_Parent(int idx)
{
	if (parent[idx] == idx)
		return parent[idx];

	return find_Parent(parent[idx]);
}

void merge(int n1, int n2)
{
	int p1 = find_Parent(n1);
	int p2 = find_Parent(n2);

	if (p1 < p2)
		parent[p2] = p1;
	else
		parent[p1] = p2;
}

bool setMST()
{
	sort(bridges.begin(), bridges.end(), comp);

	for (auto bridge : bridges)
	{
		int start = bridge.first.first;
		int end = bridge.first.second;
		int len = bridge.second;

		if (find_Parent(start) != find_Parent(end))
		{
			merge(start, end);
			answer += len;
		}
	}

	for (int i = 1; i <= land_cnt; i++)
	{
		if (find_Parent(i) != 1)
			return false;
	}
	return true;
}

int main()
{
	init();
	setLandNumber();
	setBridges();

	if (setMST())
		printf("%d\n", answer);
	else
		printf("-1\n");
	return 0;
}