#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool comp(int a, int b) { return a > b ? true : false; }

int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	priority_queue<int>pq;

	for (int i = 0; i < A.size(); i++) pq.push(A[i]);

	sort(B.begin(), B.end(), comp);

	for (int i = 0; i < B.size(); i++)
	{
		while (pq.empty() != true)
		{
			if (pq.top() < B[i])
			{
				answer++;
				pq.pop();
				break;
			}
			else
			{
				pq.pop();
			}
		}
	}

	return answer;
}

int main()
{
	solution({ 5,1,3,7 }, { 2,2,6,8 });

	return 0;
}