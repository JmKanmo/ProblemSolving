#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		int R;
		string S;
		string renew_s = "";
		cin >> R >> S;
		for (int j = 0; j < S.length(); j++)
		{
			string elem = S.substr(j, 1);
			for (int k = 0; k < R; k++) {
				renew_s += elem;
			}
		}
		cout << renew_s << "\n";
	}
	return 0;
}