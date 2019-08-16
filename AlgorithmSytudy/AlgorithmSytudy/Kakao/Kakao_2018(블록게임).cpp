#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
 000
 000
*/

bool TopToBottom(int idx1, int idx2, vector<vector<int>>& board)
{
	bool ret = false;

	for (int i = 0; i < idx1; i++)
	{
		if (board[i][idx2] != 0)
		{
			ret = true;
			break;
		}
	}
	return ret;
}

int type_1(int idx1, int idx2, vector<vector<int>>& board)
{
	int empty_cnt = 0;
	int block_cnt = 0;
	int block_type = -1;

	for (int i = idx1; i <= idx1 + 1; i++)
	{
		for (int j = idx2; j <= idx2 + 2; j++)
		{
			if (board[i][j] == 0) {
				if (TopToBottom(i, j, board))
					continue;
				else
					empty_cnt++;
			}
			else {
				if (block_type == -1) {
					block_type = board[i][j];
					block_cnt++;
				}
				else {
					if (block_type != board[i][j]) 
						continue;
					else {
						block_type = board[i][j];
						block_cnt++;
					}
				}
			}
		}
	}
	if (empty_cnt == 2 && block_cnt == 4)
	{
		for (int i = idx1; i <= idx1 + 1; i++)
		{
			for (int j = idx2; j <= idx2 + 2; j++)
			{
				board[i][j] = 0;
			}
		}
		return 1;
	}
	else
		return 0;
}

/*
00
00
00
*/
int type_2(int idx1, int idx2, vector<vector<int>>& board)
{
	int empty_cnt = 0;
	int block_cnt = 0;
	int block_type = -1;

	for (int i = idx1; i <= idx1 + 2; i++)
	{
		for (int j = idx2; j <= idx2 + 1; j++)
		{
			if (board[i][j] == 0) {
				if (TopToBottom(i, j, board))
					continue;
				else
					empty_cnt++;
			}
			else {
				if (block_type == -1) {
					block_type = board[i][j];
					block_cnt++;
				}
				else {
					if (block_type != board[i][j])
						continue;
					else {
						block_type = board[i][j];
						block_cnt++;
					}
				}
			}
		}
	}
	if (empty_cnt == 2 && block_cnt == 4)
	{
		for (int i = idx1; i <= idx1 + 2; i++)
		{
			for (int j = idx2; j <= idx2 + 1; j++)
			{
				board[i][j] = 0;
			}
		}
		return 1;
	}
	else
		return 0;
}

int solution(vector<vector<int>> board) {
	int answer = 0;

	while (true)
	{
		int cnt = 0;

		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{	
				int type1_cnt = 0;
				int type2_cnt = 0;

				if (i + 1 < board.size() && j + 2 < board.size()) {
					type1_cnt += type_1(i, j, board);
				}
				if (type1_cnt == 0 && i + 2 < board.size() && j + 1 < board.size()) {
					type2_cnt += type_2(i, j, board);
				}
				cnt += (type1_cnt + type2_cnt);
			}
		}
		if (cnt == 0)
			break;
		else
			answer += cnt;
	}
	return answer;
}

int main()
{

	return 0;
}