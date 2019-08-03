#include <stdio.h>
#include "LDeque.h"

int sel;
int selMenu(void);

int main(void)
{
	printf("\t[ 덱자료구조 실습 ]\n\n");

	Deque dq;
	DequeInit(&dq);
	printf("\t덱 생성&초기화\n");

	int data;

	while (1)
	{
		switch (selMenu())
		{
		case 1:
			printf("\n\t왼쪽[1] / 오른쪽[2]\n");
			printf("\t선택:");
			scanf("%d", &sel);
			getchar();
			if (sel == 1)
			{
				printf("\n\t데이터입력:");
				scanf("%d", &data);
				DQAddFirst(&dq, data);
			}
			else if (sel == 2)
			{
				printf("\n\t데이터입력:");
				scanf("%d", &data);
				DQAddLast(&dq, data);
			}
			else
			{
				printf("\n\t잘못된입력\n");
			}
			break;
		case 2:
			printf("\n\t왼쪽[1] / 오른쪽[2]\n");
			printf("\t선택:");
			scanf("%d", &sel);
			getchar();
			if (sel == 1) printf("\n\t[ %d ]삭제\n", DQRemoveFirst(&dq));
			else if (sel == 2) printf("\n\t[ %d ]삭제\n", DQRemoveLast(&dq));
			else printf("\n\t잘못된입력\n");
			break;
		case 3:
			printf("\n\t왼쪽[1] / 오른쪽[2]\n");
			printf("\t선택:");
			scanf("%d", &sel);
			getchar();
			if (sel == 1) printf("\n\t[ %d ]\n", DQPeekFirst(&dq));
			else if (sel == 2) printf("\n\t[ %d ]\n", DQPeekLast(&dq));
			else printf("\n\t잘못된입력\n");
			break;
		case 4:
			while (1)
			  DQRemoveFirst(&dq);
		default:
			printf("\n\t잘못된입력\n");
		}//swtich
	}//while(i)
	return 0;
}//End of main()

int selMenu(void)
{
	printf("\n\n\t[1]데이터삽입 [2]데이터삭제 [3]데이터꺼내기 [4]종료\n\n");
	printf("\t선택:");
	scanf("%d", &sel);
	getchar();
	return sel;
}//End of selMenu()
