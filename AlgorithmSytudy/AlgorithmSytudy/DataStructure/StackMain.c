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
		printf("�������Է�:");
		scanf("%d", &data);
		Push(&st, data);
		printf("%d Ǫ��\n\n",Peek(&st));
		getchar();
	}//for(i)

	putchar('\n');

	while (!IsEmptyStack(&st))
		printf("%d pop\n", Pop(&st));

	return 0;
}//End of main()