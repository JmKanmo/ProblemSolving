#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

struct Rotate {
	int r;
	int c;
	int s;
};

vector<vector<int>>arr;

int N, M, K;
vector<bool>visited(6);
Rotate rot[6];
int answer = 987654321;

vector<vector<int>> rotate_arr(Pair left_up, Pair right_down, vector<vector<int>>arr)
{
	int diff = right_down.first - left_up.first + 1;

	while (diff > 1)
	{
		vector<vector<int>>temp(5, vector<int>(diff + 1));

		//temp에 원소저장
		for (int i = left_up.first + 1, cnt = 1; i <= right_down.first; i++) temp[1][cnt++] = arr[i][left_up.second];
		for (int i = left_up.second + 1, cnt = 1; i <= right_down.second; i++) temp[2][cnt++] = arr[right_down.first][i];
		for (int i = right_down.first - 1, cnt = 1; i >= left_up.first; i--) temp[3][cnt++] = arr[i][right_down.second];
		for (int i = right_down.second - 1, cnt = 1; i >= left_up.second; i--) temp[4][cnt++] = arr[left_up.first][i];

		//한칸씩 옮기기
		for (int i = left_up.first, cnt = 1; i < right_down.first; i++) arr[i][left_up.second] = temp[1][cnt++];
		for (int i = left_up.second, cnt = 1; i < right_down.second; i++) arr[right_down.first][i] = temp[2][cnt++];
		for (int i = right_down.first, cnt = 1; i > left_up.first; i--) arr[i][right_down.second] = temp[3][cnt++];
		for (int i = right_down.second, cnt = 1; i > left_up.second; i--) arr[left_up.first][i] = temp[4][cnt++];

		diff -= 2;
		left_up = Pair(left_up.first + 1, left_up.second + 1);
		right_down = Pair(right_down.first - 1, right_down.second - 1);
	}
	return arr;
}

void setMinimum(vector<vector<int>>arr)
{
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;

		for (int j = 1; j <= M; j++)
		{
			sum += arr[i][j];
		}
		answer = min(answer, sum);
	}
}

void solve(vector<vector<int>>arr, vector<bool>visited, int cnt)
{
	for (int i = 0; i < K; i++)
	{
		if (visited[i]) continue;
		visited[i] = true;
		vector<vector<int>>temp = rotate_arr(Pair(rot[i].r - rot[i].s, rot[i].c - rot[i].s), Pair(rot[i].r + rot[i].s, rot[i].c + rot[i].s), arr);
		if (cnt == K) setMinimum(temp);
		solve(temp, visited, cnt + 1);
		visited[i] = false;
	}
}

int main()
{
	cin >> N >> M >> K;
	arr = vector<vector<int>>(N + 1, vector<int>(M + 1));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			scanf("%d", &arr[i][j]);
	}

	for (int i = 0; i < K; i++) scanf("%d %d %d", &rot[i].r, &rot[i].c, &rot[i].s);

	solve(arr, visited, 1);
	cout << answer << endl;
	return 0;
}