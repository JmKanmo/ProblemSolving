#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

int N, M;
int board[51][51];
vector<Pair>home;
vector<Pair>chicken_house;
vector<Pair>arr;
int answer = 2e9;

void init()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &board[i][j]);
			if (board[i][j] == 2)
				chicken_house.push_back(Pair(i, j));
			if (board[i][j] == 1)
				home.push_back(Pair(i, j));
		}
	}
}

void dfs(int idx, int cnt, vector<Pair>arr)
{
	if (cnt == M)
	{
		int sum = 0;

		for (int i = 0; i < home.size(); i++)
		{
			int MIN = 2e9;

			for (int j = 0; j < arr.size(); j++)
			{
				MIN = min(MIN, abs(home[i].first - arr[j].first) + abs(home[i].second - arr[j].second));
			}
			sum += MIN;
		}
		answer = min(answer, sum);
		return;
	}

	for (int i = idx + 1; i < chicken_house.size(); i++)
	{
		vector<Pair>temp = arr;
		temp.push_back(chicken_house[i]);
		dfs(i, cnt + 1, temp);
	}
}

int main()
{
	cin >> N >> M;
	init();
	dfs(-1, 0, arr);
	printf("%d\n", answer);
	return 0;
}