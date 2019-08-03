#include <stdio.h>
#include "Fibonacci.h"

void Fibonacci(int n1, int n2)
{
	int n3 = n1 + n2;

	if (n3 > 50) 
	{
		return;
	}

	if (n1 == 0)
	{
		printf(" %d ", n2);
	}
	else if (n2 < 2)
	{
		printf("%d %d ", n2, n3);
	}
	else
	{
		printf("%d ", n3);
	}

	Fibonacci(n2, n3);

}//End of Fibonacci()