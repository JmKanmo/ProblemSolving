#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <vector>

using namespace std;

/*
2018.11.06
구간트리실습
두부
*/

//세그먼트트리 클래스
class Segment_Tree
{
public:
	vector<int>max_range; //구간최댓값 저장배열
	vector<int>min_range; //구간최솟값 저장배열
	int len;

	Segment_Tree(vector<int>&array)
	{
		len = array.size();
		max_range.resize(len * 4);
		min_range.resize(len * 4);
		Init_Min(array, 0, len - 1, 1);
		Init_Max(array, 0, len - 1, 1);
	}//Segment_Tree()

	//구간최솟값배열 초기화(세그먼트 트리생성)
	int Init_Min(vector<int>&arr, int left, int right, int node)
	{
		if (left == right)
			return min_range[node] = arr[left];


		int mid = (left + right) / 2;
		int leftMin = Init_Min(arr, left, mid, node * 2);
		int rightMin = Init_Min(arr, mid + 1, right, node * 2 + 1);

		return min_range[node] = min(leftMin, rightMin);
	}//Init_Min()

	//구간 최댓값배열 초기화(세그먼트 트리생성) 
	int Init_Max(vector<int>&arr, int left, int right, int node)
	{
		if (left == right)
			return max_range[node] = arr[left];


		int mid = (left + right) / 2;
		int leftMax = Init_Max(arr, left, mid, node * 2);
		int rightMax = Init_Max(arr, mid + 1, right, node * 2 + 1);

		return max_range[node] = max(leftMax, rightMax);
	}//Init_Max()

	//구간최솟값 질의함수
	int Query_Min(int left, int right, int nodeLeft, int nodeRight, int node)
	{
		if (left > nodeRight || right < nodeLeft)
			return INT_MAX;

		else if (left <= nodeLeft && right >= nodeRight)
			return min_range[node];

		int mid = (nodeLeft + nodeRight) / 2;
		return min(Query_Min(left, right,nodeLeft, mid, node * 2), Query_Min(left, right, mid + 1, nodeRight, node * 2 + 1));
	}//Query_Min()

	//구간최댓값 질의함수
	int Query_Max(int left, int right, int nodeLeft, int nodeRight, int node)
	{
		if (left > nodeRight || right < nodeLeft)
			return -INT_MAX;

		else if (left <= nodeLeft && right >= nodeRight)
			return max_range[node];

		int mid = (nodeLeft + nodeRight) / 2;
		return max(Query_Max(left, right, nodeLeft, mid, node * 2), Query_Max(left, right, mid + 1, nodeRight, node * 2 + 1));
	}//Query_Max()
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int>array(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &array[i]);

	Segment_Tree st(array);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d %d\n", st.Query_Min(a - 1, b - 1, 0, n - 1, 1), st.Query_Max(a - 1, b - 1, 0, n - 1, 1));
	}//for()

  	return 0;
}//main()