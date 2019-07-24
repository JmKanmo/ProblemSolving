#include <cstdio>

/*
2018.11.08
¥ﬁ∆ÿ¿Ã(BOJ 1913)
µŒ∫Œ
*/

using namespace std;

enum { ONE = 1, TWO, THREE, FOUR };


int main()
{
	int N, n;
	int number = 1, step = 1;
	int pos1, pos2;
	int find1, find2;
	int**arr = NULL;
	bool flag = true;

	scanf("%d", &N);
	scanf("%d", &n);

	pos1 = (N - 1) / 2, pos2 = pos1;

	arr = new int*[N];
	for (int i = 0; i < N; i++) arr[i] = new int[N];

	arr[pos1][pos2] = number;

	while (flag)
	{
		for (int i = 1; i <= 4 && flag; i++)
		{
			switch (i)
			{
			case ONE:
				for (int j = 0; j < step; j++)
				{
					if (arr[pos1][pos2] == n)
					{
						find1 = pos1;
						find2 = pos2;
					}
					if (pos1 - 1 < 0)
						break;
					else if (number == N * N)
					{
						flag = false;
						break;
					}
					arr[--pos1][pos2] = ++number;
				}//for()		   
				break;
			case TWO:
				for (int j = 0; j < step; j++)
				{
					if (arr[pos1][pos2] == n)
					{
						find1 = pos1;
						find2 = pos2;
					}
					if (pos2 + 1 == N)
						break;
					else if (number == N * N)
					{
						flag = false;
						break;
					}
					arr[pos1][++pos2] = ++number;
				}//for()
				break;
			case THREE:
				for (int j = 0; j < step; j++)
				{
					if (arr[pos1][pos2] == n)
					{
						find1 = pos1;
						find2 = pos2;
					}
					if (pos1 + 1 == N)
						break;
					else if (number == N * N)
					{
						flag = false;
						break;
					}
					arr[++pos1][pos2] = ++number;
				}//for()
				break;
			case FOUR:
				for (int j = 0; j < step; j++)
				{
					if (arr[pos1][pos2] == n)
					{
						find1 = pos1;
						find2 = pos2;
					}
					if (pos2 - 1 < 0)
						break;
					else if (number == N * N)
					{
						flag = false;
						break;
					}
					arr[pos1][--pos2] = ++number;
				}//for()
				break;
			}//switch()
			if (i % 2 == 0) step++;
		}//for()
	}//while()

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}//for()
	printf("%d %d\n", find1 + 1, find2 + 1);
	for (int i = 0; i < N; i++) delete[] arr[i];
	delete[]arr;
	return 0;
}//main()
