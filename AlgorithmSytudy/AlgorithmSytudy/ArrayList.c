#include <stdio.h>
#include "ArrayList.h"

void Init_List(List*pList)
{
	pList->curPos = -1;//현재데이터가 하나도 없음
	pList->dataNum = 0;//현재데이터개수가 0개
}//End of Init_List()

void Insert_List(List*pList, LData data)
{
	//리스트범위초과여부확인
	if (pList->dataNum >= LIST_LEN)
	{
		printf("저장용량초과\n");
		return;
	}
	pList->arr[pList->dataNum++] = data;//리스트에 데이터추가
}//End of Insert_List()

int ref_LFirst(List*pList, LData*pData)
{
	//데이터가 하나도 없을경우
	if (pList->dataNum == 0) 
	{
		printf("참조할데이터가없음\n");
		return FALSE;
	}
	//첫번째데이터참조(실패 - FALSE반환)
	*pData = pList->arr[(pList->curPos = 0)];
	return TRUE;
}//End of ref_LFirst()

int ref_LNext(List*pList, LData*pData)
{
	//참조할 다음데이터가 없을경우
	if (pList->curPos + 1 >= pList->dataNum)
	{
		printf("참조할데이터가없음\n");
		return FALSE;
    }
	//다음데이터참조(성공 - TRUE반환)
	*pData = pList->arr[++pList->curPos];
	return TRUE;
}//End of ref_LNext()

LData L_Remove(List*pList)
{
	//삭제할 현재위치데이터저장
	LData rData = pList->arr[pList->curPos];

	//삭제할 데이터를 기점으로 한칸씩 데이터를 옮김
	for (int i = pList->curPos, j = i + 1;j < pList->dataNum;i++, j++)
	{
		pList->arr[i] = pList->arr[j];
	}//for(i)
	//현재위치,데이터개수 조정
	pList->curPos--;
	pList->dataNum--;
	return rData;
}//End of L_Remove()

int L_Count(List*pList)
{
	//현재 데이터개수 반환
	return pList->dataNum;
}//End of L_Count()

