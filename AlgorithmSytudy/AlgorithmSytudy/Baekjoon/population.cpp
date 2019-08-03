#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pos_pair;
typedef pair<Pos_pair, int> unit_pair;

const int idx1[] = { 0,0,1,-1 }; //µ¿¼­³²ºÏ
const int idx2[] = { 1,-1,0,0 };

int N, L, R;
int board[51][51];
vector<vector<bool>>visited;
int answer;

vector<unit_pair>bfs(Pos_pair start)
{
	queue<Pos_pair>q;
	vector<unit_pair>unit;

	q.push(start);
	visited[start.first][start.second] = true;
	unit.push_back(unit_pair(start, board[start.first][start.second]));

	while (q.empty() != true)
	{
		Pos_pair pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Pos_pair next = Pos_pair(pos.first + idx1[i], pos.second + idx2[i]);

			if (next.first<1 || next.first>N || next.second<1 || next.second>N) continue;

			int diff = abs(board[next.first][next.second] - board[pos.first][pos.second]);

			if ((diff >= L && diff <= R) && visited[next.first][next.second] != true)
			{
				unit.push_back(unit_pair(next, board[next.first][next.second]));
				visited[next.first][next.second] = true;
				q.push(next);
			}
		}
	}
	return unit;
}

void setValue(vector<unit_pair>unit)
{
	int sum = 0;
	for (int i = 0; i < unit.size(); i++) sum += unit[i].second;
	for (int i = 0; i < unit.size(); i++) board[unit[i].first.first][unit[i].first.second] = sum / unit.size();
}

int main()
{
	scanf("%d %d %d", &N, &L, &R);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &board[i][j]);

	while (true)
	{
		bool flag = false;
		visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1));

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (visited[i][j] != true)
				{
					vector<unit_pair>unit = bfs(Pos_pair(i, j));
					if (unit.size() == 1)
						continue;
					flag = true;
					setValue(unit);
				}
			}
		}
		if (flag == false)
			break;
		else
			answer++;
	}
	cout << answer << endl;
	return 0;
}