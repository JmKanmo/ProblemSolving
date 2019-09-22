#include <iostream>
#include <vector>

using namespace std;

/*
	���׸�ƮƮ��(������)����
	by YOLO
*/

vector<int>arr;
vector<int>s_tree;
int SIZE;

/*
	���׸�ƮƮ�� �ʱ�ȭ�Լ�
	�� ���ҿ� Ư�������� ����
*/
int init(int left, int right, int node)
{
	if (left >= right)
		return s_tree[node] = arr[left];

	int mid = (left + right) / 2;

	return s_tree[node] = init(left, mid, node * 2) + init(mid + 1, right, node * 2 + 1);
}

/*
	���׸�ƮƮ�� ������ ��ȯ�Լ�
	���ڷ� �־��� ������ ���� ��ȯ
*/
int sum(int st_left, int st_right, int start, int end, int node)
{
	//������ ��� ��
	if (st_right < start || end < st_left)
		return 0;

	//Ž�������� ���ϴ� ������ ���Եɶ� 
	if (start <= st_left && st_right <= end)
		return s_tree[node];

	int mid = (st_left + st_right) / 2;

	return sum(st_left, mid, start, end, node * 2) + sum(mid + 1, st_right, start, end, node * 2 + 1);
}

// Ư������[idx]�� ���� diff��ŭ ������ ��, ���׸�ƮƮ�� �����Լ�
void update(int left, int right, int node, int idx, int diff)
{
	// idx�� �Ѿ ���������� ����X 
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
	printf("�迭�� ũ��:");
	scanf("%d", &SIZE);

	arr = vector<int>(SIZE);
	s_tree = vector<int>(SIZE * 4);

	for (int i = 0; i < SIZE; i++) scanf("%d", &arr[i]);

	init(0, SIZE - 1, 1);

	printf("�������� ���ϱ����� �����ε����� �� �ε��� �Է�:");

	int start_idx, end_idx;
	scanf("%d %d", &start_idx, &end_idx);
	
	printf("������:%d\n", sum(0, SIZE - 1, start_idx, end_idx, 1));

	/*
		arr[3] = arr[3] + 6

		3 5 2 4 8 -> 3 5 2 10 8
	*/
	update(0, SIZE - 1, 1, 3, 6); 
	
	printf("������:%d\n", sum(0, SIZE - 1, start_idx, end_idx, 1));

	return 0;
}