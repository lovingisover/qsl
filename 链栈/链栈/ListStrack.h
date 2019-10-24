#ifndef _LISTSTRACK_H_
#define _LISTSTRACK_H_
#include"common.h"
typedef struct StackNode
{
	DataType data;
	struct StackNode *next;
}StackNode;

typedef StackNode* ListStack;

void ListStackInit(ListStack *pst);
void ListStackPush(ListStack *pst, DataType x);
void ListStackShow(ListStack pst);
void ListStackPop(ListStack *pst);

void ListStackInit(ListStack *pst)
{
	*pst = NULL;
}
void ListStackPush(ListStack *pst, DataType x)
{
	StackNode *node = (StackNode*)malloc(sizeof(StackNode));
	assert(node != NULL);
	node->data = x;
	node->next = *pst;
	*pst = node;
}
void ListStackShow(ListStack pst)
{
	StackNode *p = pst;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}
void ListStackPop(ListStack *pst)
{
	StackNode *p = *pst;
	*pst = p->next;
	free(p);
}









#endif