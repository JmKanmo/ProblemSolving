#include "ArrayStack.h"

void Init_AS(void) { stack.top_Index = -1; }//End of Init()

int IsEmpty_AS(void) { return stack.top_Index == -1 ? TRUE : FALSE; }//End of Init()

void Push_AS(Data data) { stack.arr[++stack.top_Index] = data; }//End of Push()

Data Pop_AS(void) { return !IsEmpty_AS() ? stack.arr[stack.top_Index--] : FALSE; }//End of Pop()

Data Peek_AS(void) { return !IsEmpty_AS() ? stack.arr[stack.top_Index] : FALSE; }//End of Peek()