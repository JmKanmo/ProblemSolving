#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Board
{
	int status = 0;//상태
	long long case_1 = 0;//가로
	long long case_2 = 0;//세로
	long long case_3 = 0;//대각선
};

Board board[33][33];
int N;

void init()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &board[i][j].status);
}

bool check(int idx1, int idx2)
{
	if ((idx1<1 || idx1>N || idx2<1 || idx2>N) || board[idx1][idx2].status == 1)
		return false;
	else
		return true;
}

void solve()
{
	board[1][2].case_1 = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (check(i, j + 1)) board[i][j + 1].case_1 += (board[i][j].case_1 + board[i][j].case_3);
			if (check(i + 1, j)) board[i + 1][j].case_2 += (board[i][j].case_2 + board[i][j].case_3);
			if (check(i, j + 1) && check(i + 1, j) && check(i + 1, j + 1)) board[i + 1][j + 1].case_3 += (board[i][j].case_1 + board[i][j].case_2 + board[i][j].case_3);
		}
	}
}

int main()
{
	init();
	solve();
	printf("%lld\n", board[N][N].case_1 + board[N][N].case_2 + board[N][N].case_3);
	return 0;
}