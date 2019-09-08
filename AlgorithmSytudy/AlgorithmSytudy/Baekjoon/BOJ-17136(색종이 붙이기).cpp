#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

/*
BOJ(17136) ������ ���̱�
2019.08.21
*/

const int INF = 987654321;

int board[11][11]; //����
int temp[11][11]; //���纻
int sticker[6] = { 0,5,5,5,5,5 }; //����������
int answer = INF; //����

vector<Pair>v; //1 ���庤��


//Ư����ġ�� �����̸� ���� �� �ִ��� ���ι�ȯ
bool check(int idx1, int idx2, int type)
{
	bool ret = true;

	for (int i = idx1; i <= idx1 + type - 1; i++)
	{
		for (int j = idx2; j <= idx2 + type - 1; j++)
		{
			//ĭ�� ��踦 �Ѿ ��
			if (i < 1 || i>10 || j < 1 || j>10)
			{
				ret = false;
				return ret;
			}
			//��������Ȯ�� 
			else if (!sticker[type] || board[i][j] == -1 || board[i][j] == 0)
			{
				ret = false;
				return ret;
			}
		}
	}
	return ret;
}

//������ ���̴��Լ�
void cover(int idx1, int idx2, int type)
{
	for (int i = idx1; i <= idx1 + type - 1; i++)
		for (int j = idx2; j <= idx2 + type - 1; j++)
			board[i][j] = -1;

	sticker[type]--;
}

//������ �����Լ�
void uncover(int idx1, int idx2, int type)
{
	for (int i = idx1; i <= idx1 + type - 1; i++)
		for (int j = idx2; j <= idx2 + type - 1; j++)
			board[i][j] = temp[i][j];

	sticker[type]++;
}


//����Ž��(��Ʈ��ŷ)�Լ� , sticker_cnt = ������ ����Ƚ��, cover_cnt ������ĭ�� ����
void dfs(int sticker_cnt, int cover_cnt)
{
	//������ ĭ�ǰ����� 1�ǰ����� ������(���� �� ���̸�) �Լ����� 
	// ������ �亸�� ������ ����(�ּ� �����̰���)
	if (cover_cnt == v.size())
	{
		answer = min(answer, sticker_cnt);
		return;
	}

	// ���� �����̰� ���� �亸�� ũ�� ����(����ġ��)
	if (sticker_cnt >= answer)
		return;
	
	// ��� 1��ĭ�� Ž��
	for (int i = 0; i < v.size(); i++)
	{
		int idx1 = v[i].first;
		int idx2 = v[i].second;

		// �̹� �����̰� ���������� 
		if (board[idx1][idx2] == -1)
			continue;

		//�����̰� �ȵ��� ĭ�� ��� �����̸� �ٿ�����
		for (int j = 1; j <= 5; j++)
		{
			if (check(idx1, idx2, j))
			{
				cover(idx1, idx2, j);
				dfs(sticker_cnt + 1, cover_cnt + (j * j));
				uncover(idx1, idx2, j);
			}
		}
		break;
	}
}

int main()
{
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			scanf("%d", &board[i][j]);
			temp[i][j] = board[i][j];
			if (board[i][j]) v.push_back(Pair(i, j));
		}
	}

	dfs(0, 0);

	if (answer == INF) printf("-1\n");
	else printf("%d\n", answer);
	return 0;
}