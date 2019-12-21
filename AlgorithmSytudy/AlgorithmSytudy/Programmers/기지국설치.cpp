#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int prev_pos = 1;

	if (stations.size() == 1)
	{
		int left_scope = (stations[0] - w) - 1;
		int right_scope = n - (stations[0] + w);

		int len = (w * 2) + 1;

		if (left_scope > 0)
		{
			if (left_scope < len) {
				answer++;
			}
			else {
				if (left_scope % len != 0) {
					answer += (left_scope / len);
					answer++;
				}
				else {
					answer += (left_scope / len);
				}
			}
		}
		if (right_scope > 0)
		{
			if (right_scope < len) {
				answer++;
			}
			else {
				if (right_scope % len != 0) {
					answer += (right_scope / len);
					answer++;
				}
				else {
					answer += (right_scope / len);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < stations.size(); i++)
		{
			int left_scope = (stations[i] - w) - prev_pos;
			int len = (2 * w) + 1;

			if (left_scope > 0)
			{
				if (left_scope < len) {
					answer++;
				}
				else {
					if (left_scope % len != 0) {
						answer += (left_scope / len);
						answer++;
					}
					else {
						answer += (left_scope / len);
					}
				}
			}
			prev_pos = (stations[i] + w) + 1;

			if (i == stations.size() - 1)
			{
				int right_scope = n - prev_pos + 1;

				if (right_scope > 0)
				{
					if (right_scope < len) {
						answer++;
					}
					else {
						if (right_scope % len != 0) {
							answer += (right_scope / len);
							answer++;
						}
						else {
							answer += (right_scope / len);
						}
					}
				}
			}
		}
	}
	return answer;
}


int main()
{
	solution(11, {1}, 1);

	return 0;
}