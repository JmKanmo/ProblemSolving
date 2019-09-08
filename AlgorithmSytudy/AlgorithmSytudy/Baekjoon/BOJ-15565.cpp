#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int arr[1000001];
int answer = 2e9;
int idx;
vector<int>pos;

void init()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] == 1) {
			pos.push_back(i);
			idx++;
		}
	}
}

void  solve(int start)
{
	answer = min(answer, pos[start + K - 1] - pos[start] + 1);
}

int main()
{
	init();
	for (int i = 0; i < idx-K+1; i++) solve(i);
	if (answer == 2e9) printf("-1\n");
	else printf("%d\n", answer);
	return 0;
}