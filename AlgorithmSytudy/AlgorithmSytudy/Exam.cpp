#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long dp[1000001];
int first_sub, second_sub; // 총감독관,부감독관 감독인원
long long first_cnt, second_cnt;

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) scanf("%lld", &dp[i]);
	cin >> first_sub >> second_sub;
	scanf("%lld %lld", &first_sub, &second_sub);

	for (int i = 1; i <= n; i++) {
		dp[i] -= first_sub;
		if (dp[i] < 0) dp[i] = 0;
		first_cnt++;
	}

	for (int i = 1; i <= n; i++) {
		if (dp[i] != 0) {
			if (dp[i] <= second_sub) {
				second_cnt += 1;
				dp[i] = 0;
			}
			else {
				if (dp[i] > second_sub) {
					while (dp[i] > second_sub) {
						second_cnt += (dp[i] / second_sub);
						if (dp[i] >= second_sub) {
							dp[i] %= second_sub;
						}
					}
					if (dp[i] != 0) {
						second_cnt++;
						dp[i] = 0;
					}
				}
			}
		}
	}
	cout << first_cnt + second_cnt << endl;

	return 0;
}