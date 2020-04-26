#include <stdio.h>
#include <iostream>
#include <memory.h>

using namespace std;

int tt;
int N, M, T;
int K, a, b;

char arr[305][105][105];
int acc[305][105][105];


void DBGPrint(int tt) {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << arr[tt][i][j];
		}
		cout << "\n";
	}
	cout << endl;
}


void AnsPrint(int tt) {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << arr[tt][i][j];
		}
		cout << "\n";
	}
}

void init()
{
	cin >> N >> M >> T;
	cin >> K >> a >> b;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[0][i][j];
}

void setAcc()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			acc[tt][i][j] = acc[tt][i][j - 1] + acc[tt][i - 1][j] - acc[tt][i - 1][j - 1] + (arr[tt][i][j] == '*');
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	while (tt <= T) {

		setAcc();

		int x1, y1, x2, y2;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				x1 = j - K;
				y1 = i - K;

				x2 = j + K;
				y2 = i + K;

				if (x1 < 1) x1 = 1;
				if (y1 < 1) y1 = 1;

				if (x2 > M) x2 = M;
				if (y2 > N) y2 = N;

				int ans = acc[tt][y2][x2] - acc[tt][y1 - 1][x2] - acc[tt][y2][x1 - 1] + acc[tt][y1 - 1][x1 - 1];

				if (arr[tt][i][j] == '*')
					ans--;

				if (arr[tt][i][j] == '*') {

					if (a <= ans && ans <= b)
						arr[tt + 1][i][j] = '*';

					else if (ans < a || ans > b)
						arr[tt + 1][i][j] = '.';
				}
				else {
					if (a < ans && ans <= b)
						arr[tt + 1][i][j] = '*';
					else
						arr[tt + 1][i][j] = '.';
				}
			}
		}
		tt++;
		//    DBGPrint(tt);
	}

	AnsPrint(T);
	return 0;
}
