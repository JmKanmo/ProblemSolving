#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> Pair;

const int idx_1[] = { 0,0,1,-1 };
const int idx_2[] = { 1,-1,0,0 };

int w, h;
char board[102][102];
int visited[102][102];
int keys;
int answer;

void init()
{
	memset(board, '.', sizeof(board));

	cin >> h >> w;

	for (int i = 1; i <= h; i++)
	{
		string str;
		cin >> str;

		for (int j = 1; j <= w; j++)
		{
			board[i][j] = str[j - 1];
		}
	}

	string str_key;
	keys = 0;
	answer = 0;
	cin >> str_key;

	if (str_key != "0")
	{
		for (int i = 0; i < str_key.length(); i++)
		{
			keys |= (1 << str_key[i] - 'a');
		}
	}
}

bool bfs()
{
	memset(visited, 0, sizeof(visited));
	queue<Pair>q;
	q.push(Pair(0, 0));
	visited[0][0] = 1;
	bool flag = false;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		if (board[pos.first][pos.second] == '$')
		{
			board[pos.first][pos.second] = '.';
			answer++;
		}

		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx_1[i], pos.second + idx_2[i]);

			if (next.first < 0 || next.first >= h + 2 || next.second < 0 || next.second >= w + 2)
				continue;

			if (board[next.first][next.second] == '*' || visited[next.first][next.second]) continue;

			char ch = board[next.first][next.second];

			if (ch >= 'a' && ch <= 'z')
			{
				keys |= (1 << ch - 'a');
				flag = true;
				board[next.first][next.second] = '.';
			}
			else if (ch >= 'A' && ch <= 'Z')
			{
				if (!(keys & (1 << ch - 'A'))) continue;
				board[next.first][next.second] = '.';
			}
			q.push(next);
			visited[next.first][next.second] = 1;
		}
	}
	return flag;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int test;
	cin >> test;

	for (int t = 0; t < test; t++)
	{
		init();
		while (bfs()) {}
		cout << answer << endl;
	}

	return 0;
}