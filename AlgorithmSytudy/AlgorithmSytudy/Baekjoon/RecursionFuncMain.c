#include <stdio.h>
#include "Fibonacci.h"
#include "HanoiTower.h"

int main(void)
{
	printf(" [ 피보나치수열 구현&실습 ]\n\n");
	Fibonacci(0,1);
	puts("\n\n");
	printf(" [ 하노이탑 옮기기 구현&실습 ]\n\n");
	MoveHanoiTower('A', 'B', 'C');
	puts("\n");

}//End of main()
