#include <stdio.h>
#include "HanoiTower.h"

int moveStart = FALSE;

char*disk[3][3] = { { "큰원반","중간원반","작은원반" },{ 0 },{ 0 } };

int diskA[3] = { 1,1,1 };
int diskB[3] = { 0,0,0 };
int diskC[3] = { 0,0,0 };

int diskLenA = 2;
int diskLenB = 0;
int diskLenC = 0;

int CountA = 0;
int CountB = 0;
int CountN = 0;

int* diskPtr1;
int* diskPtr2;
int* lenPtr1;
int* lenPtr2;

int delNumA, delNumB;

void setPtrLen(char top1, char top2)
{
	if (top1 == 'A')
	{
		delNumA = 0;
		diskPtr1 = diskA;
		lenPtr1 = &diskLenA;
	}
	else if (top1 == 'B')
	{
		delNumA = 1;
		diskPtr1 = diskB;
		lenPtr1 = &diskLenB;
	}
	else if (top1 == 'C')
	{
		delNumA = 2;
		diskPtr1 = diskC;
		lenPtr1 = &diskLenC;
	}
	if (top2 == 'A')
	{
		delNumB = 0;
		diskPtr2 = diskA;
		lenPtr2 = &diskLenA;
	}
	else if (top2 == 'B')
	{
		delNumB = 1;
		diskPtr2 = diskB;
		lenPtr2 = &diskLenB;
	}
	else if (top2 == 'C')
	{
		delNumB = 2;
		diskPtr2 = diskC;
		lenPtr2 = &diskLenC;
	}
}//End of setPtrLen()

void MoveHanoiTower(char top1, char top2, char top3)
{
	if (diskC[2] != 0)
	{
		return;
	}

	setPtrLen(top1, top2);

	if (moveStart && diskLenA <= 2)
	{
		if ((!(CountA > 1) && !(diskA[0] == 0 && diskC[0] != 0 && diskC[1] == 0 && diskC[2] == 0))
			|| (CountA == 0 && (diskA[0] == 0 && diskC[0] != 0 && diskC[1] == 0 && diskC[2] == 0)))
		{
			if (disk[delNumA][*lenPtr1] == NULL)
			{
				disk[delNumB][*lenPtr2] = disk[delNumA][*lenPtr1 - 1];
				printf(" %c 에서 %c로 %s을 옮깁니다.\n", top1, top2, disk[delNumA][*lenPtr1 - 1]);
				disk[delNumA][*lenPtr1 - 1] = NULL;
			}
			else {
				disk[delNumB][*lenPtr2] = disk[delNumA][*lenPtr1];
				printf(" %c 에서 %c로 %s을 옮깁니다.\n", top1, top2, disk[delNumA][*lenPtr1]);
				disk[delNumA][*lenPtr1] = NULL;
			}
			if (diskPtr1[*lenPtr1] == 0)
			{
				diskPtr1[*lenPtr1 - 1]--;
			}
			else
			{
				if (diskPtr1[*lenPtr1] > 0)
					diskPtr1[*lenPtr1]--;
			}
			if (diskPtr2[*lenPtr2] < 2) diskPtr2[*lenPtr2]++;
			if ((*lenPtr1) - 1 >= 0) (*lenPtr1)--;
			if ((*lenPtr2) + 1 <= 2) (*lenPtr2)++;
		}
	}
	if (CountA < 2 &&
		((CountB < 1 && diskA[0] != 0 && diskC[0] != 0 && diskB[0] != 0)
			|| (diskA[0] != 0 && diskB[0] != 0 && diskC[0] == 0)
			|| (CountN < 1 && (diskA[0] == 0 && diskB[0] != 0 && diskC[0] != 0))
			|| (diskA[0] != 0 && diskB[0] == 0 && diskC[1] != 0))
		&& !(CountA > 1 && (diskA[0] == 0 && diskB[1] != 0 && diskC[0] != 0)))
	{
		CountA++;

		if (diskA[0] != 0 && diskC[0] != 0 && diskB[0] != 0) CountB++;
		if (diskA[0] == 0 && diskB[0] != 0 && diskC[0] != 0) CountN++;

		if (!(diskA[0] == 0 && diskB[0] != 0 && diskC[1] != 0))
		{
			MoveHanoiTower(top3, top2, top1);
		}
		else
		{
			if (CountA < 1)
			{
				MoveHanoiTower(top3, top2, top1);
			}
		}
	}
	else
	{
		if (!moveStart) moveStart = TRUE;
		CountA = 0;
		MoveHanoiTower(top1, top3, top2);
	}
}//End of MoveHanoiTower()