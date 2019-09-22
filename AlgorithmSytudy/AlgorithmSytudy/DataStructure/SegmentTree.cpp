#include <iostream>
#include <vector>

using namespace std;

/*
	세그먼트트리(구간합)구현
	by YOLO
*/

vector<int>arr;
vector<int>s_tree;
int SIZE;

/*
	세그먼트트리 초기화함수
	각 원소에 특정구간합 저장
*/
int init(int left, int right, int node)
{
	if (left >= right)
		return s_tree[node] = arr[left];

	int mid = (left + right) / 2;

	return s_tree[node] = init(left, mid, node * 2) + init(mid + 1, right, node * 2 + 1);
}

/*
	세그먼트트리 구간합 반환함수
	인자로 주어진 구간의 합을 반환
*/
int sum(int st_left, int st_right, int start, int end, int node)
{
	//구간을 벗어날 때
	if (st_right < start || end < st_left)
		return 0;

	//탐색범위가 원하는 구간에 포함될때 
	if (start <= st_left && st_right <= end)
		return s_tree[node];

	int mid = (st_left + st_right) / 2;

	return sum(st_left, mid, start, end, node * 2) + sum(mid + 1, st_right, start, end, node * 2 + 1);
}

// 특정원소[idx]의 값을 diff만큼 수정할 때, 세그먼트트리 갱신함수
void update(int left, int right, int node, int idx, int diff)
{
	// idx를 넘어난 범위에서는 갱신X 
	if (right < idx || idx < left)
		return;

	s_tree[node] += diff;

	if (left >= right)
		return;

	int mid = (left + right) / 2;

	update(left, mid, node * 2, idx, diff);
	update(mid + 1, right, node * 2 + 1, idx, diff);
}

int main()
{
	printf("배열의 크기:");
	scanf("%d", &SIZE);

	arr = vector<int>(SIZE);
	s_tree = vector<int>(SIZE * 4);

	for (int i = 0; i < SIZE; i++) scanf("%d", &arr[i]);

	init(0, SIZE - 1, 1);

	printf("구간합을 구하기위한 시작인덱스와 끝 인덱스 입력:");

	int start_idx, end_idx;
	scanf("%d %d", &start_idx, &end_idx);
	
	printf("구간합:%d\n", sum(0, SIZE - 1, start_idx, end_idx, 1));

	/*
		arr[3] = arr[3] + 6

		3 5 2 4 8 -> 3 5 2 10 8
	*/
	update(0, SIZE - 1, 1, 3, 6); 
	
	printf("구간합:%d\n", sum(0, SIZE - 1, start_idx, end_idx, 1));

	return 0;
}