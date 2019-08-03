#include <ctype.h>
#include "CalPostfixExp.h"
#include "ListStack.h"

int CalPostfixExp(char exp[])
{
	Stack stack;
	Init_S(&stack);

	for (int i = 0;i < strlen(exp);i++)
	{
		char ch = exp[i];

		if (isdigit(ch))
		{
			Push_S(&stack, ch - 48);
		}
		else
		{
			int op1 = Pop_S(&stack);
			int op2 = Pop_S(&stack);

			switch (ch)
			{
			case '+':
				Push_S(&stack, op2 + op1);
				break;
			case '-':
				Push_S(&stack, op2 - op1);
				break;
			case '*':
				Push_S(&stack, op2 * op1);
				break;
			case '/':
				Push_S(&stack, op2 / op1);
			}//swtich
		}//if-else
	}//for(i)

	return Pop_S(&stack);
}//End of CalPostfixExp()