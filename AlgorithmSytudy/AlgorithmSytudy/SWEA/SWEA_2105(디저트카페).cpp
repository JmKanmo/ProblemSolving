#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx1[] = { 1,1,-1,-1 }; //방향좌표
const int idx2[] = { 1,-1,-1,1 };

int board[21][21];
int counter[101]; //디저트종류
int N;
int answer;

//데이터입력함수
void init()
{
	answer = -1;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}
}

//범위초과체크
bool outofRange(Pair pos) { return pos.first<1 || pos.first>N || pos.second<1 || pos.second>N ? true : false; }

//dfs백트래킹함수
void dfs(Pair start, Pair pos, int depth, int cnt)
{
	//방향그대로
	Pair next = Pair(pos.first + idx1[depth], pos.second + idx2[depth]);

	if (outofRange(next) != true)
	{
		if (!counter[board[next.first][next.second]])
		{
			counter[board[next.first][next.second]]++;
			dfs(start, next, depth, cnt + 1);
			counter[board[next.first][next.second]]--;
		}
		if (start == next)
		{
			answer = max(answer, cnt);
		}
	}

	//방향전환	
	depth += 1;
	if (depth > 3) return;
	next = Pair(pos.first + idx1[depth], pos.second + idx2[depth]);

	if (outofRange(next) != true)
	{
		if (!counter[board[next.first][next.second]])
		{
			counter[board[next.first][next.second]]++;
			dfs(start, next, depth, cnt + 1);
			counter[board[next.first][next.second]]--;
		}
		if (start == next)
		{
			answer = max(answer, cnt);
		}
	}
}

int main()
{
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		init();
		
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				counter[board[i][j]]++;
				dfs(Pair(i, j), Pair(i, j), 0, 1);
				counter[board[i][j]]--;
			}
		}
		printf("#%d %d\n", t, answer);
	}
	return 0;
}