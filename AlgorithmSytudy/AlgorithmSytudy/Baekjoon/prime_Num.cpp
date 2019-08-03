#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;

/*
2018.11.19
소수구하기(BOJ 1929)
두부
*/

int main()
{
	int M, N;
	bool *pArr;

	scanf("%d %d", &M, &N);

	pArr = new bool[N + 1];

	fill(pArr, pArr + N + 1, true);
	pArr[1] = false;

	for (int i = 2; i <= sqrt(N); i++)
	{
		for (int j = i + i; j <= N; j += i)
		{
			if (pArr[j])
				pArr[j] = !pArr[j];
		}//for()
	}//for()

	for (int i = M; i <= N; i++)
	{
		if (pArr[i])
			printf("%d\n", i);
	}

	delete[]pArr;
	return 0;
}//main()