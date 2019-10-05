#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

int lock_home;

vector<vector<int>>getRotatedArray(vector<vector<int>>arr)
{
	vector<vector<int>>ret = arr;
	int SIZE = arr.size();
	Pair LU = Pair(0, 0);
	Pair RU = Pair(0, arr[0].size() - 1);
	Pair LD = Pair(SIZE - 1, 0);
	Pair RD = Pair(SIZE - 1, arr[0].size() - 1);

	while (SIZE >= 2)
	{
		for (int t = 1; t <= 4; t++)
		{
			vector<int>line;

			if (t == 1)
			{
				Pair start = LU;

				for (int i = 0; i < RU.second - LU.second + 1; i++)
				{
					line.push_back(arr[start.first][start.second]);
					start = Pair(start.first, start.second + 1);
				}

				start = RU;

				for (int i = 0; i < RD.first - RU.first + 1; i++)
				{
					ret[start.first][start.second] = line[i];
					start = Pair(start.first + 1, start.second);
				}
			}
			else if (t == 2)
			{
				Pair start = RU;

				for (int i = 0; i < RD.first - RU.first + 1; i++)
				{
					line.push_back(arr[start.first][start.second]);
					start = Pair(start.first + 1, start.second);
				}

				start = RD;

				for (int i = 0; i < RD.second - LD.second + 1; i++)
				{
					ret[start.first][start.second] = line[i];
					start = Pair(start.first, start.second - 1);
				}
			}
			else if (t == 3)
			{
				Pair start = RD;

				for (int i = 0; i < RD.second - LD.second + 1; i++)
				{
					line.push_back(arr[start.first][start.second]);
					start = Pair(start.first, start.second - 1);
				}

				start = LD;

				for (int i = 0; i < LD.first - LU.first + 1; i++)
				{
					ret[start.first][start.second] = line[i];
					start = Pair(start.first - 1, start.second);
				}
			}
			else
			{
				Pair start = LD;

				for (int i = 0; i < LD.first - LU.first + 1; i++)
				{
					line.push_back(arr[start.first][start.second]);
					start = Pair(start.first - 1, start.second);
				}

				start = LU;

				for (int i = 0; i < RU.second - LU.second + 1; i++)
				{
					ret[start.first][start.second] = line[i];
					start = Pair(start.first, start.second + 1);
				}
			}
		}
		LU = Pair(LU.first + 1, LU.second + 1);
		RU = Pair(RU.first + 1, RU.second - 1);
		LD = Pair(LD.first - 1, LD.second + 1);
		RD = Pair(RD.first - 1, RD.second - 1);
		SIZE -= 2;
	}
	return ret;
}

bool convFunc(vector<vector<int>>key, vector<vector<int>>lock, int row_key_start, int row_key_end, int row_lock_start, int row_lock_end)
{
	int col_key_start = key.size() - 1;
	int col_key_end = key.size() - 1;
	int col_lock_start = 0;
	int col_lock_end = 0;

	while (col_lock_start < lock.size())
	{
		int clear_cnt = 0; // È¨ Ã¤¿îÈ½¼ö
		int temp_cls = col_lock_start;
		bool flag = true;

		for (int i = col_key_start; i <= col_key_end; i++, temp_cls++)
		{
			int temp_rls = row_lock_start;

			for (int j = row_key_start; j <= row_key_end; j++, temp_rls++)
			{
				if (key[i][j] == 1 && lock[temp_cls][temp_rls] == 1)
				{
					flag = false;
					break;
				}
				if (key[i][j] == 1 && lock[temp_cls][temp_rls] == 0) clear_cnt++;
			}
			if (!flag)
				break;
			else {
				if (clear_cnt == lock_home)
					return true;
			}
		}
		col_lock_end++;
		if (col_lock_end - col_lock_start >= key.size()) col_lock_start++;
		if (col_key_start >= 1) col_key_start--;
		if (col_lock_end >= lock.size()) col_key_end--;
	}
	return false;
}

bool checkKeyLock(vector<vector<int>> key, vector<vector<int>> lock)
{
	bool ret = false;
	int row_key_start = key[0].size() - 1;
	int row_key_end = key[0].size() - 1;
	int row_lock_start = 0;
	int row_lock_end = 0;

	while (row_lock_start < lock[0].size())
	{
		if (convFunc(key, lock, row_key_start, row_key_end, row_lock_start, row_lock_end >= lock[0].size() ? lock[0].size() - 1 : row_lock_end))
		{
			ret = true;
			break;
		}
		row_lock_end++;
		if (row_lock_end - row_lock_start >= key[0].size()) row_lock_start++;
		if (row_key_start >= 1) row_key_start--;
		if (row_lock_end >= lock[0].size()) row_key_end--;
	}
	return ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;
	vector<vector<int>>keys[4];

	for (int i = 0; i < lock.size(); i++)
	{
		for (int j = 0; j < lock[0].size(); j++)
		{
			if (lock[i][j] == 0)
				lock_home++;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		keys[i] = key;
		key = getRotatedArray(key);
	}

	for (int i = 0; i < 4; i++)
	{
		answer = checkKeyLock(keys[i], lock);
		if (answer) break;
	}

	return answer;
}

int main()
{
	

	return 0;
}