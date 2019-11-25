#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx1[] = { 0,0,1,-1 };
const int idx2[] = { 1,-1,0,0 };

int R, C;
char board[51][51];
int visited[51][51];
int step[51][51];
vector<Pair>water_pos;
queue<Pair>animal_q;
queue<Pair>water_q;

void init()
{
	cin >> R >> C;

	for (int i = 1; i <= R; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= C; j++)
		{
			board[i][j] = str[j - 1];

			if (board[i][j] == 'S')
			{
				animal_q.push(Pair(i, j));
				visited[i][j] = 1;
			}

			if (board[i][j] == '*')
			{
				visited[i][j] = 1;
				water_q.push(Pair(i, j));
			}
		}
	}
}

void bfs()
{
	int time = 0;
	bool isArrive = false;

	while (true)
	{
		time++;

		if (water_q.empty() && animal_q.empty()) 
			break;

		int water_size = water_q.size();

		while (water_size>0)
		{
			Pair water_pos = water_q.front();
			water_q.pop();

			for (int i = 0; i < 4; i++)
			{
				Pair next_pos = Pair(water_pos.first + idx1[i], water_pos.second + idx2[i]);

				if (next_pos.first<1 || next_pos.first>R || next_pos.second<1 || next_pos.second>C)
					continue;

				if (!visited[next_pos.first][next_pos.second] && board[next_pos.first][next_pos.second] == '.')
				{
					visited[next_pos.first][next_pos.second] = 1;
					water_q.push(next_pos);
				}
			}
			water_size--;
		}

		int animal_size = animal_q.size();

		while (animal_size>0)
		{
			Pair animal_pos = animal_q.front();
			animal_q.pop();

			if (board[animal_pos.first][animal_pos.second] == 'D')
			{
				isArrive = true;
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				Pair next_pos = Pair(animal_pos.first + idx1[i], animal_pos.second + idx2[i]);

				if (next_pos.first<1 || next_pos.first>R || next_pos.second<1 || next_pos.second>C)
					continue;

				if (!visited[next_pos.first][next_pos.second] && (board[next_pos.first][next_pos.second] == '.' || board[next_pos.first][next_pos.second] == 'D'))
				{
					visited[next_pos.first][next_pos.second] = 1;
					animal_q.push(next_pos);
				}
			}
			animal_size--;
		}
		if (isArrive)
			break;
	}

	if (isArrive) {
		cout << time-1 << endl;
	}
	else {
		cout << "KAKTUS" << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	init();
	bfs();

	return 0;
}

