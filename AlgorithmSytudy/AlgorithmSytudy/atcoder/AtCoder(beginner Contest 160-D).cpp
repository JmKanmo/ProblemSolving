#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int  n, x, y;
	cin >> n >> x >> y;
	map<int, int>mp;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int dist = j - i;
			dist = min(dist, (abs(i - x) + 1 + abs(y - j)));
			dist = min(dist, (abs(i - y) + 1 + abs(x - j)));
			mp[dist]++;
		}
	}

	for (int i = 1; i < n; i++)
		cout << mp[i] << endl;

	return 0;
}