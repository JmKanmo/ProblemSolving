#include <iostream>
#include <vector>

using namespace std;

typedef pair<char, char> Pair;

vector<vector<char>>cube;
vector<Pair>cube_rot;

void init_cube()
{
	cube = vector<vector<char>>(20, vector<char>(20));
	cube_rot.clear();

	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 9; j++) {
			switch (i)
			{
			case 1: cube[i][j] = 'w'; break;
			case 2: cube[i][j] = 'y'; break;
			case 3: cube[i][j] = 'r'; break;
			case 4: cube[i][j] = 'o'; break;
			case 5: cube[i][j] = 'g'; break;
			case 6: cube[i][j] = 'b'; break;
			}
		}
	}
}

void sub_rotate(char object, char direct)
{
	int time_arr[9] = { 2,4,6,-2,0,2,-6,-4,-2 };
	int untime_arr[9] = { 6,2,-2,4,0,-4,2,-2,-6 };
	vector<vector<char>>temp = cube;

	switch (object)
	{
	case 'U':
	{
		//윗면
		if (direct == '+') {
			for (int i = 1, j = 0; i <= 9; i++, j++) {
				cube[1][i + time_arr[j]] = temp[1][i];
			}
		}
		else {
			for (int i = 1, j = 0; i <= 9; i++, j++) {
				cube[1][i + untime_arr[j]] = temp[1][i];
			}
		}
		break;
	}
	case 'D':
	{
		//아랫면
		if (direct == '+') {
			for (int i = 1, j = 0; i <= 9; i++, j++) {
				cube[2][i + time_arr[j]] = temp[2][i];
			}
		}
		else {
			for (int i = 1, j = 0; i <= 9; i++, j++) {
				cube[2][i + untime_arr[j]] = temp[2][i];
			}
		}
		break;
	}
	case 'F':
	{
		//앞면
		if (direct == '+') {
			for (int i = 1, j = 0; i <= 9; i++, j++) {
				cube[3][i + time_arr[j]] = temp[3][i];
			}
		}
		else {
			for (int i = 1, j = 0; i <= 9; i++, j++) {
				cube[3][i + untime_arr[j]] = temp[3][i];
			}
		}
		break;
	}
	case 'B':
	{
		if (direct == '+') {
			for (int i = 1, j = 0; i <= 9; i++, j++) {
				cube[4][i + time_arr[j]] = temp[4][i];
			}
		}
		else {
			for (int i = 1, j = 0; i <= 9; i++, j++) {
				cube[4][i + untime_arr[j]] = temp[4][i];
			}
		}
		break;
	}
	case 'L':
	{
		if (direct == '+') {
			for (int i = 1, j = 0; i <= 9; i++, j++) {
				cube[5][i + time_arr[j]] = temp[5][i];
			}
		}
		else {
			for (int i = 1, j = 0; i <= 9; i++, j++) {
				cube[5][i + untime_arr[j]] = temp[5][i];
			}
		}
		break;
	}
	case 'R':
	{
		if (direct == '+') {
			for (int i = 1, j = 0; i <= 9; i++, j++) {
				cube[6][i + time_arr[j]] = temp[6][i];
			}
		}
		else {
			for (int i = 1, j = 0; i <= 9; i++, j++) {
				cube[6][i + untime_arr[j]] = temp[6][i];
			}
		}
		break;
	}
	}
}

