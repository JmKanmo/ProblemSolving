#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rotate {

	int idx;
	int way;

	Rotate() {}

	Rotate(int idx, int way)
	{
		this->idx = idx;
		this->way = way;
	}
};

int K;

vector<int> magnetic_1(8);
vector<int> magnetic_2(8);
vector<int> magnetic_3(8);
vector<int> magnetic_4(8);
vector<int>isRotated;
vector<Rotate>rot_v;

void init()
{
	cin >> K;
	rot_v.clear();

	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
		{
			for (int j = 0; j < 8; j++) cin >> magnetic_1[j];
			break;
		}
		case 1:
		{
			for (int j = 0; j < 8; j++) cin >> magnetic_2[j];
			break;
		}
		case 2:
		{
			for (int j = 0; j < 8; j++) cin >> magnetic_3[j];
			break;
		}
		case 3:
		{
			for (int j = 0; j < 8; j++) cin >> magnetic_4[j];
			break;
		}
		}
	}

	for (int i = 0; i < K; i++)
	{
		int n, way;
		cin >> n >> way;
		rot_v.push_back(Rotate(n, way));
	}
}

void rotate_func(int idx, int way)
{
	//idx번자석 회전
	switch (idx)
	{
	case 1:
	{
		if (way == 1)
		{
			//시계
			vector<int>temp = magnetic_1;
			for (int i = 0; i < 7; i++) magnetic_1[i + 1] = temp[i];
			magnetic_1[0] = temp[7];
		}
		else
		{
			//반시계
			vector<int>temp = magnetic_1;
			for (int i = 7; i > 0; i--) magnetic_1[i - 1] = temp[i];
			magnetic_1[7] = temp[0];
		}
	}
	break;
	case 2:
	{
		if (way == 1)
		{
			//시계
			vector<int>temp = magnetic_2;
			for (int i = 0; i < 7; i++) magnetic_2[i + 1] = temp[i];
			magnetic_2[0] = temp[7];
		}
		else
		{
			//반시계
			vector<int>temp = magnetic_2;
			for (int i = 7; i > 0; i--) magnetic_2[i - 1] = temp[i];
			magnetic_2[7] = temp[0];
		}
	}
	break;
	case 3:
	{
		if (way == 1)
		{
			//시계
			vector<int>temp = magnetic_3;
			for (int i = 0; i < 7; i++) magnetic_3[i + 1] = temp[i];
			magnetic_3[0] = temp[7];
		}
		else
		{
			//반시계
			vector<int>temp = magnetic_3;
			for (int i = 7; i > 0; i--) magnetic_3[i - 1] = temp[i];
			magnetic_3[7] = temp[0];
		}
	}
	break;
	case 4:
	{
		if (way == 1)
		{
			//시계
			vector<int>temp = magnetic_4;
			for (int i = 0; i < 7; i++) magnetic_4[i + 1] = temp[i];
			magnetic_4[0] = temp[7];
		}
		else
		{
			//반시계
			vector<int>temp = magnetic_4;
			for (int i = 7; i > 0; i--) magnetic_4[i - 1] = temp[i];
			magnetic_4[7] = temp[0];
		}
	}
	}
}

void check_matching(int idx)
{
	if (idx == 1)
	{
		if (magnetic_1[2] != magnetic_2[6] && isRotated[1]) isRotated[2] = 1;
		if (magnetic_2[2] != magnetic_3[6] && isRotated[2]) isRotated[3] = 1;
		if (magnetic_3[2] != magnetic_4[6] && isRotated[3]) isRotated[4] = 1;
	}
	else if (idx == 2)
	{
		if (magnetic_1[2] != magnetic_2[6] && isRotated[2]) isRotated[1] = 1;
		if (magnetic_2[2] != magnetic_3[6] && isRotated[2]) isRotated[3] = 1;
		if (magnetic_3[2] != magnetic_4[6] && isRotated[3]) isRotated[4] = 1;
	}
	else if (idx == 3)
	{
		if (magnetic_2[2] != magnetic_3[6] && isRotated[3]) isRotated[2] = 1;
		if (magnetic_1[2] != magnetic_2[6] && isRotated[2]) isRotated[1] = 1;
		if (magnetic_3[2] != magnetic_4[6] && isRotated[3]) isRotated[4] = 1;
	}
	else
	{
		if (magnetic_3[2] != magnetic_4[6] && isRotated[4]) isRotated[3] = 1;
		if (magnetic_2[2] != magnetic_3[6] && isRotated[3]) isRotated[2] = 1;
		if (magnetic_1[2] != magnetic_2[6] && isRotated[2]) isRotated[1] = 1;
	}
}

void rotate_magnetic(int idx, int way)
{
	isRotated[idx] = 1;

	//각각붙어잇는지 확인
	check_matching(idx);

	//idx번자석 회전
	rotate_func(idx, way);

	//idx번자석의 좌측자석회전
	for (int i = idx - 1, main_way = way; i >= 1; i--) {
		if (isRotated[i])
		{
			int temp_way = main_way == 1 ? -1 : 1;
			rotate_func(i, temp_way);
			main_way = temp_way;
		}
	}
	//idx번자석의 우측자석회전
	for (int i = idx + 1, main_way = way; i <= 4; i++) {
		if (isRotated[i])
		{
			int temp_way = main_way == 1 ? -1 : 1;
			rotate_func(i, temp_way);
			main_way = temp_way;
		}
	}
}

int get_sum()
{
	int ret = 0;

	for (int i = 0; i < rot_v.size(); i++)
	{
		isRotated = vector<int>(5);
		rotate_magnetic(rot_v[i].idx, rot_v[i].way);
	}

	for (int i = 1; i <= 4; i++)
	{
		if (i == 1)
		{
			if (magnetic_1[0] == 0) ret += 0;
			else ret += 1;
		}
		else if (i == 2)
		{
			if (magnetic_2[0] == 0) ret += 0;
			else ret += 2;
		}
		else if (i == 3)
		{
			if (magnetic_3[0] == 0) ret += 0;
			else ret += 4;
		}
		else
		{
			if (magnetic_4[0] == 0) ret += 0;
			else ret += 8;
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		init();
		cout << "#" << t << " " << get_sum() << "\n";
	}

	return 0;
}