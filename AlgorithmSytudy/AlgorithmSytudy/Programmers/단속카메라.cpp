#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int>v1, vector<int>v2) {
	return v1[1] < v2[1] ? true : false;
}

int solution(vector<vector<int>> routes) {
	int answer = 0;
	sort(routes.begin(), routes.end(), comp);

	int camera = routes[0][1];
	answer += 1;

	for (int i = 1; i < routes.size(); i++)
	{
		if (camera < routes[i][0]) {
			answer++;
			camera = routes[i][1];
		}
	}

	return answer;
}

int main(void)
{
	solution({ {-20,15},{-14,-5},{-18,-13},{-5,-3} });

	return 0;
}