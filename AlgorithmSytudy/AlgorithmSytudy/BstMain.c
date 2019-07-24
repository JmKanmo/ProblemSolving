#include <stdio.h>
#include "BinarySearchTree.h"

int GetSelect(void);
void ShowData(DataKey, BSTData);

int main(void)
{
	printf("[ ����Ž��Ʈ�� ����&�ǽ� ]\n\n");

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

			printf("\nŰ:");
			scanf("%c", &key);
			getchar();

			printf("������:");
			scanf("%s", data);
			getchar();
			
			if ((key >= 'A'&&key <= 'z') && data)
				BSTreeInsert(&bst, key, data);
			else
				printf("\n�߸����Է�\n");
			break;
		}

		case 2:
		{
			DataKey key;
			BSTData data;

			printf("\nŽ���� Ű��:");
			scanf("%c", &key);
			getchar();

			if (!(data = BSTreeSearch(&bst, key)))
				printf("\nŽ������\n");
			else
				printf("\n������:%s\n", data);
			break;
		}

	   case 3:
	   {
		   DataKey key;
		   BSTData data;
		   
		   printf("\n������ Ű��:");
		   scanf("%c", &key);
		   getchar();

		   if (!(data = BSTreeDelete(&bst, key)))
			   printf("\n��������\n");
		   else
			   printf("\n������:%s\n", data);
		   break;
	   }

	   case 4:
		   BSTreeTraversal(&bst);
		   putchar('\n');
		   break;

	   default:
		   printf("\n�߸��� �Է�\n");
	  }//switch
	putchar('\n');
   }//while(i)
	return 0;
}//End of main()

int GetSelect(void)
{
	int sel;

	printf("����: [0]���� [1]���� [2]Ž�� [3]���� [4]��ȸ\n\n");
	printf("����:");
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

