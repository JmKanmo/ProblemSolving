#include <ctype.h>
#include "CalPostFix.h"
#include "ArrayStack.h"

int CalPostFixExp(char exp[])
{
	int i;
	Init_AS();

	for (i = 0;i < strlen(exp);i++)
	{
		if (isdigit(exp[i]))
		{
			Push_AS(exp[i] - 48);
		}
		else
		{
			int PopN1 = Pop_AS();
			int PopN2 = Pop_AS();
			
			switch (exp[i])
			{
			case '+':
				Push_AS(PopN2+PopN1);
				break;
			case '-':
				Push_AS(PopN2 - PopN1);
				break;
			case '*':
				Push_AS(PopN2*PopN1);
				break;
			case '/':
				Push_AS(PopN2 / PopN1);
				break;
			}//switch
		}//if-else
	}//for(i)
	return Pop_AS();
}//End of CalPostFixExp()