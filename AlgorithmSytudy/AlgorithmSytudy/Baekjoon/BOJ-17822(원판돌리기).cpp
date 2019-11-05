#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

struct Spin
{
	int x;
	int d;
	int k;

	Spin() {}
};

const int INF = -2e9;
int circle[51][51];
int N, M, T;
Spin spin[51];

void init()
{
	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> circle[i][j];
		}
	}

	for (int i = 1; i <= T; i++)
	{
		cin >> spin[i].x >> spin[i].d >> spin[i].k;
	}
}

int getNextPos(int pos, int d, int k)
{
	if (d == 0)
	{
		//시계
		for (int cnt = 0; cnt < k; cnt++)
			pos = (pos + 1 > M) ? 1 : pos + 1;
	}
	else
	{
		//반시계
		for (int cnt = 0; cnt < k; cnt++)
			pos = (pos - 1 == 0) ? M : pos - 1;
	}
	return pos;
}

vector<Pair> getNextToEachOther()
{
	vector<vector<int>>visited = vector<vector<int>>(N + 1, vector<int>(M + 1));
	vector<Pair>ret;

	//step1
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (circle[i][j] != INF) {
				Pair left = Pair(i, j - 1 == 0 ? M : j - 1);
				Pair right = Pair(i, j + 1 > M ? 1 : j + 1);

				if (circle[i][j] == circle[left.first][left.second]) {
					visited[i][j] = 1;
					visited[left.first][left.second] = 1;
				}
				if (circle[i][j] == circle[right.first][right.second]) {
					visited[i][j] = 1;
					visited[right.first][right.second] = 1;
				}
			}
		}
	}

	//step2
	for (int i = M; i >= 1; i--)
	{
		for (int j = N; j >= 1; j--)
		{
			if (circle[j][i] != INF)
			{
				Pair left = Pair(j - 1, i);
				Pair right = Pair(j + 1, i);

				if (left.first >= 1 && left.first <= N) {
					if (circle[j][i] == circle[left.first][left.second])
					{
						visited[j][i] = 1;
						visited[left.first][left.second] = 1;
					}
				}

				if (right.first >= 1 && right.first <= N) {
					if (circle[j][i] == circle[right.first][right.second])
					{
						visited[j][i] = 1;
						visited[right.first][right.second] = 1;
					}
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (visited[i][j])
				ret.push_back(Pair(i, j));
		}
	}
	return ret;
}

void setEval()
{
	int cnt = 0;
	int sum = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (circle[i][j] != INF)
			{
				sum += circle[i][j];
				cnt++;
			}
		}
	}
	double eval = sum / (double)cnt;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (circle[i][j] == INF)
				continue;

			if (circle[i][j] > eval) {
				circle[i][j]--;
			}
			else if (circle[i][j] < eval) {
				circle[i][j]++;
			}
		}
	}
}

void solve()
{
	for (int test = 1; test <= T; test++)
	{
		Spin sp = spin[test];

		for (int i = 1; i <= N; i++)
		{
			if (i % sp.x == 0)
			{
				//회전
				vector<vector<int>>temp = vector<vector<int>>(N + 1, vector<int>(M + 1));

				for (int j = 1; j <= M; j++) temp[i][getNextPos(j, sp.d, sp.k)] = circle[i][j];

				for (int j = 1; j <= M; j++) circle[i][j] = temp[i][j];
			}
		}
		//인접한것찾기
		vector<Pair>nextToElem = getNextToEachOther();

		if (nextToElem.size() == 0)
		{
			setEval();
		}
		else
		{
			for (Pair elem : nextToElem) circle[elem.first][elem.second] = INF;
		}
	}
}

int getSum()
{
	int ret = 0;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			ret += circle[i][j] != INF ? circle[i][j] : 0;

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	solve();
	cout << getSum() << endl;
	return 0;
}