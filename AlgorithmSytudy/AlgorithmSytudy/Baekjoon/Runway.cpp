#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

int n, L;
int board[101][101];
vector<vector<bool>>visited;
int cnt;

bool check_width(int prev_val, Pair prev_pos, Pair cur_pos, int comp)
{
	int prev_idx1 = prev_pos.first;
	int prev_idx2 = prev_pos.second;
	int cur_idx1 = cur_pos.first;
	int cur_idx2 = cur_pos.second;
	bool flag = true;
	
	if (comp == 1)
	{
		// prev_val > cur 
		for (int i = cur_idx2; i <= prev_idx2 + L; i++) {
			if (prev_val - board[cur_idx1][i] != 1 || visited[cur_idx1][i]) {
				flag = false;
				break;
			}
			visited[cur_idx1][i] = true;
		}
	}
	else
	{
		// prev_val < cur
		for (int i = prev_idx2; i >= cur_idx2 - L; i--) {
			if (board[cur_idx1][cur_idx2] - board[prev_idx1][i] != 1 || visited[prev_idx1][i]) {
				flag = false;
				break;
			}
			visited[prev_idx1][i] = true;
		}
	}
	return flag;
}

bool check_height(int prev_val, Pair prev_pos, Pair cur_pos, int comp)
{
	int prev_idx1 = prev_pos.first;
	int prev_idx2 = prev_pos.second;
	int cur_idx1 = cur_pos.first;
	int cur_idx2 = cur_pos.second;
	bool flag = true;

	if (comp == 1)
	{
		// prev_val > cur
		for (int i = cur_idx1; i <= prev_idx1 + L; i++) {
			if (prev_val - board[i][cur_idx2] != 1 || visited[i][cur_idx2]) {
				flag = false;
				break;
			}
			visited[i][cur_idx2] = true;
		}
	}
	else
	{
		// prev_val < cur
		for (int i = prev_idx1; i >= cur_idx1 - L; i--) {
			if (board[cur_idx1][cur_idx2] - board[i][prev_idx2] != 1 || visited[i][prev_idx2]) {
				flag = false;
				break;
			}
			visited[i][prev_idx2] = true;
		}
	}
	return flag;
}

void setCntOfLoad()
{
	//1Â÷
	visited = vector<vector<bool>>(101, vector<bool>(101));

	for (int i = 1; i <= n; i++) {
		int prev_val = 0;
		Pair prev_pos;
		bool flag = true;

		for (int j = 1; j <= n; j++) {
			if (prev_val != 0 && board[i][j] != prev_val)
			{
				if (prev_val > board[i][j]) {
					flag = check_width(prev_val, prev_pos, Pair(i, j), 1);
					if (flag)
					{
						j += (L-1);
						prev_val = board[i][j];
						prev_pos = Pair(i, j);
					}
				}
				else if (prev_val < board[i][j]) {
					flag = check_width(prev_val, prev_pos, Pair(i, j), 2);
					prev_val = board[i][j];
					prev_pos = Pair(i, j);
				}
				if (!flag) break;
			}
			else {
				prev_val = board[i][j];
				prev_pos = Pair(i, j);
			}
		}
		if (flag) cnt++;
	}

	//2Â÷
	visited = vector<vector<bool>>(101, vector<bool>(101));

	for (int i = 1; i <= n; i++) {
		int prev_val = 0;
		Pair prev_pos;
		bool flag = true;

		for (int j = 1; j <= n; j++) {
			if (prev_val != 0 && prev_val != board[j][i])
			{
				if (prev_val > board[j][i]) {
					flag = check_height(prev_val, prev_pos, Pair(j, i), 1);
					if (flag)
					{
						j += (L - 1);
						prev_val = board[j][i];
						prev_pos = Pair(j, i);
					}
				}
				else if (prev_val < board[j][i]) {
					flag = check_height(prev_val, prev_pos, Pair(j, i), 2);
					prev_val = board[j][i];
					prev_pos = Pair(j, i);
				}
				if (!flag) break;
			}
			else {
				prev_val = board[j][i];
				prev_pos = Pair(j, i);
			}
		}
		if (flag) cnt++;
	}
}

int main()
{
	cin >> n >> L;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	setCntOfLoad();
	cout << cnt << endl;
	return 0;
}