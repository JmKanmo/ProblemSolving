#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, double> Pair;

double stage[502];
double dp[502];
vector<Pair>failure(501);

void setStage(int N, vector<int>stages)
{
	for (int i = 0; i < stages.size(); i++)
		stage[stages[i]]++;

	for (int i = 2; i <= N; i++)
		dp[i] = dp[i - 1] + stage[i - 1];
}

vector<Pair> sort_desc(vector<Pair>failure, int N)
{
	//삽입정렬
	for (int i = 1; i <= N; i++) {
		for (int j = i; j > 1; j--) {
			if (failure[j].second > failure[j - 1].second) {
				Pair temp = failure[j];
				failure[j] = failure[j - 1];
				failure[j - 1] = temp;
			}
			else if (failure[j].second == failure[j - 1].second) {
				if (failure[j].first < failure[j - 1].first) {
					Pair temp = failure[j];
					failure[j] = failure[j - 1];
					failure[j - 1] = temp;
				}
			}
			else {

			}
		}
	}
	return failure;
}

vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;

	// 실패율을 구하는과정
	setStage(N, stages);

	for (int i = 1; i <= N; i++)
		failure[i] = Pair(i, stage[i] / (stages.size() - dp[i]));

	//실패율을 구한뒤 정렬진행
	failure = sort_desc(failure, N);

	//정렬된 실패율배열의 인덱스를 answer에 저장
	for (int i = 1; i <= N; i++)
		answer.push_back(failure[i].first);
	return answer;
}

int main()
{
	solution(5, { 2, 1, 2, 6, 2, 4, 3, 3 });



	return 0;
}