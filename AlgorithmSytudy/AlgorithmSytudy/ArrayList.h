#ifndef __ARRAY_LIST__
#define __ARRAY_LIST__
#define TRUE 1
#define FALSE 0
#define LIST_LEN 100
#include "Point.h"

//데이터자료형 typedef정의
typedef Point* LData;

//배열리스트 구조체정의
typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int dataNum;
	int curPos;
}ArrayList;

//리스트자료형 typedef정의
typedef ArrayList List;

void Init_List(List*pList);//리스트초기화
void Insert_List(List*pList, LData data);//리스트 데이터삽입
int ref_LFirst(List*pList, LData*pData);//리스트 첫번째데이터참조
int ref_LNext(List*pList, LData*pData);//리스트 다음데이터참조
LData L_Remove(List*pList);//리스트 현재데이터삭제
int L_Count(List*pList);//리스트데이터수 조회

#endif