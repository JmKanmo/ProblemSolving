#include <stdio.h>
#include <stdlib.h>
#include "ArrayHeap.h"

void Heap_Init(Heap*heap,CompPriority fp)
{
	heap->DataNum = 0;
	heap->Comp_Fp = fp;

}//End of Heap_Init()

int H_IsEmpty(Heap*heap)
{
	return heap->DataNum == 0 ? TRUE : FALSE;
}//End of H_IsEmpty()

int Get_Parent_Idx(int idx)
{
	return idx / 2;
}//End of Get_Parent_Idx()

int Get_LeftChild_Idx(int idx)
{
	return idx * 2;
}//End of Get_LeftChild_Idx()

int Get_RightChild_Idx(int idx)
{
	return (idx * 2) + 1;
}

int Get_HighPriority_idx(Heap*heap, int idx)
{
	if (Get_LeftChild_Idx(idx) > heap->DataNum)
		return FALSE;

	else if (Get_LeftChild_Idx(idx) == heap->DataNum)
		return Get_LeftChild_Idx(idx);

	else
	{
		if (heap->Comp_Fp(heap->arr[Get_LeftChild_Idx(idx)], heap->arr[Get_RightChild_Idx(idx)]))
			return Get_LeftChild_Idx(idx);
		else
			return Get_RightChild_Idx(idx);
	}
}//End of Get_HighPriority_idx()

void H_Insert(Heap*heap, HData data)
{
	int bottom = heap->DataNum + 1;

	if (bottom == HEAP_SIZE)
	{
		printf("ÈüÀÌ ²ËÃ¡½À´Ï´Ù.\n");
		exit(1);
	}

	while (bottom != 1)
	{
		if (heap->Comp_Fp(heap->arr[Get_Parent_Idx(bottom)], data))
		{
			break;
		}
		else
		{
			heap->arr[bottom] = heap->arr[Get_Parent_Idx(bottom)];
			bottom = Get_Parent_Idx(bottom);
		}
	}//while(i)

	heap->arr[bottom] = data;
	heap->DataNum++;
}//End of H_Insert()

HData H_Delete(Heap*heap)
{
	if (H_IsEmpty(heap))
	{
		printf("ÈüÀÌ ºñ¾ú½À´Ï´Ù.\n");
		exit(1);
	}

	int top = 1;
	int temp;
	HData delData = heap->arr[top];
	HData bottomData = heap->arr[heap->DataNum];
     
	while (1)
	{
		temp = top;
		top = Get_HighPriority_idx(heap, top);

		if (top == 0)
			break;

		if (heap->Comp_Fp(heap->arr[top], bottomData))
			heap->arr[temp] = heap->arr[top];
		else
			break;
	}//while(1)

	heap->arr[temp] = bottomData;
	heap->DataNum--;
	return delData;
}//End of H_Delete()









