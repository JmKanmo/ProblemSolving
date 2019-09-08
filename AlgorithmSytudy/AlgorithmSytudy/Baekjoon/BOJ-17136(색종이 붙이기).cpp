#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

/*
BOJ(17136) 색종이 붙이기
2019.08.21
*/

const int INF = 987654321;

int board[11][11]; //종이
int temp[11][11]; //복사본
int sticker[6] = { 0,5,5,5,5,5 }; //색종이종류
int answer = INF; //정답

vector<Pair>v; //1 저장벡터


//특정위치에 색종이를 붙일 수 있는지 여부반환
bool check(int idx1, int idx2, int type)
{
	bool ret = true;

	for (int i = idx1; i <= idx1 + type - 1; i++)
	{
		for (int j = idx2; j <= idx2 + type - 1; j++)
		{
			//칸의 경계를 넘어갈 때
			if (i < 1 || i>10 || j < 1 || j>10)
			{
				ret = false;
				return ret;
			}
			//문제조건확인 
			else if (!sticker[type] || board[i][j] == -1 || board[i][j] == 0)
			{
				ret = false;
				return ret;
			}
		}
	}
	return ret;
}

//색종이 붙이는함수
void cover(int idx1, int idx2, int type)
{
	for (int i = idx1; i <= idx1 + type - 1; i++)
		for (int j = idx2; j <= idx2 + type - 1; j++)
			board[i][j] = -1;

	sticker[type]--;
}

//색종이 떼는함수
void uncover(int idx1, int idx2, int type)
{
	for (int i = idx1; i <= idx1 + type - 1; i++)
		for (int j = idx2; j <= idx2 + type - 1; j++)
			board[i][j] = temp[i][j];

	sticker[type]++;
}


//완전탐색(백트래킹)함수 , sticker_cnt = 색종이 붙인횟수, cover_cnt 덮여진칸의 개수
void dfs(int sticker_cnt, int cover_cnt)
{
	//덮여진 칸의개수가 1의개수와 같으면(전부 다 덮이면) 함수종료 
	// 현재의 답보다 작으면 변경(최소 색종이개수)
	if (cover_cnt == v.size())
	{
		answer = min(answer, sticker_cnt);
		return;
	}

	// 사용된 색종이가 현재 답보다 크면 종료(가지치기)
	if (sticker_cnt >= answer)
		return;
	
	// 모든 1인칸을 탐색
	for (int i = 0; i < v.size(); i++)
	{
		int idx1 = v[i].first;
		int idx2 = v[i].second;

		// 이미 색종이가 덮여잇으면 
		if (board[idx1][idx2] == -1)
			continue;

		//색종이가 안덮인 칸에 모든 색종이를 붙여본다
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