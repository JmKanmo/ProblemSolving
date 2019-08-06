#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int getScore(string dartResult)
{
	vector<int>score(3);
	int score_cnt = 0;

	for (int i = 0; i < dartResult.length(); i++)
	{
		if (isalpha(dartResult[i]))
		{
			if (dartResult[i] == 'S')
			{
				score[score_cnt - 1] = pow(score[score_cnt - 1], 1);
			}
			else if (dartResult[i] == 'D')
			{
				score[score_cnt - 1] = pow(score[score_cnt - 1], 2);
			}
			else
			{
				score[score_cnt - 1] = pow(score[score_cnt - 1], 3);
			}
		}
		else if (isdigit(dartResult[i]))
		{
			if (isdigit(dartResult[i + 1])) {
				score[score_cnt++] = 10;
				i += 1;
			}
			else {
				score[score_cnt++] = stoi(to_string(dartResult[i])) - 48;
			}
		}
		else {
			if (dartResult[i] == '*')
			{
				for (int i = score_cnt - 1, j = 0; j < 2; i--, j++)
				{
					score[i] *= 2;
				}
			}
			else
			{
				score[score_cnt - 1] *= -1;
			}
		}
	}

	return score[0] + score[1] + score[2];
}

int solution(string dartResult) {
	int answer = getScore(dartResult);
	return answer;
}