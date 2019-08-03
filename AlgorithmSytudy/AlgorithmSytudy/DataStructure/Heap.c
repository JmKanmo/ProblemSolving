#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

int CompPriorityFunc(HData data1, HData data2)
{
	HData Subtract = data1 - data2;

	if (Subtract <= 0)
		return TRUE;
	else
		return FALSE;
}//End of CompPriority()

////Passive function

int GetParentIndex(int idx) { return idx / 2; }
int GetLeftChildIndex(int idx) { return idx * 2; }
int GetRightChildIndex(int idx) { return idx * 2 + 1; }

int GetHighPriorityIndex(Heap*heap, int idx)
{
	if (GetLeftChildIndex(idx) > heap->NumOfData)
		return FALSE;

	else if (GetLeftChildIndex(idx) == heap->NumOfData)
		return GetLeftChildIndex(idx);

	else
		return heap->cp(heap->arr[GetLeftChildIndex(idx)], heap->arr[GetRightChildIndex(idx)]) ? GetLeftChildIndex(idx) : GetRightChildIndex(idx);
}//End of GetHighPriorityIndex()

///ÈüÀÚ·á±¸Á¶ ADT

void HeapInit(Heap*heap, CompPriority cp)
{
	heap->NumOfData = 0;
	heap->cp = cp;
}//End of HeapInit()

int HIsEmpty(Heap*heap)
{
	return heap->NumOfData == 0 ? TRUE : FALSE;
}//End of HIsEmpty()

void HInsert(Heap*heap, HData data)
{
	if (heap->NumOfData == HEAP_SIZE)
	{
		printf("ÈüÀÌ ²ËÃ¡½À´Ï´Ù.\n");
		exit(1);
	}

	int insIndex = heap->NumOfData + 1;
  
	while (insIndex != 1)
	{
		if (heap->cp(heap->arr[GetParentIndex(insIndex)], data))
			break;

		heap->arr[insIndex] = heap->arr[GetParentIndex(insIndex)];
		insIndex = GetParentIndex(insIndex);
	}//while(i)

	heap->arr[insIndex] = data;
	heap->NumOfData++;
}//End of HInsert()

HData HDelete(Heap*heap)
{
	if (HIsEmpty(heap))
	{
		printf("ÈüÀÌ ºñ¾ú½À´Ï´Ù.\n");
		exit(1);
	}

	int idx = 1;
	int idx2 = idx;

	HData lastData = heap->arr[heap->NumOfData];
	HData delData = heap->arr[idx];

	while (1)
	{
		if (!(idx = GetHighPriorityIndex(heap, idx)))
			break;
		else
		{
			if (heap->cp(heap->arr[idx], lastData))
			{
				heap->arr[idx2] = heap->arr[idx];
				idx2 = idx;
			}
			else
				break;
		}
	}//while(i)
	
	heap->arr[idx2] = lastData;
	heap->NumOfData--;
	return delData;
}// End of HDelete()














