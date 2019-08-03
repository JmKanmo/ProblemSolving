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

int visit[10][10] = { 0, }; //10x10ũ���� �̷ι湮���� ����迭
int isArrive = FALSE;//������������ ��/���� ���� ����

void gotoxy(const int, const int);//��ǥ�̵� �Լ�
void PrintMaze(char*[][10],const int,const int);//�̷���� �Լ�
void FindMaze(char*[][10],const int,const int);//�̷�ã�� �Լ�

int main(void)
{
	//10x10 ũ���� �̷ι迭
	char*maze[10][10] = {
	"��","��","��","��","��","��","��","��","��","��"
   ,"��","��","��","��","��","��","��","��","��","��"
   ,"��","��","��","��","��","��","��","��","��","��"
   ,"��","��","��","��","��","��","��","��","��","��"
   ,"��","��","��","��","��","��","��","��","��","��"
   ,"��","��","��","��","��","��","��","��","��","��"
   ,"��","��","��","��","��","��","��","��","��","��"
   ,"��","��","��","��","��","��","��","��","��","��"
   ,"��","��","��","��","��","��","��","��","��","��"
   ,"��","��","��","��","��","��","��","��","��","��"
	};
	FindMaze(maze, 0, 0);//(0,0)������ ������� ���ϰ� �̷�ã���Լ�ȣ��
	return 0;
}//End of main()

//��ǥ�̵��Լ� ����
void gotoxy(const int x, const int y) 
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//End of gotoxy()

//�̷�����Լ� ����
void PrintMaze(char*maze[][10],const int x,const int y)
{
	//��ø�ݺ����� �̿��� 10x10ũ�� �̷θ� ��ǥ�� ����Ѵ�.
	for (int i = 0;i < 10;i++) 
	{
		for (int j = 0;j < 10;j++)
		{
			//���ڷ� �־��� ��ǥ(x,y)������ ���ڢ̸� ����Ѵ�.
			if (i == x&&j == y)
				printf("%s", "��");
			else
			printf("%s", maze[i][j]);
		}//for()
		printf("\n");
	}//for()
	//1�ʰ� ������ �� �ܼ�â�� �����.
	Sleep(1000);
	system("cls");
}//End of PrintMaze()

//�̷�ã���Լ� ����
void FindMaze(char*maze[][10], const int x, const int y)
{
	//���������� ���� �Լ�ȣ��
	srand((unsigned int)time(NULL));

	//(x,y)���� �湮���(TRUE ����)
	visit[x][y] = TRUE;

	//���� �̷θ� �ܼ�â�� ���
	PrintMaze(maze, x, y);

	//���������� ������ ��� �������κ����� TRUE ���� �� �Լ�����
	if (ARRIVE(x,y)) 
	{
		isArrive = TRUE;
		return;
	}
	else {
		//�������� �˻縦 ���� ũ��4 �迭����
		int ranArr[4] = { 0, };

		//(��,��,��,��)��, ���� �̵����� ������ ���ϱ����� �ݺ��� 
		while(TRUE)
		{
			//1~4���� �������� 
			int ranNum = rand() % 4 + 1;
			//������ �������� 1�� ������ �ε����� TRUE ���� 
			ranArr[ranNum - 1] = TRUE;
			//x,y�� ����������� �ӽ����������� ���� ����
			int rX = x, rY = y;

			int sum = 0;
			//�迭������ ������ ����.
			//(1~4�� ��� ���� ���Դ��� �˻�)  
			for (int i = 0;i < 4;i++)
				sum += ranArr[i];

			/*
			 �������������� ����Ű(��,��,��,��)�� ���Ѵ�.

			1 -> �� , 2 -> �� 
			3 -> �� , 4 -> ��
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
			������������ ���� �̵��� ��ǥ(x,y)�� �̷��� ũ�⸦ �������,
			continue�� �����Ͽ�, ����Ű�� �ٽ� ����(�������� �����)
			*/
			if (OVERPASS_WALL(rX,rY)) 
			{
				/*
				����,��,��,��,��  ���� �̵��������� ������ ���������,
				�ݺ����� Ż��(break�� ����)
				*/
				if (sum >= 4)
					break;
				continue;
			}
			/*
			�̵��Ϸ��� ĭ(��ǥ��)�� ��(��)�̰ų� �湮������ �������,
			continue�� �����Ͽ�, ����Ű�� �ٽü���(�������� �����)
			*/
			else if (!strcmp(maze[rX][rY], "��") || visit[rX][rY]) 
			{
				/*
				����,��,��,��,��  ���� �̵��������� ������ ���������,
				�ݺ����� Ż��(break�� ����)
				*/
				if (sum >= 4)
					break;
				continue;
			}
			
			//�̵��ϱ⿡ ������ ĭ�� ã�� ���, ����Լ��� ȣ���� �̵���ǥ��(rX,rY)�� ���ڷ� �ѱ��.  
			else
			 FindMaze(maze, rX, rY);

			//�������� �����ߴٸ� "�����Ϸ�" �޽����� ����� �� break���� ������� �ݺ��� Ż��
			if (isArrive == TRUE)
			{
				//�������� cnt�� ����, 1������Ų��.
				// cnt�� 1���� �۰ų� ������ "�����Ϸ�" �޽��� ���(�޽����ߺ������ �����ϱ����� ������)
				//break���� ������� while���� Ż���Ѵ�.(����Լ� �������)
				static int cnt;
				if (++cnt <= 1)
					printf("�ڵ����Ϸ��\n\n");
				break;
			}
			/*������ �̵�ĭ�� ��ã�����, ������ ��(����Լ�����)
			�̷�����Լ��� ȣ���� �̷θ� ã�ư��� ������ ������.  
			*/
			PrintMaze(maze, x, y);
		}//while()
	}//if-else
}//End of FindMaze()


