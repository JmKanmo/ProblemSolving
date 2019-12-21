#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

LL answer = 2e9;

void dfs(int idx, LL a, LL b, LL c)
{
	if (idx == 1)
	{
		dfs(idx + 1, a - 1, b, c);
		dfs(idx + 1, a + 1, b, c);
		dfs(idx + 1, a, b, c);
	}
	else if (idx == 2)
	{
		dfs(idx + 1, a, b - 1, c);
		dfs(idx + 1, a, b + 1, c);
		dfs(idx + 1, a, b, c);
	}
	else if (idx == 3)
	{
		dfs(idx + 1, a, b, c - 1);
		dfs(idx + 1, a, b, c + 1);
		dfs(idx + 1, a, b, c);
	}
	else
	{
		LL ret = abs(a - b) + abs(a - c) + abs(b - c);
		answer = min(answer, ret);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		LL a, b, c;
		answer = 2e9;

		cin >> a >> b >> c;

		dfs(1, a, b, c);
		cout << answer << endl;
	}

	return 0;
}