#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	//배열리스트 선언&초기화
	List list;
	Init_List(&list);
	
	//배열리스트데이터삽입
	Insert_List(&list, 25);
	Insert_List(&list, 35);
	Insert_List(&list, 55);
	Insert_List(&list, 100);
	Insert_List(&list, 135);
	Insert_List(&list, 155);
	Insert_List(&list, 185);
	Insert_List(&list, 200);

	//데이터순회(출력)
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
		printf("%d번째 데이터:%d\n", i + 1, pData);
	}//for(i)

	printf("\n100보다큰 데이터삭제");
	//데이터삭제(100보다 클경우)
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
	printf("삭제후 데이터\n\n");

	 //데이터순회(출력)
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
		printf("%d번째 데이터:%d\n", i + 1, pData);
	}//for(i)

	return 0;
}