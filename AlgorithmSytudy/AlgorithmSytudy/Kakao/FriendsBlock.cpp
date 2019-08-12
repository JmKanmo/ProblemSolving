#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int idx1[] = { 0,1,1 };
const int idx2[] = { 1,1,0 };

bool search(int m, int n, vector<string>board,vector<vector<bool>>&visited)
{
	bool block_flag = false;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == '*') continue;

			int cnt = 0;
			char ch = board[i][j];
			vector<vector<bool>>temp = visited;
			temp[i][j] = true;
			cnt++;

			for (int k = 0; k < 3; k++)
			{
				int next_first = i + idx1[k];
				int next_second = j + idx2[k];

				if (next_first < 0 || next_first >= m || next_second < 0 || next_second >= n) 
					continue;

				char next_ch = board[next_first][next_second];
				if (ch == next_ch) {
					temp[next_first][next_second] = true;
					cnt++;
				}
			}
			if (cnt == 4) {
				visited = temp;
				block_flag = true;
			}
		}
	}
	return block_flag;
}

int erase(int m, int n, vector<string>& board, vector<vector<bool>>visited)
{
	int erase_cnt = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == true)
			{
				board[i][j] = '*';
				erase_cnt++;
			}
		}
	}
	return erase_cnt;
}

void down(int m, int n, vector<string>& board)
{
	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == '*') continue;
			int idx1 = i;
			int idx2 = j;

			while (idx1 + 1 <= m - 1 && board[idx1 + 1][idx2] == '*') {
				board[idx1 + 1][idx2] = board[idx1][idx2];
				board[idx1][idx2] = '*';
				idx1 += 1;
			}
		}
	}
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	vector<vector<bool>>visited;

	while (true)
	{
		visited = vector<vector<bool>>(m, vector<bool>(n));
		if (!search(m, n, board, visited))
			break;
		answer += erase(m, n, board, visited);
		down(m, n, board);
	}
	return answer;
}

int main()
{
	int n = solution(6, 6, { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" });
	return 0;
}