#include <stdio.h>
#include "ListQueue.h"

int main(void)
{
	Queue q;

	InitQ(&q);

	EnQueue(&q, 25); EnQueue(&q, 10);
	EnQueue(&q, 100); EnQueue(&q, 250);
	EnQueue(&q, 450); EnQueue(&q, 500);
	EnQueue(&q, 700); EnQueue(&q, 850);
	EnQueue(&q, 1000); EnQueue(&q, 1200);

	printf("%d ", DeQueue(&q)); printf("%d\n", DeQueue(&q));

	EnQueue(&q, -55); EnQueue(&q, 10000);
	EnQueue(&q, 0);

	printf("%d ", DeQueue(&q)); printf("%d\n", DeQueue(&q));

	EnQueue(&q, 77);

	puts("\n");

	while (1)
		printf("%d\n", DeQueue(&q));

	return 0;


}