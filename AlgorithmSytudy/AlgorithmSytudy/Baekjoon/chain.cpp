#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> Pair;

int chains[5][10];

Pair left_right[5];

int state[5];

int k;
int score;

void setLeftRight() 
{
	for (int i = 1; i <= 4; i++) {
		left_right[i].first = chains[i][7];
		left_right[i].second = chains[i][3];
	}
}

void rotate(int number, int direction)
{
	int temp[9];

	for (int i = 1; i <= 8; i++) temp[i] = chains[number][i];

	if (direction == 1) {
		for (int i = 1; i <= 8; i++) {
			if (i == 8) {
				chains[number][1] = temp[i];
			}
			else {
				chains[number][i + 1] = temp[i];
			}
		}
	}
	else if (direction == -1) {
		for (int i = 8; i >= 1; i--) {
			if (i == 8) {
				chains[number][8] = temp[1];
			}
			else {
				chains[number][i] = temp[i + 1];
			}
		}
	}
}

void goLeft(int left, int right)
{
	if (state[right] != 0)
	{
		if (left_right[left].second == left_right[right].first) {
			state[left] = 0;
		}
		else {
			state[left] = state[right] == 1 ? -1 : 1;
		}
	}
	else {
		state[left] = 0;
	}
	rotate(left, state[left]);
}

void goRight(int left, int right)
{
	if (state[left] != 0)
	{
		if (left_right[left].second == left_right[right].first) {
			state[right] = 0;
		}
		else {
			state[right] = state[left] == 1 ? -1 : 1;
		}
	}
	else {
		state[right] = 0;
	}
	rotate(right, state[right]);
}

void rotate_chain(int number, int direction)
{
	setLeftRight();
	state[number] = direction;
	rotate(number, direction);

	for (int i = number; i > 1; i--) {
		goLeft(i - 1, i);
	}

	for (int i = number; i < 4; i++) {
		goRight(i, i + 1);
	}
}

void getScore()
{
	for (int i = 1; i <= 4; i++) {
		if (i == 1) {
			score += chains[i][1] == 0 ? 0 : 1;
		}
		else if (i == 2) {
			score += chains[i][1] == 0 ? 0 : 2;
		}
		else if (i == 3) {
			score += chains[i][1] == 0 ? 0 : 4;
		}
		else {
			score += chains[i][1] == 0 ? 0 : 8;
		}
	}
}

int main()
{
	for (int i = 1; i <= 4; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= 8; j++) {
			chains[i][j] = stoi(to_string(str[j - 1])) - 48;
		}
	}

	scanf("%d", &k);

	for (int i = 1; i <= k; i++) {
		int num, dir;
		scanf("%d %d", &num, &dir);
		rotate_chain(num, dir);
	}
	getScore();
	cout << score << endl;
	return 0;
}