#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListStack.h"
#include "ConvInfixToPostfix.h"

int GetExpPriority(char exp)
{
	switch (exp)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return -1;
	}//switch
}//End of GetExpPriority()

int CompExpPriority(char exp1, char exp2)
{
	return GetExpPriority(exp1) >= GetExpPriority(exp2) ? TRUE : FALSE;
}//End of CompExpPrior

void ConvExpInfixToPostfix(char exp[])
{
	int expLen = strlen(exp);
	int convExpCount = 0;
	int i;
	char ch;

	char*convExp = (char*)malloc(sizeof(char)*expLen + 1);
	Stack stack;

	Init_S(&stack);

	for (i = 0;i < expLen;i++)
	{
		ch = exp[i];

			if (isdigit(ch))
			{
				convExp[convExpCount++] = ch;
			}
			else
			{
				switch (ch)
				{
				case '(':
					Push_S(&stack, ch);
					break;

				case ')':
					while (TRUE)
					{
						char pData = Pop_S(&stack);

						if (pData == '(')
							break;
						
						else
							convExp[convExpCount++] = pData;
					}//while(i)
					break;

				default:
					while (!IsEmpty_S(&stack) && CompExpPriority(Peek_S(&stack), ch))
						convExp[convExpCount++] = Pop_S(&stack);

					Push_S(&stack, ch);
				}//switch()
			}//if-else
	}//for(i)
	
	while (!IsEmpty_S(&stack))
		convExp[convExpCount++] = Pop_S(&stack);

	convExp[convExpCount++] = NULL;
	strcpy(exp, convExp);
	free(convExp);
}//End of ConvExpInfixToPostfix()