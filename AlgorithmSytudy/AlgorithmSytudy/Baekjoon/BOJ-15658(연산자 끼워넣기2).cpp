#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int N;
int arr[12];
int op[5];
int MIN = 2e9;
int MAX = -2e9;

void init()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= 4; i++) {
		cin >> op[i];
	}
}

void solve(int idx, int sum, int plus, int minus, int mul, int div)
{
	if (idx >= N) {
		MIN = min(MIN, sum);
		MAX = max(MAX, sum);
		return;
	}

	if (plus)
		solve(idx + 1, sum + arr[idx + 1], plus - 1, minus, mul, div);

	if (minus)
		solve(idx + 1, sum - arr[idx + 1], plus, minus - 1, mul, div);

	if (mul)
		solve(idx + 1, sum * arr[idx + 1], plus, minus, mul - 1, div);

	if (div)
		solve(idx + 1, sum / arr[idx + 1], plus, minus, mul, div - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	init();
	solve(1, arr[1], op[1], op[2], op[3], op[4]);
	cout << MAX << endl;
	cout << MIN << endl;
	return 0;
}