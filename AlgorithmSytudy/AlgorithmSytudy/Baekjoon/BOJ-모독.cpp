#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n;
	vector<int>v;
	int minus = 1;
	int answer = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (v[i] >= minus) {
			v[i] -= minus;
			answer += v[i];
			minus++;
		}
	}

	cout << answer << endl;
	return 0;
}