#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	while (progresses.empty() != true)
	{
		for (int i = 0; i < progresses.size(); i++)
			progresses[i] = progresses[i] + speeds[i];

		int cnt = 0;

		while (progresses.empty() != true)
		{
			if (progresses[0] >= 100)
			{
				progresses.erase(progresses.begin());
				speeds.erase(speeds.begin());
				cnt++;
			}
			else {
				break;
			}
		}
		if (cnt > 0) answer.push_back(cnt);
	}

	return answer;
}