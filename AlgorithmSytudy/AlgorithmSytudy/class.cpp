#include <stdio.h>

int main()
{
	char arr[] = "Hello my name is kang jun mo";
	printf("πÆ¿Â:Hello my name is kang jun mo\n");
	int size = sizeof(arr) / sizeof(char);
	int voca_cnt = 0, space_cnt = 0, cnt = 0;

	while (cnt < size)
	{
		if (arr[cnt] == '\n')
		{
			cnt++;
			continue;
		}
		if (arr[cnt] != ' ') ++voca_cnt;
		else ++space_cnt;
		cnt++;
	}
	space_cnt++;
	voca_cnt--;
	printf("%d %d\n", voca_cnt, space_cnt);
	return 0;
}