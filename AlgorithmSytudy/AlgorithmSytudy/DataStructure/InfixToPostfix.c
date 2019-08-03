#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "InfixToPostfix.h"
#include "ListStack.h"

int getNumOfPriority(char op)
{
	switch (op)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return 0;
	}//switch()
}//End of getNumOfPriority()

int CompPriority(char op1, char op2)
{
	return (op1 = getNumOfPriority(op1)) >= (op2 = getNumOfPriority(op2)) ? 1 : 0;

}//End of CompPriority()

void ConvToPostFix(char exp[])
{
	int expLen = strlen(exp);
	char*cpExp = (char*)malloc(sizeof(char)*(expLen)+1);
	int cpCount;
	int i;
	Init_LS();

	memset(cpExp, 0, expLen + 1);

	for (i = 0, cpCount = 0;i < expLen;i++)
	{
		if (isdigit(exp[i]))
		{
			cpExp[cpCount++] = exp[i];
		}
		else
		{
			switch (exp[i])
			{
			case '(':
				Push_LS(exp[i]);
				break;
			case ')':
				while (1)
				{
					if (Peek_LS() == '(')
					{
						Pop_LS();
						break;
					}
					else
					{
						cpExp[cpCount++] = Pop_LS();
					}
				}//while(i)
				break;
			case '+':case '-':
			case '*':case '/':
				while (!IsEmpty_LS() && CompPriority(Peek_LS(), exp[i]))
				{
					cpExp[cpCount++] = Pop_LS();
				}//while(i)
				Push_LS(exp[i]);
				break;
			}//switch()
		}//if-else
	}//for(i)

	while (!IsEmpty_LS())
	{
		cpExp[cpCount++] = Pop_LS();
	}//while(i)

	strcpy(exp, cpExp);
	free(cpExp);
}//End of ConvToPostFix()
