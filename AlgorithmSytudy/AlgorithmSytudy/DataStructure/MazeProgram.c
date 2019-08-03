#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

#define TRUE 1
#define FALSE 0

#define ARRIVE(x,y) (x == 9 && y == 1)
#define OVERPASS_WALL(x,y) ((x < 0 || y < 0) || (x > 9 || y > 9))

int visit[10][10] = { 0, }; //10x10크기의 미로방문여부 저장배열
int isArrive = FALSE;//도착여부저장 참/거짓 저장 변수

void gotoxy(const int, const int);//좌표이동 함수
void PrintMaze(char*[][10],const int,const int);//미로출력 함수
void FindMaze(char*[][10],const int,const int);//미로찾기 함수

int main(void)
{
	//10x10 크기의 미로배열
	char*maze[10][10] = {
	"☆","■","■","■","■","□","■","□","■","■"
   ,"□","□","□","■","■","□","■","□","■","□"
   ,"■","□","□","■","□","□","□","□","□","□"
   ,"□","□","□","□","□","■","□","□","■","■"
   ,"■","■","□","□","□","□","□","■","■","■"
   ,"□","□","□","□","□","■","□","□","■","■"
   ,"□","■","■","□","□","■","■","□","■","■"
   ,"□","□","□","□","■","■","□","□","■","■"
   ,"□","□","■","□","□","□","■","□","□","□"
   ,"■","★","□","■","□","□","□","□","■","■"
	};
	FindMaze(maze, 0, 0);//(0,0)지점을 출발지로 정하고 미로찾기함수호출
	return 0;
}//End of main()

//좌표이동함수 정의
void gotoxy(const int x, const int y) 
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//End of gotoxy()

//미로출력함수 정의
void PrintMaze(char*maze[][10],const int x,const int y)
{
	//중첩반복문을 이용해 10x10크기 미로를 좌표상에 출력한다.
	for (int i = 0;i < 10;i++) 
	{
		for (int j = 0;j < 10;j++)
		{
			//인자로 주어진 좌표(x,y)지점에 문자▩를 출력한다.
			if (i == x&&j == y)
				printf("%s", "▩");
			else
			printf("%s", maze[i][j]);
		}//for()
		printf("\n");
	}//for()
	//1초간 정지한 뒤 콘솔창을 지운다.
	Sleep(1000);
	system("cls");
}//End of PrintMaze()

//미로찾기함수 정의
void FindMaze(char*maze[][10], const int x, const int y)
{
	//난수생성을 위한 함수호출
	srand((unsigned int)time(NULL));

	//(x,y)지점 방문기록(TRUE 저장)
	visit[x][y] = TRUE;

	//현재 미로를 콘솔창에 출력
	PrintMaze(maze, x, y);

	//도착지점에 도달할 경우 도착여부변수에 TRUE 저장 후 함수종료
	if (ARRIVE(x,y)) 
	{
		isArrive = TRUE;
		return;
	}
	else {
		//랜덤변수 검사를 위한 크기4 배열선언
		int ranArr[4] = { 0, };

		//(좌,우,상,하)중, 어디로 이동할지 방향을 정하기위한 반복문 
		while(TRUE)
		{
			//1~4범위 난수생성 
			int ranNum = rand() % 4 + 1;
			//생성된 난수에서 1을 뺀값의 인덱스에 TRUE 저장 
			ranArr[ranNum - 1] = TRUE;
			//x,y값 변경방지위해 임시지역변수에 값을 복사
			int rX = x, rY = y;

			int sum = 0;
			//배열원소의 총합을 구함.
			//(1~4중 몇개의 값이 나왔는지 검사)  
			for (int i = 0;i < 4;i++)
				sum += ranArr[i];

			/*
			 랜덤변수값으로 방향키(좌,우,상,하)를 정한다.

			1 -> 좌 , 2 -> 우 
			3 -> 상 , 4 -> 하
			*/
			switch (ranNum)
			{
			case 1:
				rY--;
				break;
			case 2:
				rY++;
				break;
			case 3:
				rX--;
				break;
			case 4:
				rX++;
				break;
			}//switch

			/*
			랜덤변수값에 따라 이동한 좌표(x,y)가 미로의 크기를 넘을경우,
			continue문 실행하여, 방향키를 다시 설정(랜덤변수 재생성)
			*/
			if (OVERPASS_WALL(rX,rY)) 
			{
				/*
				만일,좌,우,상,하  전부 이동했음에도 방향을 못잡을경우,
				반복문을 탈출(break문 실행)
				*/
				if (sum >= 4)
					break;
				continue;
			}
			/*
			이동하려는 칸(좌표값)이 벽(■)이거나 방문한적이 있을경우,
			continue문 실행하여, 방향키를 다시설정(랜덤변수 재생성)
			*/
			else if (!strcmp(maze[rX][rY], "■") || visit[rX][rY]) 
			{
				/*
				만일,좌,우,상,하  전부 이동했음에도 방향을 못잡을경우,
				반복문을 탈출(break문 실행)
				*/
				if (sum >= 4)
					break;
				continue;
			}
			
			//이동하기에 적절한 칸을 찾을 경우, 재귀함수를 호출해 이동좌표값(rX,rY)를 인자로 넘긴다.  
			else
			 FindMaze(maze, rX, rY);

			//목적지에 도달했다면 "도착완료" 메시지를 출력한 뒤 break문을 실행시켜 반복문 탈출
			if (isArrive == TRUE)
			{
				//정적변수 cnt를 선언, 1증가시킨다.
				// cnt가 1보다 작거나 같으면 "도착완료" 메시지 출력(메시지중복출력을 방지하기위해 제어문사용)
				//break문을 실행시켜 while문을 탈출한다.(재귀함수 종료목적)
				static int cnt;
				if (++cnt <= 1)
					printf("★도착완료★\n\n");
				break;
			}
			/*적절한 이동칸을 못찾을경우, 후진할 때(재귀함수종료)
			미로출력함수를 호출해 미로를 찾아가는 과정을 보여줌.  
			*/
			PrintMaze(maze, x, y);
		}//while()
	}//if-else
}//End of FindMaze()


