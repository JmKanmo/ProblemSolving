#ifndef __HEAP__H
#define __HEAP__H

#define TRUE 1	
#define FALSE 0

#define HEAP_SIZE 100

typedef int HData;

typedef int CompPriority(HData, HData);

typedef struct ArrayHeap
{
	int NumOfData;
	HData arr[HEAP_SIZE];
	CompPriority*cp;
}ArrayHeap;

typedef ArrayHeap Heap;

int CompPriorityFunc(HData, HData);

void HeapInit(Heap*,CompPriority);
int HIsEmpty(Heap*);

void HInsert(Heap*, HData);
HData HDelete(Heap*);

#endif