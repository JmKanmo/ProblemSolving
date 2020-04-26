#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, X;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> X;

	if (N * 1 <= X && N * 26 >= X) {
		string money = "";
		for (int i = 1; i <= N; i++) money += 'A';
		X -= N;
		for (int i = N - 1; i >= 0; i--) {
			int temp = min(25, X);
			money[i] += temp;
			if (X - temp >= 0) {
				X -= temp;
			}
		}
		cout << money << "\n";
	}
	else {
		cout << "!" << "\n";
	}
	return 0;
}