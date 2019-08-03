#include <stdio.h>
#include "ArrayList.h"

void Init_List(List*pList)
{
	pList->curPos = -1;//���絥���Ͱ� �ϳ��� ����
	pList->dataNum = 0;//���絥���Ͱ����� 0��
}//End of Init_List()

void Insert_List(List*pList, LData data)
{
	//����Ʈ�����ʰ�����Ȯ��
	if (pList->dataNum >= LIST_LEN)
	{
		printf("����뷮�ʰ�\n");
		return;
	}
	pList->arr[pList->dataNum++] = data;//����Ʈ�� �������߰�
}//End of Insert_List()

int ref_LFirst(List*pList, LData*pData)
{
	//�����Ͱ� �ϳ��� �������
	if (pList->dataNum == 0) 
	{
		printf("�����ҵ����Ͱ�����\n");
		return FALSE;
	}
	//ù��°����������(���� - FALSE��ȯ)
	*pData = pList->arr[(pList->curPos = 0)];
	return TRUE;
}//End of ref_LFirst()

int ref_LNext(List*pList, LData*pData)
{
	//������ ���������Ͱ� �������
	if (pList->curPos + 1 >= pList->dataNum)
	{
		printf("�����ҵ����Ͱ�����\n");
		return FALSE;
    }
	//��������������(���� - TRUE��ȯ)
	*pData = pList->arr[++pList->curPos];
	return TRUE;
}//End of ref_LNext()

LData L_Remove(List*pList)
{
	//������ ������ġ����������
	LData rData = pList->arr[pList->curPos];

	//������ �����͸� �������� ��ĭ�� �����͸� �ű�
	for (int i = pList->curPos, j = i + 1;j < pList->dataNum;i++, j++)
	{
		pList->arr[i] = pList->arr[j];
	}//for(i)
	//������ġ,�����Ͱ��� ����
	pList->curPos--;
	pList->dataNum--;
	return rData;
}//End of L_Remove()

int L_Count(List*pList)
{
	//���� �����Ͱ��� ��ȯ
	return pList->dataNum;
}//End of L_Count()

