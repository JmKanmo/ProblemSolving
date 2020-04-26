#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

int getKtjCharacter(ll K)
{
	if (K % 2 == 0) {
		if (K % 4 == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
	else {
		while (K % 2 != 0) {
			K = ((K - 1) / 2);
		}
		if (K % 4 == 0) {
			return 0;
		}
		else {
			return 1;
		}
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
		ll K;
		cin >> K;
		cout << "#" << " " << t << " " << getKtjCharacter(K - 1) << "\n";
	}
	return 0;
}