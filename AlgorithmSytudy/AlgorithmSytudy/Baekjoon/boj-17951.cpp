#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int arr[100001];

int main() 
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) cin >> arr[i];

	int left = 0, right = 2e9;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		int cnt = 0, sum = 0;

		for (int i = 0; i < N; i++) {
			sum += arr[i];
			if (sum >= mid) {
				sum = 0;
				cnt++;
			}
		}
		
		if (cnt >= K) left = mid + 1;
		else right = mid - 1;
	}

	cout << right << endl;
	return 0;
}