#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int table[16][16];
int visited[16];
int answer;

void init()
{
	answer = 2e9;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> table[i][j];
	}
}

int calc()
{
	//차이값반환
	vector<int> left_v;
	vector<int> right_v;

	for (int i = 0; i < N; i++)
	{
		if (visited[i]) left_v.push_back(i);
		else right_v.push_back(i);
	}

	int left_sum = 0, right_sum = 0;

	for (int i = 0; i < left_v.size(); i++)
	{
		for (int j = 0; j < left_v.size(); j++)
		{
			if (i != j)
			{
				left_sum += table[left_v[i]][left_v[j]];
			}
		}
	}

	for (int i = 0; i < right_v.size(); i++)
	{
		for (int j = 0; j < right_v.size(); j++)
		{
			if (i != j)
			{
				right_sum += table[right_v[i]][right_v[j]];
			}
		}
	}

	return abs(left_sum - right_sum);
}

void dfs(int idx, int cnt)
{
	if (cnt >= N / 2)
	{
		answer = min(answer, calc());
		return;
	}

	for (int i = idx + 1; i < N; i++)
	{
		visited[i] = 1;
		dfs(i, cnt + 1);
		visited[i] = 0;
	}
}

int main()
{
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		init();
		dfs(-1, 0);
		cout << "#" << t << " " << answer << "\n";
	}
	return 0;
}