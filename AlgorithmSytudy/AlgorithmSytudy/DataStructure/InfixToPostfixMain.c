#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InfixToPostfix.h"
#include "CalPostFix.h"

int main(void)
{
	char*ExpArr[3];
	int arrlen = sizeof(ExpArr) / sizeof(char*);
	int i;

	for (i = 0;i < arrlen;i++) {
		ExpArr[i] = (char*)malloc(sizeof(char)*20);	
		memset(ExpArr[i], 0, 20);
		switch (i)
		{
		case 0:
			strcpy(ExpArr[i], "1+2*3");
			break;
		case 1:
			strcpy(ExpArr[i], "(1+2)*3");
			break;
		case 2:
			strcpy(ExpArr[i], "((1-2)+3)*(5-2)");
			break;
		}//switch
		ConvToPostFix(ExpArr[i]);
		printf("%s   계산결과:%d\n", ExpArr[i], CalPostFixExp(ExpArr[i]));

	}//for(i)
	
	for (i = 0;i < arrlen;i++) {
		free(ExpArr[i]);
	}//for(i)
	return 0;
}//End of main()