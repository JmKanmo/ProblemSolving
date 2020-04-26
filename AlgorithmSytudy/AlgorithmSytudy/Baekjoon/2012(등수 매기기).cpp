#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int>arr;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		arr.push_back(n);
	}

	sort(arr.begin(), arr.end());
	long long answer = 0;
	for (int i = 1; i <= N; i++) {
		answer += abs(i - arr[i - 1]);
	}
	cout << answer << endl;
	return 0;
}