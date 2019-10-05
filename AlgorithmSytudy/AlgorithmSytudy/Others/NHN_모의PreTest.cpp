#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

int N, W;
string board[101][101];
string temp[101][101];

Pair left_up;
Pair left_down;
Pair right_up;
Pair right_down;

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> W;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> board[i][j];
			temp[i][j] = board[i][j];
		}
	}
}

Pair get_Rotate_pos(Pair pos, bool way, int cnt, int number)
{
	if (way == true)
	{
		switch (number)
		{
		case 1:
		{
			int temp_cnt = 0;

			while (true)
			{
				while (temp_cnt < cnt && pos.second < right_up.second)
				{
					pos.second += 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.first < right_down.first)
				{
					pos.first += 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.second > left_down.second)
				{
					pos.second -= 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.first>left_up.first)
				{
					pos.first -= 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;
			}
		}
		break;

		case 2:
		{
			int temp_cnt = 0;

			while (true)
			{
				while (temp_cnt < cnt && pos.first < right_down.first)
				{
					pos.first += 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.second > left_down.second)
				{
					pos.second -= 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.first>left_up.first)
				{
					pos.first -= 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.second < right_up.second)
				{
					pos.second += 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;
			}
		}
		break;
		case 3:
		{
			int temp_cnt = 0;

			while (true)
			{
				while (temp_cnt < cnt && pos.second > left_down.second)
				{
					pos.second -= 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.first > left_up.first)
				{
					pos.first -= 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.second < right_up.second)
				{
					pos.second += 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.first < right_down.first)
				{
					pos.first += 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;
			}
		}
		break;
		case 4:
		{
			int temp_cnt = 0;

			while (true)
			{
				while (temp_cnt < cnt && pos.first > left_up.first)
				{
					pos.first -= 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.second < right_up.second)
				{
					pos.second += 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.first < right_down.first)
				{
					pos.first += 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.second > left_down.second)
				{
					pos.second -= 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;
			}
		}
		break;
		}
	}
	else
	{
		//반시계방향
		switch (number)
		{
		case 1:
		{
			int temp_cnt = 0;

			while (true)
			{
				while (temp_cnt < cnt && pos.first < left_down.first)
				{
					pos.first += 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.second < right_down.second)
				{
					pos.second += 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.first>right_up.first)
				{
					pos.first -= 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.second > left_up.second)
				{
					pos.second -= 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;
			}
		}
		break;
		case 2:
		{
			int temp_cnt = 0;

			while (true)
			{
				while (temp_cnt < cnt && pos.second < right_down.second)
				{
					pos.second += 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.first>right_up.first)
				{
					pos.first -= 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.second > left_up.second)
				{
					pos.second -= 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.first < left_down.first)
				{
					pos.first += 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;
			}
		}
		break;
		case 3:
		{
			int temp_cnt = 0;

			while (true)
			{
				while (temp_cnt < cnt && pos.first>right_up.first)
				{
					pos.first -= 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.second > left_up.second)
				{
					pos.second -= 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.first < left_down.first)
				{
					pos.first += 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.second < right_down.second)
				{
					pos.second += 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;
			}
		}
		break;
		case 4:
		{
			int temp_cnt = 0;

			while (true)
			{
				while (temp_cnt < cnt && pos.second > left_up.second)
				{
					pos.second -= 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.first < left_down.first)
				{
					pos.first += 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.second < right_down.second)
				{
					pos.second += 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;

				while (temp_cnt < cnt && pos.first>right_up.first)
				{
					pos.first -= 1;
					temp_cnt++;
				}
				if (temp_cnt == cnt)
					return pos;
			}
		}
		break;
		}
	}
	return pos;
}

void rotate()
{
	int turn = N;
	left_up = Pair(1, 1);
	left_down = Pair(N, 1);
	right_up = Pair(1, N);
	right_down = Pair(N, N);

	while (turn > 1)
	{
		if (W > 0)
		{
			//시계방향
			for (int t = 1; t <= 4; t++)
			{
				if (t == 1)
				{
					Pair start = left_up;

					for (int i = start.second; i < right_up.second; i++)
					{
						Pair rotated_pos = get_Rotate_pos(start, true, W % ((turn - 1) * 4), t);
						board[rotated_pos.first][rotated_pos.second] = temp[start.first][start.second];
						start = Pair(start.first, start.second + 1);
					}
				}
				else if (t == 2)
				{
					Pair start = right_up;

					for (int i = start.first; i < right_down.first; i++)
					{
						Pair rotated_pos = get_Rotate_pos(start, true, W % ((turn - 1) * 4), t);
						board[rotated_pos.first][rotated_pos.second] = temp[start.first][start.second];
						start = Pair(start.first + 1, start.second);
					}
				}
				else if (t == 3)
				{
					Pair start = right_down;

					for (int i = start.second; i > left_down.second; i--)
					{
						Pair rotated_pos = get_Rotate_pos(start, true, W % ((turn - 1) * 4), t);
						board[rotated_pos.first][rotated_pos.second] = temp[start.first][start.second];
						start = Pair(start.first, start.second - 1);
					}
				}
				else
				{
					Pair start = left_down;

					for (int i = start.first; i > left_up.first; i--)
					{
						Pair rotated_pos = get_Rotate_pos(start, true, W % ((turn - 1) * 4), t);
						board[rotated_pos.first][rotated_pos.second] = temp[start.first][start.second];
						start = Pair(start.first - 1, start.second);
					}
				}
			}
		}
		else
		{
			//반시계방향
			for (int t = 1; t <= 4; t++)
			{
				if (t == 1)
				{
					Pair start = left_up;

					for (int i = start.first; i < left_down.first; i++)
					{
						Pair rotated_pos = get_Rotate_pos(start, false, abs(W) % ((turn - 1) * 4), t);
						board[rotated_pos.first][rotated_pos.second] = temp[start.first][start.second];
						start = Pair(start.first + 1, start.second);
					}
				}
				else if (t == 2)
				{
					Pair start = left_down;

					for (int i = start.second; i < right_down.second; i++)
					{
						Pair rotated_pos = get_Rotate_pos(start, false, abs(W) % ((turn - 1) * 4), t);
						board[rotated_pos.first][rotated_pos.second] = temp[start.first][start.second];
						start = Pair(start.first, start.second + 1);
					}
				}
				else if (t == 3)
				{
					Pair start = right_down;

					for (int i = start.first; i > right_up.first; i--)
					{
						Pair rotated_pos = get_Rotate_pos(start, false, abs(W) % ((turn - 1) * 4), t);
						board[rotated_pos.first][rotated_pos.second] = temp[start.first][start.second];
						start = Pair(start.first - 1, start.second);
					}
				}
				else
				{
					Pair start = right_up;

					for (int i = start.second; i > left_up.second; i--)
					{
						Pair rotated_pos = get_Rotate_pos(start, false, abs(W) % ((turn - 1) * 4), t);
						board[rotated_pos.first][rotated_pos.second] = temp[start.first][start.second];
						start = Pair(start.first, start.second - 1);
					}
				}
			}
		}
		turn -= 2;
		W *= -1;
		left_up = Pair(left_up.first + 1, left_up.second + 1);
		left_down = Pair(left_down.first - 1, left_down.second + 1);
		right_up = Pair(right_up.first + 1, right_up.second - 1);
		right_down = Pair(right_down.first - 1, right_down.second - 1);
	}
}

int main()
{
	init();
	rotate();
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (j == N)
				cout << board[i][j]+"\n";
			else
				cout << board[i][j] + " ";
		}
	}

	return 0;
}