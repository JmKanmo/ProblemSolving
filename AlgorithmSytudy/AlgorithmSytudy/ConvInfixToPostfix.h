#ifndef __CONVINFIXTOPOSTFIX__H
#define __CONVINFIXTOPOSTFIX__H

int GetExpPriority(char);
int CompExpPriority(char, char);
void ConvExpInfixToPostfix(char[]);

#endif