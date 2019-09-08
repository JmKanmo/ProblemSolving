#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

const int idx1[] = { 1,1,-1,-1 }; //������ǥ
const int idx2[] = { 1,-1,-1,1 };

int board[21][21];
int counter[101]; //����Ʈ����
int N;
int answer;

//�������Է��Լ�
void init()
{
	answer = -1;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}
}

//�����ʰ�üũ
bool outofRange(Pair pos) { return pos.first<1 || pos.first>N || pos.second<1 || pos.second>N ? true : false; }

//dfs��Ʈ��ŷ�Լ�
void dfs(Pair start, Pair pos, int depth, int cnt)
{
	//����״��
	Pair next = Pair(pos.first + idx1[depth], pos.second + idx2[depth]);

	if (outofRange(next) != true)
	{
		if (!counter[board[next.first][next.second]])
		{
			counter[board[next.first][next.second]]++;
			dfs(start, next, depth, cnt + 1);
			counter[board[next.first][next.second]]--;
		}
		if (start == next)
		{
			answer = max(answer, cnt);
		}
	}

	//������ȯ	
	depth += 1;
	if (depth > 3) return;
	next = Pair(pos.first + idx1[depth], pos.second + idx2[depth]);

	if (outofRange(next) != true)
	{
		if (!counter[board[next.first][next.second]])
		{
			counter[board[next.first][next.second]]++;
			dfs(start, next, depth, cnt + 1);
			counter[board[next.first][next.second]]--;
		}
		if (start == next)
		{
			answer = max(answer, cnt);
		}
	}
}

int main()
{
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		init();
		
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				counter[board[i][j]]++;
				dfs(Pair(i, j), Pair(i, j), 0, 1);
				counter[board[i][j]]--;
			}
		}
		printf("#%d %d\n", t, answer);
	}
	return 0;
}