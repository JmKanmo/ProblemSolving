#ifndef __ARRAYHEAP__H
#define __ARRAYHEAP__H

#define HEAP_SIZE 100

#define TRUE 1
#define FALSE 0

typedef char* HData;

typedef int CompPriority(HData, HData);

typedef struct _Heap
{
	int DataNum;
	HData arr[HEAP_SIZE];
	CompPriority*Comp_Fp;
}Heap;

void Heap_Init(Heap*, CompPriority);
int H_IsEmpty(Heap*);

void H_Insert(Heap*, HData);
HData H_Delete(Heap*);

#endif