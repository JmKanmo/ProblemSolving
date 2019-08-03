#include <stdio.h>
#include "Stack.h"

int main(void)
{
	Stack st;
	InitStack(&st);
	
	int data;
	int i;
	
	for (i = 0;i <5;i++)
	{
		printf("데이터입력:");
		scanf("%d", &data);
		Push(&st, data);
		printf("%d 푸쉬\n\n",Peek(&st));
		getchar();
	}//for(i)

	putchar('\n');

	while (!IsEmptyStack(&st))
		printf("%d pop\n", Pop(&st));

	return 0;
}//End of main()