#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	//�迭����Ʈ ����&�ʱ�ȭ
	List list;
	Init_List(&list);
	
	//�迭����Ʈ�����ͻ���
	Insert_List(&list, 25);
	Insert_List(&list, 35);
	Insert_List(&list, 55);
	Insert_List(&list, 100);
	Insert_List(&list, 135);
	Insert_List(&list, 155);
	Insert_List(&list, 185);
	Insert_List(&list, 200);

	//�����ͼ�ȸ(���)
	int pData;
	int i;

	for (i = 0;i < L_Count(&list);i++)
	{
		if (i == 0)
		{
			ref_LFirst(&list, &pData);
		}
		else
		{
			ref_LNext(&list, &pData);
		}
		printf("%d��° ������:%d\n", i + 1, pData);
	}//for(i)

	printf("\n100����ū �����ͻ���");
	//�����ͻ���(100���� Ŭ���)
	for (i = 0;i < L_Count(&list);i++)
	{
		if (i == 0)
		{
			ref_LFirst(&list, &pData);
		}
		else
		{
			ref_LNext(&list, &pData);
		}
		if (pData > 100)
		{
			L_Remove(&list);
			i--;
		}
	}//for(i)

	puts("\n");
	printf("������ ������\n\n");

	 //�����ͼ�ȸ(���)
	for (i = 0;i < L_Count(&list);i++)
	{
		if (i == 0)
		{
			ref_LFirst(&list, &pData);
		}
		else
		{
			ref_LNext(&list, &pData);
		}
		printf("%d��° ������:%d\n", i + 1, pData);
	}//for(i)

	return 0;
}