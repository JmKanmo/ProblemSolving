#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int n;
map<int, int>hash_map;

void init()
{
	cin >> n;
	int a = 10, b = 1;

	while (b <= n)
	{
		hash_map[(n % a) / b]++;
		a *= 10;
		b *= 10;
	}
}

void solve()
{
	int checked_arr[] = { 0,1,2,8 };
	int checked_cnt = 0;

	int a = 10, b = 1;

	for (auto elem : hash_map)
	{
		int val = elem.first;
		bool flag = false;

		for (int i = 0; i < 4; i++)
		{
			if (checked_arr[i] == val) {
				flag = true;
				break;
			}
		}
		if (flag) {
			checked_cnt++;
		}
		else {
			cout << 0 << endl;
			return;
		}
	}

	if (checked_cnt == 4) {
		int cnt = 0;
		int val = 0;

		for (auto elem : hash_map) {
			if (cnt == 0) {
				val = elem.second;
			}
			else {
				if (val != elem.second) {
					cout << 2 << endl;
					return;
				}
				val = elem.second;
			}
			cnt++;
		}
		cout << 8 << endl;
	}
	else {
		cout << 1 << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	init();
	solve();
	return 0;
}