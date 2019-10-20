#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

int R, C;
int answer;
char board[21][21];
int checked[100001];

void init()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> R >> C;

	for (int i = 1; i <= R; i++)
	{
		string str;
		cin >> str;

		for (int j = 1; j <= C; j++)
			board[i][j] = str[j - 1];
	}
}

void dfs(Pair start, int step)
{
	answer = max(answer, step);

	for (int i = 0; i < 4; i++)
	{
		Pair next = Pair(start.first + idx1[i], start.second + idx2[i]);

		if (next.first<1 || next.first>R || next.second<1 || next.second>C) continue;

		if (checked[board[next.first][next.second]] == 0)
		{
			checked[board[next.first][next.second]] = 1;
			dfs(next, step + 1);
			checked[board[next.first][next.second]] = 0;
		}
	}
}

int main()
{
	init();
	checked[board[1][1]] = 1;
	dfs(Pair(1, 1),1);
	checked[board[1][1]] = 0;
	printf("%d\n", answer);
	return 0;
}