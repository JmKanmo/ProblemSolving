#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int N;
int MAX,MIN;
vector<char>opCard;
vector<int>numbers;

void init()
{
	cin >> N;

	for (int i = 0; i < 4; i++) {
		int n;
		cin >> n;
		opCard.push_back(n);
	}
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		numbers.push_back(n);
	}
}

void clear()
{
	opCard.clear();
	MAX = -2e9;
	MIN = 2e9;
	numbers.clear();
}

void solve(int idx, int val, int plus, int minus, int mul, int div)
{
	if (idx + 1 >= N) {
		MAX = max(MAX, val);
		MIN = min(MIN, val);
		return;
	}
	if (plus > 0) {
		solve(idx + 1, val + numbers[idx + 1], plus - 1, minus, mul, div);
	}
	if (minus > 0) {
		solve(idx + 1, val - numbers[idx + 1], plus, minus - 1, mul, div);
	}
	if (mul > 0) {
		solve(idx + 1, val * numbers[idx + 1], plus, minus, mul - 1, div);
	}
	if (div > 0) {
		solve(idx + 1, val / numbers[idx + 1], plus, minus, mul, div - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		clear();
		init();
		solve(0, numbers[0], opCard[0], opCard[1], opCard[2], opCard[3]);
		cout << "#" << t << " " << MAX - MIN << "\n";
	}
	return 0;
}