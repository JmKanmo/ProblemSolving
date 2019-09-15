#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define MAX(a,b) a>b?a:b

using namespace std;

typedef pair<int, int> Pair;

int main()
{
	int N;
	long long counter = 0;
	map<int, int> hash_map; //first - node¹øÈ£, second - depth

	scanf("%d", &N);
	hash_map.insert(Pair(0, -1));
	hash_map.insert(Pair(N + 1, -1));

	for (int i = 0; i < N; i++)
	{
		int node;
		scanf("%d", &node);
		hash_map.insert(Pair(node, -1));
		auto pre_node = hash_map.find(node);
		auto post_node = pre_node;
		pre_node--;
		post_node++;
		hash_map[node] = MAX(pre_node->second, post_node->second);
		hash_map[node]++;
		counter += hash_map[node];
		printf("%lld\n", counter);
	}

	return 0;
}