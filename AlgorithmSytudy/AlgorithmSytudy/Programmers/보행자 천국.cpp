#include <vector>

using namespace std;

typedef long long LL;
int MOD = 20170805;

struct MovingWay
{
	LL up; //위에서 온 경로
	LL left; //왼쪽에서 온 경로
};

vector<vector<MovingWay>>dp;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	int answer = 0;
	dp = vector<vector<MovingWay>>(501, vector<MovingWay>(501));

	dp[0][0].left = 1;
	dp[0][0].up = 1;

	for (int i = 0; i < city_map.size(); i++)
	{
		for (int j = 0; j < city_map[i].size(); j++)
		{
			if (city_map[i][j] == 1)
				continue;
			else if (city_map[i][j] == 0)
			{
				//오른쪽이동
				int right_idx1 = i, right_idx2 = j + 1;

				if (right_idx2 < city_map[0].size() && (city_map[right_idx1][right_idx2] == 0 || city_map[right_idx1][right_idx2] == 2))
				{
					if (i == 0) {
						dp[right_idx1][right_idx2].left += (dp[i][j].left);
					}
					else {
						dp[right_idx1][right_idx2].left += (dp[i][j].left + dp[i][j].up);
					}
				}

				//아래쪽 이동
				int down_idx1 = i + 1, down_idx2 = j;

				if (down_idx1 < city_map.size() && (city_map[down_idx1][down_idx2] == 0 || city_map[down_idx1][down_idx2] == 2))
				{
					if (i == 0) {
						dp[down_idx1][down_idx2].up += (dp[i][j].left);
					}
					else {
						dp[down_idx1][down_idx2].up += (dp[i][j].left + dp[i][j].up);
					}
				}

				dp[right_idx1][right_idx2].left %= MOD;
				dp[down_idx1][down_idx2].up %= MOD;
			}
			else
			{
				//오른쪽이동
				int right_idx1 = i, right_idx2 = j + 1;

				if (right_idx2 < city_map[0].size() && (city_map[right_idx1][right_idx2] == 0 || city_map[right_idx1][right_idx2] == 2))
				{
					dp[right_idx1][right_idx2].left += (dp[i][j].left);
				}

				//아래쪽 이동
				int down_idx1 = i + 1, down_idx2 = j;

				if (down_idx1 < city_map.size() && (city_map[down_idx1][down_idx2] == 0 || city_map[down_idx1][down_idx2] == 2))
				{
					dp[down_idx1][down_idx2].up += (dp[i][j].up);
				}

				dp[right_idx1][right_idx2].left %= MOD;
				dp[down_idx1][down_idx2].up %= MOD;
			}
		}
	}
	return answer = (dp[city_map.size() - 1][city_map[0].size() - 1].left + dp[city_map.size() - 1][city_map[0].size() - 1].up) % MOD;
}

int main()
{
	solution(3, 3, { {0,2,0,0,0,2},{0,0,2,0,1,0},{1,0,0,2,2,0} });

	return 0;
}