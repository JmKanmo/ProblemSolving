#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 100001;

struct Heap
{
private:
	int arr[MAX_SIZE];
	int index;

public:
	Heap() {}

	bool isEmpty() { return index == 0 ? true : false; }

	void swap(int parent, int child)
	{
		int temp = arr[parent];
		arr[parent] = arr[child];
		arr[child] = temp;
	}

	void push(const int data)
	{
		arr[++index] = data;

		int child = index;
		int parent = child / 2;

		while (child > 1)
		{
			if (abs(arr[child]) == abs(arr[parent]) && arr[child] < arr[parent])
			{
				swap(parent, child);
			}
			else if (abs(arr[child]) < abs(arr[parent]))
			{
				swap(parent, child);
			}
			else {
				break;
			}
			child = parent;
			parent = child / 2;
		}
	}

	int pop()
	{
		if (isEmpty())
			return 0;

		int ret = arr[1];
		swap(1, index--);

		int parent = 1;
		int child = parent * 2;

		while (true)
		{
			if (child + 1 <= index)
			{
				if (abs(arr[child]) == abs(arr[child + 1]))
				{
					if (arr[child] > arr[child + 1]) child += 1;
				}
				else {
					child = abs(arr[child]) < abs(arr[child + 1])? child:child + 1;
				}

				if (abs(arr[parent]) == abs(arr[child]))
				{
					if (arr[parent] < arr[child])
						break;
					else
						swap(parent, child);
				}
				else {
					if (abs(arr[parent]) < abs(arr[child]))
						break;
					swap(parent, child);
				}
			}
			else if (child <= index)
			{
				if (abs(arr[parent]) == abs(arr[child]))
				{
					if (arr[parent] < arr[child])
						break;
					swap(parent, child);
				}
				else {
					if (abs(arr[parent]) < abs(arr[child]))
						break;
					swap(parent, child);
				}
			}
			else {
				break;
			}
			parent = child;
			child *= 2;
		}
		return ret;
	}
};

Heap heap;

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int input;
		scanf("%d", &input);
		if (input == 0) printf("%d\n", heap.pop());
		else heap.push(input);
	}
	
	return 0;
}