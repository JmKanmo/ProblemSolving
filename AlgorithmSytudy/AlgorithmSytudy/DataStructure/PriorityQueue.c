#include "PriorityQueue.h"

void PQueueInit(PQueue*pq, CompPriority cp)
{
	Heap_Init(&pq->heap,cp);
}//End of PQueueInit()

int PQ_IsEmpty(PQueue*pq)
{
	return H_IsEmpty(&pq->heap);
}//End of PQ_IsEmpty()

void PEnqueue(PQueue*pq, PQData data)
{
	H_Insert(&pq->heap, data);
}//End of PQ_Insert()

PQData PDequeue(PQueue*pq)
{
	return H_Delete(&pq->heap);
}//End of PQ_Delete()
