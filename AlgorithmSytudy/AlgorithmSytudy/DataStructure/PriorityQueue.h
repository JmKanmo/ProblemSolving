#ifndef __PRIORITYQUEUE__H
#define __PRIORITYQUEUE__H

#include "ArrayHeap.h"

typedef struct _PQueue
{
	Heap heap;
}PQueue;

typedef HData PQData;

void PQueueInit(PQueue*, CompPriority);
int PQ_IsEmpty(PQueue*);
void PEnqueue(PQueue*, PQData);
PQData PDequeue(PQueue*);

#endif