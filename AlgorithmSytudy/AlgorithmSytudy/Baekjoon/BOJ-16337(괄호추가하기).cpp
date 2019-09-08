#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

char arr[21];
int N;
LL answer = -2e9;

void init()
{
	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++)
	{
		scanf("%c", &arr[i]);
		if (i % 2 == 0) arr[i] -= 48;
	}
}

LL calc(LL left_Num, char op, LL right_Num)
{
	switch (op)
	{
	case '+': return left_Num + right_Num;
	case '-': return left_Num - right_Num;
	case '*': return left_Num * right_Num;
	}
}

void dfs(LL num, int idx)
{
	if (idx == N - 1)
	{
		answer = max(answer, num);
		return;
	}

	if (idx + 2 <= N - 1) dfs(calc(num, arr[idx + 1], arr[idx + 2]), idx + 2);
	if (idx + 4 <= N - 1) dfs(calc(num, arr[idx + 1], calc(arr[idx + 2], arr[idx + 3], arr[idx + 4])), idx + 4);
}

int main()
{
	init();
	
	if (N == 1)
	{
		printf("%d\n", arr[0]);
		return 0;
	}

	dfs(arr[0], 0);
	dfs(calc(arr[0], arr[1], arr[2]), 2);
	printf("%lld\n", answer);
	return 0;
}