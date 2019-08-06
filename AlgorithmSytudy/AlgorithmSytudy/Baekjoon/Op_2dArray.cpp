#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, int> Pair;

const int MAX_SIZE = 101;

int r, c, k;
int  col, row;
int min_time;

vector<vector<int>> op_R(vector<vector<int>>arr);
vector<vector<int>> op_C(vector<vector<int>>arr);
vector<Pair> sorted_func(map<int, int> param);
bool cmp(const pair<int, int>& a, const pair<int, int>& b);

int main()
{
	vector<vector<int>>arr(MAX_SIZE, vector<int>(MAX_SIZE));

	row = 3, col = 3;
	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &arr[i][j]);


	while (arr[r - 1][c - 1] != k)
	{
		if (min_time > 100) break;

		if (col >= row)
		{
			arr = op_R(arr);
		}
		else
		{
			arr = op_C(arr);
		}
		min_time++;
	}

	if (min_time > 100) cout << -1 << endl;
	else cout << min_time << endl;
	return 0;
}

vector<vector<int>> op_R(vector<vector<int>>arr)
{
	vector<map<int, int>>sorted(col);
	vector<vector<int>>new_arr;
	int MAX = 0;

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (arr[i][j] == 0)
				continue;
			else {
				if (sorted[i].count(arr[i][j]) == 0) {
					sorted[i].insert(Pair(arr[i][j], 1));
				}
				else {
					sorted[i][arr[i][j]]++;
				}
			}
		}
		MAX = max(MAX, (int)(sorted[i].size()));
	}

	if (MAX > 50) MAX = 50;
	row = MAX * 2 > row ? MAX * 2 : row;
	new_arr = vector<vector<int>>(MAX_SIZE, vector<int>(MAX_SIZE));

	for (int i = 0; i < col; i++)
	{
		vector<Pair> res = sorted_func(sorted[i]);
		for (int j = 0, k = 0; j < res.size(); j++) {
			new_arr[i][k++] = res[j].first;
			new_arr[i][k++] = res[j].second;
		}
	}
	return new_arr;
}

vector<vector<int>> op_C(vector<vector<int>>arr)
{
	vector<vector<int>>new_arr;
	vector<map<int, int>>sorted(row);
	int MAX = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[j][i] == 0)
				continue;
			else {
				if (sorted[i].count(arr[j][i]) == 0) {
					sorted[i].insert(Pair(arr[j][i], 1));
				}
				else {
					sorted[i][arr[j][i]]++;
				}
			}
		}
		MAX = max(MAX, (int)sorted[i].size());
	}

	if (MAX > 50) MAX = 50;
	col = MAX * 2 > col ? MAX * 2 : col;
	new_arr = vector<vector<int>>(MAX_SIZE, vector<int>(MAX_SIZE));

	for (int i = 0; i < row; i++)
	{
		vector<Pair> res = sorted_func(sorted[i]);
		for (int j = 0, k = 0; j < res.size(); j++) {
			new_arr[k++][i] = res[j].first;
			new_arr[k++][i] = res[j].second;
		}
	}
	return new_arr;
}

vector<Pair> sorted_func(map<int, int> param)
{
	vector<Pair>ret;
	for (auto elem : param) ret.push_back(Pair(elem.first, elem.second));
	sort(ret.begin(), ret.end(), cmp);
	return ret;
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}
