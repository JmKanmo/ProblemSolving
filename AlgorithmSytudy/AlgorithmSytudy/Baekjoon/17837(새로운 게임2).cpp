#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

enum Way {
	RIGHT = 1, LEFT, UP, DOWN
};

enum Color {
	WHITE = 0, RED, BLUE
};

struct Horse
{
	int idx1;
	int idx2;
	int way;
	int number;
};

struct Board
{
	queue<Horse>horses;
	int color;
};

int N, K;
Board board[13][13];
Horse horse[11];

void init()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int color;
			cin >> color;
			board[i][j].color = color;
		}
	}

	for (int i = 1; i <= K; i++)
	{
		int idx1, idx2, way;
		cin >> idx1 >> idx2 >> way;
		horse[i].idx1 = idx1;
		horse[i].idx2 = idx2;
		horse[i].way = way;
		horse[i].number = i;
		board[idx1][idx2].horses.push(horse[i]);
	}
}

int reverseWay(int way) {
	switch (way)
	{
	case UP: return DOWN;
	case DOWN: return UP;
	case LEFT: return RIGHT;
	case RIGHT: return LEFT;
	}
}

pair<int,int> movePos(int idx1, int idx2, int way)
{
	switch (way)
	{
	case UP:
		idx1--;
		break;
	case DOWN:
		idx1++;
		break;
	case LEFT:
		idx2--;
		break;
	case RIGHT:
		idx2++;
		break;
	}
	return make_pair(idx1, idx2);
}

void moveFunc(int number, int prevIdx1, int prevIdx2, int movedIdx1, int movedIdx2, int color)
{
	queue<Horse>tempQ;
	queue<Horse>movedQ;
	bool flag = false;

	while (board[prevIdx1][prevIdx2].horses.empty() != true)
	{
		Horse temp_horse = board[prevIdx1][prevIdx2].horses.front();
		board[prevIdx1][prevIdx2].horses.pop();
		if (temp_horse.number == number) flag = true;
		if (!flag) {
			tempQ.push(temp_horse);
		}
		else {
			temp_horse.idx1 = movedIdx1;
			temp_horse.idx2 = movedIdx2;
			horse[temp_horse.number].idx1 = movedIdx1;
			horse[temp_horse.number].idx2 = movedIdx2;
			movedQ.push(temp_horse);
		}
	}

	while (tempQ.empty() != true) {
		board[prevIdx1][prevIdx2].horses.push(tempQ.front());
		tempQ.pop();
	}

	if (color == WHITE) {
		while (movedQ.empty() != true) {
			board[movedIdx1][movedIdx2].horses.push(movedQ.front());
			movedQ.pop();
		}
	}
	else if (color == RED) {
		stack<Horse>st;
		while (movedQ.empty() != true) {
			st.push(movedQ.front());
			movedQ.pop();
		}
		while (st.empty() != true) {
			movedQ.push(st.top());
			st.pop();
		}
		while (movedQ.empty() != true) {
			board[movedIdx1][movedIdx2].horses.push(movedQ.front());
			movedQ.pop();
		}
	}
}

void changeHorseWay(int number, int idx1, int idx2) {
	horse[number].way = reverseWay(horse[number].way);
	queue<Horse>tempQ;

	while (board[idx1][idx2].horses.empty() != true) {
		Horse horse = board[idx1][idx2].horses.front();
		board[idx1][idx2].horses.pop();
		if (horse.number == number) horse.way = reverseWay(horse.way);
		tempQ.push(horse);
	}
	while (tempQ.empty() != true) {
		board[idx1][idx2].horses.push(tempQ.front());
		tempQ.pop();
	}
}

bool moveHorse(int number, int prevIdx1, int prevIdx2, int movedIdx1, int movedIdx2)
{
	moveFunc(number, prevIdx1, prevIdx2, movedIdx1, movedIdx2, board[movedIdx1][movedIdx2].color);
	return board[movedIdx1][movedIdx2].horses.size() >= 4 ? true : false;
}

void solve()
{
	int turn = 0;

	while (++turn) {
		if (turn > 1000) {
			cout << -1 << "\n";
			return;
		}
		else {
			for (int i = 1; i <= K; i++) {
				pair<int, int> movedPos = movePos(horse[i].idx1, horse[i].idx2, horse[i].way);

				if (movedPos.first<1 || movedPos.first>N || movedPos.second<1 || movedPos.second>N) {
					changeHorseWay(i, horse[i].idx1, horse[i].idx2);
					movedPos = movePos(horse[i].idx1, horse[i].idx2, horse[i].way);
					if (movedPos.first<1 || movedPos.first>N || movedPos.second<1 || movedPos.second>N || board[movedPos.first][movedPos.second].color == BLUE) continue;
				}

				else if (board[movedPos.first][movedPos.second].color == BLUE) {
					changeHorseWay(i, horse[i].idx1, horse[i].idx2);
					movedPos = movePos(horse[i].idx1, horse[i].idx2, horse[i].way);
					if (movedPos.first<1 || movedPos.first>N || movedPos.second<1 || movedPos.second>N || board[movedPos.first][movedPos.second].color == BLUE) continue;
				}

				if (moveHorse(i, horse[i].idx1, horse[i].idx2, movedPos.first, movedPos.second)) {
					cout << turn << "\n";
					return;
				}
			}
		}
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