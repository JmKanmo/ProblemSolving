#include <stdio.h>
#include "BinarySearchTree.h"

int GetSelect(void);
void ShowData(DataKey, BSTData);

int main(void)
{
	printf("[ 이진탐색트리 구현&실습 ]\n\n");

	BSTree bst;
	BSTreeInit(&bst, ShowData);

	while (1)
	{
		switch (GetSelect())
		{
		case 0:
			return -1;

		case 1:
		{
			DataKey key;
			char data[20];

			printf("\n키:");
			scanf("%c", &key);
			getchar();

			printf("데이터:");
			scanf("%s", data);
			getchar();
			
			if ((key >= 'A'&&key <= 'z') && data)
				BSTreeInsert(&bst, key, data);
			else
				printf("\n잘못된입력\n");
			break;
		}

		case 2:
		{
			DataKey key;
			BSTData data;

			printf("\n탐색할 키값:");
			scanf("%c", &key);
			getchar();

			if (!(data = BSTreeSearch(&bst, key)))
				printf("\n탐색실패\n");
			else
				printf("\n데이터:%s\n", data);
			break;
		}

	   case 3:
	   {
		   DataKey key;
		   BSTData data;
		   
		   printf("\n삭제할 키값:");
		   scanf("%c", &key);
		   getchar();

		   if (!(data = BSTreeDelete(&bst, key)))
			   printf("\n삭제실패\n");
		   else
			   printf("\n데이터:%s\n", data);
		   break;
	   }

	   case 4:
		   BSTreeTraversal(&bst);
		   putchar('\n');
		   break;

	   default:
		   printf("\n잘못된 입력\n");
	  }//switch
	putchar('\n');
   }//while(i)
	return 0;
}//End of main()

int GetSelect(void)
{
	int sel;

	printf("선택: [0]퇴장 [1]삽입 [2]탐색 [3]삭제 [4]순회\n\n");
	printf("선택:");
	scanf("%d", &sel);
	getchar();
	return sel;
}//End of sel()

void ShowData(DataKey key, BSTData data)
{
	static int count = 1;

	if (count++ % 4 == 0)
		puts("\n");
      
	printf("%c[%s] ", key, data);
}//End of BSTShow()

