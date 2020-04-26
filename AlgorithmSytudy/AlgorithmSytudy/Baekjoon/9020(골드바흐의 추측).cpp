#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

vector<bool>isPrimeNumber(10001, true);

void setPrimeNumbers()
{
	for (int i = 2; i <= sqrt(10000); i++)
	{
		for (int j = i + i; j <= 10000; j += i) {
			isPrimeNumber[j] = false;
		}
	}
}

pair<int, int> getGoldPartition(int n)
{
	int diff = 2e9;
	pair<int, int>ret;

	for (int i = 1; i <= n / 2; i++)
	{
		if (isPrimeNumber[i] && isPrimeNumber[n - i]) {
			int d = abs(i - (n - i));
			if (diff > d) {
				diff = d;
				ret.first = i;
				ret.second = n - i;
			}
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	setPrimeNumbers();
	isPrimeNumber[0] = false, isPrimeNumber[1] = false;

	for (int t = 1; t <= tc; t++)
	{
		int n;
		cin >> n;
		pair<int, int> ret = getGoldPartition(n);
		cout << ret.first << " " << ret.second << "\n";
	}
	return 0;
}