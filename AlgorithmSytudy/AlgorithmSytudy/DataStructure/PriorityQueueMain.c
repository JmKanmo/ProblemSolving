#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PriorityQueue.h"

int CompNodePriority(HData, HData);

int main(void)
{
	printf("[ �켱����ť ����&�ǽ� ]\n\n");
 
	PQueue pq;

	PQueueInit(&pq,CompNodePriority);

	PEnqueue(&pq,"����"); PEnqueue(&pq,"ȣ����");
	PEnqueue(&pq,"�Ǿ�"); PEnqueue(&pq,"���ȿ�����");
	PEnqueue(&pq,"���̿���"); PEnqueue(&pq,"����Ʈ����������");
	PEnqueue(&pq, "��"); PEnqueue(&pq, "��Ծ�");

	printf("%s����\n", PDequeue(&pq));


	PEnqueue(&pq, "���ظ�");
	PEnqueue(&pq, "����");
	PEnqueue(&pq, "����");

	puts("\n");

	while (!PQ_IsEmpty(&pq))
		printf("%s����\n\n", PDequeue(&pq));

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


