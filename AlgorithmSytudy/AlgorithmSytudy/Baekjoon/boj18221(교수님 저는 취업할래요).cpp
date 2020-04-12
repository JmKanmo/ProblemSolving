#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

int N;
int board[1001][1001];
vector<Pair>student_pos, professor_pos;

void init()
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				student_pos.push_back(Pair(i, j));
			}
			else if (board[i][j] == 5) {
				professor_pos.push_back(Pair(i, j));
			}
		}
	}
}

void solve()
{
	int student_cnt = 0;

	if (student_pos.front().first == professor_pos.front().first) {
		if (student_pos.front().second > professor_pos.front().second) {
			for (int i = professor_pos.front().second; i <= student_pos.front().second; i++) {
				if (board[student_pos.front().first][i] == 1) student_cnt++;
			}
		}
		else {
			for (int i = professor_pos.front().second; i >= student_pos.front().second; i--) {
				if (board[student_pos.front().first][i] == 1) student_cnt++;
			}
		}
	}
	else if (student_pos.front().second == professor_pos.front().second) {
		if (student_pos.front().first > professor_pos.front().first) {
			for (int i = professor_pos.front().first; i <= student_pos.front().first; i++) {
				if (board[i][student_pos.front().second] == 1) student_cnt++;
			}
		}
		else {
			for (int i = professor_pos.front().first; i >= student_pos.front().first; i--) {
				if (board[i][student_pos.front().second] == 1) student_cnt++;
			}
		}
	}
	else {
		if (student_pos.front().first < professor_pos.front().first) {
			for (int i = student_pos.front().first; i <= professor_pos.front().first; i++)
			{
				if (student_pos.front().second < professor_pos.front().second) {
					for (int j = student_pos.front().second; j <= professor_pos.front().second; j++) {
						if (board[i][j] == 1) student_cnt++;
					}
				}
				else {
					for (int j = student_pos.front().second; j >= professor_pos.front().second; j--) {
						if (board[i][j] == 1) student_cnt++;
					}
				}
			}
		}
		else {
			for (int i = student_pos.front().first; i >= professor_pos.front().first; i--)
			{
				if (student_pos.front().second < professor_pos.front().second) {
					for (int j = student_pos.front().second; j <= professor_pos.front().second; j++) {
						if (board[i][j] == 1) student_cnt++;
					}
				}
				else {
					for (int j = student_pos.front().second; j >= professor_pos.front().second; j--) {
						if (board[i][j] == 1) student_cnt++;
					}
				}
			}
		}
	}
	//교수님과 학생간에 거리 재기
	int dist = sqrt(pow(student_pos.front().first - professor_pos.front().first, 2) +
		pow(student_pos.front().second - professor_pos.front().second, 2));

	if (student_cnt >= 3 && dist >= 5) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	init();
	solve();
	return 0;
}