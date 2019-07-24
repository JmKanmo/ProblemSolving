#include <stdio.h>
#include "CircularQueue.h"

int getMenu(void);

int main(void)
{
	printf("[Array based circular Queue data structure practice]\n\n");

	Queue CQ;

	printf("[ Initialize clear ]\n\n");
	QueueInit(&CQ);

	int data;
	while (1)
	{
		switch (getMenu())
		{
		case 1:
			printf("Input Data:");
			scanf("%d", &data);
			getchar();
			EnQueue(&CQ, data);
			break;
		case 2:
			printf("\nData: %d\n\n",DeQueue(&CQ));
			break;
		case 3:
			printf("\nPeek Data:%d\n\n", QPeek(&CQ));
			break;
		case 4:
			return -1;
			break;
		default:
			printf("\n[ Wrong Input ]\n\n");
		}//switch()
	}//while(i)
	return 0;
}//End of main()

int getMenu(void)
{
	int sel;
	printf("\n[1]insert [2]delete [3]peek [4]exit\n\n");
	printf("Input:");
	scanf("%d", &sel);
	getchar();
	putchar('\n');
	return sel;
}//End of getMenu()