#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int>Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

bool visited[101][101] = { false, };

int bfs(int m, int n, Pair start, vector<vector<int>>& picture)
{
	queue<Pair>q;
	int area_cnt = 1;
	q.push(start);
	visited[start.first][start.second] = true;

	while (q.empty() != true)
	{
		Pair pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Pair next = Pair(pos.first + idx1[i], pos.second + idx2[i]);

			if (next.first<0 || next.first>=m || next.second<0 || next.second>=n)
				continue;

			if (visited[next.first][next.second] || picture[next.first][next.second]==0)
				continue;

			if (picture[pos.first][pos.second] == picture[next.first][next.second])
			{
				q.push(next);
				visited[next.first][next.second] = true;
				area_cnt++;
			}
		}
	}
	return area_cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	fill(&visited[0][0], &visited[0][0] + 101 * 101, false);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (picture[i][j] != 0 && visited[i][j] == false)
			{
				max_size_of_one_area = max(max_size_of_one_area, bfs(m, n, Pair(i, j), picture));
				number_of_area += 1;
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main()
{
	solution(6, 4, { {1, 1, 1, 0}, { 1, 2, 2, 0 }, { 1, 0, 0, 1 }, { 0, 0, 0, 1 }, { 0, 0, 0, 3 }, { 0, 0, 0, 3} });

	return 0;
}