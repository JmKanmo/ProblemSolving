#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[13];
int dp[13];

int main() 
{
	int test;

	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		int one_day_cost, one_month_cost, three_month_cost, one_year_cost;

		scanf("%d %d %d %d", &one_day_cost, &one_month_cost, &three_month_cost, &one_year_cost);

		for (int i = 1; i <= 12; i++)
		{
			scanf("%d", &arr[i]);
			dp[i] = 0;
		}

		for (int day = 1; day <= 12; day++)
			dp[day] = min(min(dp[day - 1] + arr[day] * one_day_cost, dp[day - 1] + one_month_cost), dp[day - 3] + three_month_cost);

		int answer = min(dp[12], one_day_cost);
		printf("#%d %d\n", t, answer);
	}

	return 0;
}