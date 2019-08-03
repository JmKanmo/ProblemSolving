#ifndef __ARRAY_LIST__
#define __ARRAY_LIST__
#define TRUE 1
#define FALSE 0
#define LIST_LEN 100
#include "Point.h"

//�������ڷ��� typedef����
typedef Point* LData;

//�迭����Ʈ ����ü����
typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int dataNum;
	int curPos;
}ArrayList;

//����Ʈ�ڷ��� typedef����
typedef ArrayList List;

void Init_List(List*pList);//����Ʈ�ʱ�ȭ
void Insert_List(List*pList, LData data);//����Ʈ �����ͻ���
int ref_LFirst(List*pList, LData*pData);//����Ʈ ù��°����������
int ref_LNext(List*pList, LData*pData);//����Ʈ ��������������
LData L_Remove(List*pList);//����Ʈ ���絥���ͻ���
int L_Count(List*pList);//����Ʈ�����ͼ� ��ȸ

#endif