#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
int answer = 2e9, length;
int arr[100001];

void init()
{
	cin >> N >> S;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
}

void solve()
{
	int sum = 0;
	int Left = 1, Right = 1;

	while (true)
	{
		if (sum >= S)
		{
			answer = min(answer, length);
			sum -= arr[Left++];
			length--;
		}
		else
		{
			if (Right > N) break;
			sum += arr[Right++];
			length++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	init();
	solve();
	cout << (answer == 2e9 ? 0 : answer) << endl;
	return 0;
}