#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> strs, string t)
{
	int answer = 0;
	vector<int>dp(t.length(), 2e9);

	for (int i = 0; i < t.length(); i++)
	{
		for (int j = 0; j < strs.size(); j++)
		{
			if (((i + 1) - strs[j].length()) < 0)
				continue;

			bool flag = true;

			for (int k = 0; k < strs[j].length(); k++)
			{
				if (strs[j][strs[j].length() - 1 - k] != t[i - k])
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				if ((i + 1) - strs[j].length() > 0)
				{
					dp[i] = min(dp[i], dp[i - strs[j].length()] + 1);
				}
				else
				{
					dp[i] = 1;
				}
			}
		}
	}
	return dp[t.length() - 1] == 2e9 ? -1 : dp[t.length() - 1];
}