#define _CRT_SECURE_NO_WARNINGS 1
#include"ListStrack.h"
int main()
{
	      ListStack st;
		  ListStackInit(&st);
		  ListStackPush(&st, 1);
		  ListStackPush(&st, 2);
		  ListStackPush(&st, 3);
		  ListStackPop(&st);
		 ListStackShow(st);
		 
		  system("pause");
		  return 0;
}