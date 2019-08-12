#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//��Ʈ(1)�� ������ ����
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

//��Ʈ(1)�� ������ ū ������ ����
bool comp(const int& bitset1, const int& bitset2) { return getCntOfBit(bitset1) > getCntOfBit(bitset2); }

//���ϼ� üũ�Լ� ( true ��ȯ - ���ϼ� ������ ���)
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
	int answer = 0; //����
	int row_size = relation.size(); //���� ũ��
	int col_size = relation.front().size(); //����ũ��
	vector<int>candidates; // ���ϼ��� �����ϴ� �ĺ�Ű��

	//��Ʈ������ ���� �ĺ�Ű����� ������ ���ϰ� �� ������ ���ϼ����� ������ ���Ѵ� 
	for (int bitset = 1; bitset < (1 << col_size); bitset++)
	{
		if (uniqueCheck(relation, row_size, col_size, bitset))
			candidates.push_back(bitset);
	}

	// �ĺ�Ű��� ����(��������)
	sort(candidates.begin(), candidates.end(), comp);

	//�ּҼ��˻� & ���䱸�ϱ�
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
