#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//비트(1)의 개수를 구함
int getCntOfBit(int bitset)
{
	int cnt = 0;

	while (bitset != 0)
	{
		if (bitset & 1) cnt++;
		bitset = bitset >> 1;
	}
	return cnt;
}

//비트(1)의 개수가 큰 순서로 정렬
bool comp(const int& bitset1, const int& bitset2) { return getCntOfBit(bitset1) > getCntOfBit(bitset2); }

//유일성 체크함수 ( true 반환 - 유일성 만족의 경우)
bool uniqueCheck(vector<vector<string>> relation, int row_size, int col_size, int bitSet)
{
	bool ret = true;

	for (int i = 0; i < row_size - 1; i++)
	{
		for (int j = i + 1; j < row_size; j++)
		{
			for (int k = 0; k < col_size; k++)
			{
				if (bitSet & 1 << k)
				{
					if (relation[i][k] != relation[j][k])
					{
						ret = false;
						break;
					}
				}
			}
			if (ret)
				return !ret;
			else
				ret = !ret;
		}
	}
	return ret;
}

int solution(vector<vector<string>> relation) {
	int answer = 0; //정답
	int row_size = relation.size(); //행의 크기
	int col_size = relation.front().size(); //열의크기
	vector<int>candidates; // 유일성을 만족하는 후보키셋

	//비트연산을 통해 후보키목록의 조합을 구하고 각 조합의 유일성만족 조합을 구한다 
	for (int bitset = 1; bitset < (1 << col_size); bitset++)
	{
		if (uniqueCheck(relation, row_size, col_size, bitset))
			candidates.push_back(bitset);
	}

	// 후보키목록 정렬(내림차순)
	sort(candidates.begin(), candidates.end(), comp);

	//최소성검사 & 정답구하기
	while (candidates.empty() != true)
	{
		int bitset = candidates.back();
		candidates.pop_back();
		answer++;

		for (int i = 0; i < candidates.size(); i++) {
			if ((bitset & candidates[i]) == bitset) {
				candidates.erase(candidates.begin() + i, candidates.begin() + i + 1);
				i--;
			}
		}
	}
	return answer;
}
