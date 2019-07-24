#include <stdio.h>
#include "LDeque.h"

int sel;
int selMenu(void);

int main(void)
{
	printf("\t[ ���ڷᱸ�� �ǽ� ]\n\n");

	Deque dq;
	DequeInit(&dq);
	printf("\t�� ����&�ʱ�ȭ\n");

	int data;

	while (1)
	{
		switch (selMenu())
		{
		case 1:
			printf("\n\t����[1] / ������[2]\n");
			printf("\t����:");
			scanf("%d", &sel);
			getchar();
			if (sel == 1)
			{
				printf("\n\t�������Է�:");
				scanf("%d", &data);
				DQAddFirst(&dq, data);
			}
			else if (sel == 2)
			{
				printf("\n\t�������Է�:");
				scanf("%d", &data);
				DQAddLast(&dq, data);
			}
			else
			{
				printf("\n\t�߸����Է�\n");
			}
			break;
		case 2:
			printf("\n\t����[1] / ������[2]\n");
			printf("\t����:");
			scanf("%d", &sel);
			getchar();
			if (sel == 1) printf("\n\t[ %d ]����\n", DQRemoveFirst(&dq));
			else if (sel == 2) printf("\n\t[ %d ]����\n", DQRemoveLast(&dq));
			else printf("\n\t�߸����Է�\n");
			break;
		case 3:
			printf("\n\t����[1] / ������[2]\n");
			printf("\t����:");
			scanf("%d", &sel);
			getchar();
			if (sel == 1) printf("\n\t[ %d ]\n", DQPeekFirst(&dq));
			else if (sel == 2) printf("\n\t[ %d ]\n", DQPeekLast(&dq));
			else printf("\n\t�߸����Է�\n");
			break;
		case 4:
			while (1)
			  DQRemoveFirst(&dq);
		default:
			printf("\n\t�߸����Է�\n");
		}//swtich
	}//while(i)
	return 0;
}//End of main()

int selMenu(void)
{
	printf("\n\n\t[1]�����ͻ��� [2]�����ͻ��� [3]�����Ͳ����� [4]����\n\n");
	printf("\t����:");
	scanf("%d", &sel);
	getchar();
	return sel;
}//End of selMenu()
