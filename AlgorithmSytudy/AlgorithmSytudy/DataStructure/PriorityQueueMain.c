#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PriorityQueue.h"

int CompNodePriority(HData, HData);

int main(void)
{
	printf("[ 우선순위큐 구현&실습 ]\n\n");
 
	PQueue pq;

	PQueueInit(&pq,CompNodePriority);

	PEnqueue(&pq,"사자"); PEnqueue(&pq,"호랑이");
	PEnqueue(&pq,"악어"); PEnqueue(&pq,"긴팔원숭이");
	PEnqueue(&pq,"하이에나"); PEnqueue(&pq,"오스트랄로피테쿠스");
	PEnqueue(&pq, "곰"); PEnqueue(&pq, "재규어");

	printf("%s삭제\n", PDequeue(&pq));


	PEnqueue(&pq, "강준모");
	PEnqueue(&pq, "늑대");
	PEnqueue(&pq, "여우");

	puts("\n");

	while (!PQ_IsEmpty(&pq))
		printf("%s삭제\n\n", PDequeue(&pq));

	return 0;
}//End of main()

int CompNodePriority(HData n1, HData n2)
{
	int subStr= strlen(n2) - strlen(n1);

	if (subStr >= 0)
		return TRUE;
	else
		return FALSE;
}//End of CompNodePriority()