void cube_rotate()
{
	for (int i = 0; i < cube_rot.size(); i++)
	{
		Pair pair = cube_rot[i];

		switch (pair.first)
		{
		case 'U':
		{
			//윗면
			if (pair.second == '+') {
				//시계방향
				vector<vector<char>>temp_cube = cube;
				for (int i = 1; i <= 4; i++)
				{
					if (i == 1) {
						for (int j = 1; j <= 3; j++) cube[6][j] = temp_cube[4][j];
					}
					else if (i == 2) {
						for (int j = 1, k = 3; j <= 3; j++, k--) cube[3][j] = temp_cube[6][k];
					}
					else if (i == 3) {
						for (int j = 1; j <= 3; j++) cube[5][j] = temp_cube[3][j];
					}
					else {
						for (int j = 1, k = 3; j <= 3; j++, k--) cube[4][j] = temp_cube[5][k];
					}
				}
			}
			else {
				//반시계방향
				vector<vector<char>>temp_cube = cube;
				for (int i = 1; i <= 4; i++)
				{
					if (i == 1) {
						for (int j = 1, k = 3; j <= 3; j++, k--) cube[6][j] = temp_cube[3][k];
					}
					else if (i == 2) {
						for (int j = 1; j <= 3; j++) cube[4][j] = temp_cube[6][j];
					}
					else if (i == 3) {
						for (int j = 1, k = 3; j <= 3; j++, k--) cube[5][j] = temp_cube[4][k];
					}
					else {
						for (int j = 1; j <= 3; j++) cube[3][j] = temp_cube[5][j];
					}
				}
			}
			sub_rotate(pair.first, pair.second);
			break;
		}
		case 'D':
		{
			//아랫면
			if (pair.second == '+') {
				vector<vector<char>>temp_cube = cube;
				for (int i = 1; i <= 4; i++)
				{
					if (i == 1) {
						for (int j = 7; j <= 9; j++) cube[3][j] = temp_cube[5][j];
					}
					else if (i == 2) {
						for (int j = 7, k = 9; j <= 9; j++, k--) cube[6][j] = temp_cube[3][k];
					}
					else if (i == 3) {
						for (int j = 7; j <= 9; j++) cube[4][j] = temp_cube[6][j];
					}
					else {
						for (int j = 7, k = 9; j <= 9; j++, k--) cube[5][j] = temp_cube[4][k];
					}
				}
			}
			else {
				vector<vector<char>>temp_cube = cube;
				for (int i = 1; i <= 4; i++)
				{
					if (i == 1) {
						for (int j = 7, k = 9; j <= 9; j++, k--) cube[3][j] = temp_cube[6][k];
					}
					else if (i == 2) {
						for (int j = 7; j <= 9; j++) cube[5][j] = temp_cube[3][j];
					}
					else if (i == 3) {
						for (int j = 7, k = 9; j <= 9; j++, k--) cube[4][j] = temp_cube[5][k];
					}
					else {
						for (int j = 7; j <= 9; j++) cube[6][j] = temp_cube[4][j];
					}
				}
			}
			sub_rotate(pair.first, pair.second);
			break;
		}
		case 'F':
		{
			//앞면
			if (pair.second == '+') {
				vector<vector<char>>temp_cube = cube;
				for (int i = 1; i <= 4; i++)
				{
					if (i == 1) {
						for (int j = 7, k = 9; j <= 9; j++, k -= 3) cube[1][j] = temp_cube[5][k];
					}
					else if (i == 2) {
						for (int j = 7, k = 3; j <= 9; j++, k += 3) cube[6][k] = temp_cube[1][j];
					}
					else if (i == 3) {
						for (int j = 7, k = 9; j <= 9; j++, k -= 3) cube[2][j] = temp_cube[6][k];
					}
					else {
						for (int j = 7, k = 3; j <= 9; j++, k += 3) cube[5][k] = temp_cube[2][j];
					}
				}
			}
			else {
				vector<vector<char>>temp_cube = cube;
				for (int i = 1; i <= 4; i++)
				{
					if (i == 1) {
						for (int j = 7, k = 3; j <= 9; j++, k += 3) cube[1][j] = temp_cube[6][k];
					}
					else if (i == 2) {
						for (int j = 7, k = 9; j <= 9; j++, k -= 3) cube[5][k] = temp_cube[1][j];
					}
					else if (i == 3) {
						for (int j = 7, k = 3; j <= 9; j++, k += 3) cube[2][j] = temp_cube[5][k];
					}
					else {
						for (int j = 7, k = 9; j <= 9; j++, k -= 3) cube[6][k] = temp_cube[2][j];
					}
				}
			}
			sub_rotate(pair.first, pair.second);
			break;
		}
		case'B':
		{
			//뒷면
			if (pair.second == '+') {
				vector<vector<char>>temp_cube = cube;
				for (int i = 1; i <= 4; i++)
				{
					if (i == 1) {
						for (int j = 1, k = 7; j <= 3; j++, k -= 3) cube[5][k] = temp_cube[1][j];
					}
					else if (i == 2) {
						for (int j = 1, k = 1; j <= 3; j++, k += 3) cube[2][j] = temp_cube[5][k];
					}
					else if (i == 3) {
						for (int j = 1, k = 7; j <= 3; j++, k -= 3) cube[6][k] = temp_cube[2][j];
					}
					else {
						for (int j = 1, k = 1; j <= 3; j++, k += 3) cube[1][j] = temp_cube[6][k];
					}
				}
			}
			else {
				vector<vector<char>>temp_cube = cube;
				for (int i = 1; i <= 4; i++)
				{
					if (i == 1) {
						for (int j = 1, k = 1; j <= 3; j++, k += 3) cube[6][k] = temp_cube[1][j];
					}
					else if (i == 2) {
						for (int j = 1, k = 7; j <= 3; j++, k -= 3) cube[2][j] = temp_cube[6][k];
					}
					else if (i == 3) {
						for (int j = 1, k = 1; j <= 3; j++, k += 3) cube[5][k] = temp_cube[2][j];
					}
					else {
						for (int j = 1, k = 7; j <= 3; j++, k -= 3) cube[1][j] = temp_cube[5][k];
					}
				}
			}
			sub_rotate(pair.first, pair.second);
			break;
		}
		case 'L':
		{
			//왼쪽면
			if (pair.second == '+') {
				vector<vector<char>>temp_cube = cube;
				for (int i = 1; i <= 4; i++)
				{
					if (i == 1) {
						for (int j = 1, k = 1; j <= 7; j += 3, k += 3) cube[3][k] = temp_cube[1][j];
					}
					else if (i == 2) {
						for (int j = 7, k = 1; j >= 1; j -= 3, k += 3) cube[2][k] = temp_cube[3][j];
					}
					else if (i == 3) {
						for (int j = 1, k = 1; j <= 7; j += 3, k += 3) cube[4][k] = temp_cube[2][j];
					}
					else {
						for (int j = 7, k = 1; j >= 1; j -= 3, k += 3) cube[1][k] = temp_cube[4][j];
					}
				}
			}
			else {
				vector<vector<char>>temp_cube = cube;
				for (int i = 1; i <= 4; i++)
				{
					if (i == 1) {
						for (int j = 7, k = 1; j >= 1; j -= 3, k += 3) cube[4][j] = temp_cube[1][k];
					}
					else if (i == 2) {
						for (int j = 1, k = 1; j <= 7; j += 3, k += 3) cube[2][j] = temp_cube[4][k];
					}
					else if (i == 3) {
						for (int j = 7, k = 1; j >= 1; j -= 3, k += 3) cube[3][k] = temp_cube[2][j];
					}
					else {
						for (int j = 1, k = 1; j <= 7; j += 3, k += 3) cube[1][j] = temp_cube[3][k];
					}

				}
			}
			sub_rotate(pair.first, pair.second);
			break;
		}
		case 'R':
		{
			//오른쪽면
			if (pair.second == '+') {
				vector<vector<char>>temp_cube = cube;
				for (int i = 1; i <= 4; i++)
				{
					if (i == 1) {
						for (int j = 3, k = 3; j <= 9; j += 3, k += 3) cube[1][j] = temp_cube[3][k];
					}
					else if (i == 2) {
						for (int j = 9, k = 3; j >= 3; j -= 3, k += 3) cube[4][k] = temp_cube[1][j];
					}
					else if (i == 3) {
						for (int j = 3, k = 3; j <= 9; j += 3, k += 3) cube[2][j] = temp_cube[4][k];
					}
					else {
						for (int j = 9, k = 3; j >= 3; j -= 3, k += 3) cube[3][k] = temp_cube[2][j];
					}
				}
			}
			else {
				vector<vector<char>>temp_cube = cube;
				for (int i = 1; i <= 4; i++)
				{
					if (i == 1) {
						for (int j = 3, k = 3; j <= 9; j += 3, k += 3) cube[3][j] = temp_cube[1][k];
					}
					else if (i == 2) {
						for (int j = 9, k = 3; j >= 3; j -= 3, k += 3) cube[2][k] = temp_cube[3][j];
					}
					else if (i == 3) {
						for (int j = 3, k = 3; j <= 9; j += 3, k += 3) cube[4][j] = temp_cube[2][k];
					}
					else {
						for (int j = 9, k = 3; j >= 3; j -= 3, k += 3) cube[1][k] = temp_cube[4][j];
					}
				}
			}
			sub_rotate(pair.first, pair.second);
			break;
		}
		}
	}
}

void setUpperColorOfCube()
{
	for (int i = 1; i <= 3; i++) printf("%c", cube[1][i]);
	printf("\n");
	for (int i = 4; i <= 6; i++) printf("%c", cube[1][i]);
	printf("\n");
	for (int i = 7; i <= 9; i++) printf("%c", cube[1][i]);
	printf("\n");
}
int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		init_cube();
		int rot_cnt;
		scanf("%d", &rot_cnt);
		for (int i = 0; i < rot_cnt; i++) {
			char w, d;
			cin >> w >> d;
			cube_rot.push_back(Pair(w, d));
		}
		//큐브로테이트함수호출
		cube_rotate();
		//큐브윗면색구하는함수호출
		setUpperColorOfCube();
	}
	return 0;
}