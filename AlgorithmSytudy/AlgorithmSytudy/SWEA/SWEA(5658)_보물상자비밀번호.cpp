#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, K;
string str;
map<int, int> hash_map;

void init()
{
	scanf("%d %d", &N, &K);
	getchar();
	cin >> str;
	hash_map.clear();
}

void rotate()
{
	string temp = str;

	for (int i = 0; i < str.length() - 1; i++)
		str[i + 1] = temp[i];

	str[0] = temp[temp.length() - 1];
}

void solve()
{
	int len = N / 4;

	while (true)
	{
		bool flag = false;

		for (int i = 1, idx = 0; i <= 4; i++)
		{
			int sum = 0;

			for (int j = 0; j < len; j++)
			{
				int n = str[idx++];

				if (n >= 'A') {
					n = n - 'A' + 10;
				}
				else {
					n -= '0';
				}
				n *= pow(16, len - j - 1);
				sum += n;
			}
			if (hash_map.count(sum) == 0)
			{
				hash_map[sum] = 1;
				flag = true;
			}
		}
		if (flag == false)
			break;
		rotate();
	}
}

int find()
{
	int idx = hash_map.size() - K;
	int cnt = 0;

	for (auto elem : hash_map)
	{
		if (idx == cnt)
			return elem.first;
		cnt++;
	}
}

int main()
{
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		init();
		solve();
		printf("#%d %d\n", t, find());
	}
	return 0;
}