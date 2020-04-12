#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int test;
	cin >> test;

	for (int t = 1; t <= test; t++)
	{
		int k;
		cin >> k;
		multiset<int>multiSet;

		for (int i = 1; i <= k; i++)
		{
			char order;
			int n;

			cin >> order >> n;

			if (order == 'I')
			{
				multiSet.insert(n);
			}
			else
			{
				if (multiSet.size() == 0) continue;

				if (n == 1)
				{
					multiSet.erase(--multiSet.end());
				}
				else
				{
					multiSet.erase(multiSet.begin());
				}
			}
		}
		if (multiSet.size() == 0) {
			printf("EMPTY\n");
		}
		else {
			auto first = multiSet.begin();
			auto last = --multiSet.end();
			printf("%d %d\n", *last, *first);
		}
	}
	return 0;
}