#include <stdio.h>
#include "Fibonacci.h"
#include "HanoiTower.h"

int main(void)
{
	printf(" [ �Ǻ���ġ���� ����&�ǽ� ]\n\n");
	Fibonacci(0,1);
	puts("\n\n");
	printf(" [ �ϳ���ž �ű�� ����&�ǽ� ]\n\n");
	MoveHanoiTower('A', 'B', 'C');
	puts("\n");

}//End of main()
