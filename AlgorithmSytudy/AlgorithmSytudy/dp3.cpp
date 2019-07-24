#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> Pair;

/*
2018.11.08
DP 실습(BOJ 14501)
두부
*/

int main()
{
	int n;
	scanf("%d", &n);

	vector<Pair>dp(15);
	vector<int>temp(15);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		dp[i] = make_pair(a, b);
		temp[i] = b;
	}//for()

	int cost = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + dp[i].first; j <= n; j++)
		{
			if (j + dp[j].first <= n)
			{
				dp[j].second = max(dp[j].second, dp[i].second + temp[j]);
				cost = cost < dp[j].second ? dp[j].second : cost;
			}
		}//for()		
	}//for()

	printf("%d\n", cost);
	return 0;
}//main()